#include "s21_decimal.h"

void init_decimal(s21_decimal *value) {
  for (int i = 0; i < BYTES_IN_DECIMAL; i++) {
    value->bits[i] = 0;
  }
  set_scale_decimal(value, 0);
  set_sign_decimal(value, 0);
}

int is_bit_set_decimal(s21_decimal *value, int index) {
  int index_in_bits = index / INT_BIT;
  int index_in_int = index % INT_BIT;
  int bit_mask = 1 << index_in_int;
  int result = (value->bits[index_in_bits] & bit_mask) ? 1 : 0;
  return result;
}

void set_bit_decimal(s21_decimal *value, int index) {
  int index_in_bits = index / INT_BIT;
  int index_in_int = index % INT_BIT;
  int bit_mask = 1 << index_in_int;
  value->bits[index_in_bits] = value->bits[index_in_bits] | bit_mask;
}

void unset_bit_decimal(s21_decimal *value, int index) {
  int index_in_bits = index / INT_BIT;
  int index_in_int = index % INT_BIT;
  int bit_mask = 1 << index_in_int;
  value->bits[index_in_bits] = value->bits[index_in_bits] & (~bit_mask);
}

void left_bit_shift_in_decimal(s21_decimal *value) {
  for (int i = BYTES_IN_DECIMAL - 2; i >= 0; i--) {
    value->bits[i] <<= 1;
    if (i > 0) {
      int highest_bit_in_right_int_index = (i - 1) * INT_BIT + INT_BIT - 1;
      if (is_bit_set_decimal(value, highest_bit_in_right_int_index)) {
        set_bit_decimal(value, highest_bit_in_right_int_index + 1);
      }
    }
  }
}

void right_bit_shift_in_decimal(s21_decimal *value) {
  for (int i = 0; i < BYTES_IN_DECIMAL - 1; i++) {
    value->bits[i] >>= 1;
    if (i < BYTES_IN_DECIMAL - 1) {
      int lowest_bit_in_left_int_index = i * INT_BIT + INT_BIT;
      if (is_bit_set_decimal(value, lowest_bit_in_left_int_index)) {
        set_bit_decimal(value, lowest_bit_in_left_int_index - 1);
      } else {
        unset_bit_decimal(value, lowest_bit_in_left_int_index - 1);
      }
    }
  }
}

int get_sign_decimal(s21_decimal value) {
  return (value.bits[3] & MINUS_MASK) >> 31;
}

int get_scale_decimal(s21_decimal value) {
  return (value.bits[3] >> 16) & 0x000000ff;
}

void set_scale_decimal(s21_decimal *value, uint32_t scale) {
  value->bits[3] = (scale << 16) & SCALE_MASK;
}

void set_sign_decimal(s21_decimal *value, uint32_t sign) {
  int sign_bit_index = BYTES_IN_DECIMAL * INT_BIT - 1;
  if (sign == 1) {
    set_bit_decimal(value, sign_bit_index);
  } else {
    unset_bit_decimal(value, sign_bit_index);
  }
}

int is_positive_decimal(s21_decimal value) { return !get_sign_decimal(value); }

int compare_float_as_string(float value_1, float value_2) {
  int err_code = 0;

  char value_1_str[56];
  sprintf(value_1_str, "%.7f", value_1);
  char *point_in_value_1 = strchr(value_1_str, '.');
  int cipher_count_before_point_value_1 = point_in_value_1 - value_1_str;

  char value_2_str[56];
  sprintf(value_2_str, "%.7f", value_2);
  char *point_in_value_2 = strchr(value_2_str, '.');
  int cipher_count_before_point_value_2 = point_in_value_2 - value_2_str;

  if (cipher_count_before_point_value_1 > cipher_count_before_point_value_2) {
    err_code = 1;
  } else if (cipher_count_before_point_value_1 ==
             cipher_count_before_point_value_2) {
    if (strcmp(value_1_str, value_2_str) >= 0) {
      err_code = 1;
    }
  }

  return err_code;
}

int check_float_range(float value) {
  int err_code = 0;
  if (value == S21_INF) {
    err_code = 1;
    return err_code;
  }
  float max = powf(2, 96) - 1;
  err_code = compare_float_as_string(value, max);
  if (err_code == 0) {
    err_code = compare_float_as_string(value, 0x1.fffffep+127f);
  }
  if (err_code == 0) {
    if (value > 0 && value < 1e-28) {
      err_code = 1;
    }
  }
  return err_code;
}

void corrector(int *mantisse, int *scale) {
  int dscale = 0;
  if (*scale > 28) {
    dscale = *scale - 28;
    int i = 0;
    while (i < dscale - 2) {
      *mantisse /= 10;
      (*scale)--;
      i++;
    }
  }
  int mantisse_copy = *mantisse;
  int ost = mantisse_copy % 10;
  int addition = 0;
  int coeff = 1;
  bool rounded = false;
  while (*scale > 28) {
    addition = 0;
    mantisse_copy /= 10;
    if (ost > 4) {
      mantisse_copy++;
      if (!rounded) rounded = true;
    }
    ost = mantisse_copy % 10;
    (*scale)--;
  }
  *mantisse = mantisse_copy;
  ost = mantisse_copy % 10;
  addition = 0;
  while (ost == 0 && *scale > 0 && !rounded) {
    addition = 0;
    if (ost > 4) {
      addition = 1;
    }
    mantisse_copy /= 10;
    coeff *= 10;
    ost = mantisse_copy % 10;
    (*scale)--;
  }
  *mantisse = *mantisse / coeff;
  if (addition) {
    (*mantisse)++;
  }
}

void scanf_float(float src, uint32_t *num, int *scale) {
  char src_str[56];
  sprintf(src_str, "%.6e", src);
  int part1 = 0;
  int part2 = 0;
  sscanf(src_str, "%d.%de%d", &part1, &part2, scale);
  if (part1 < 0) {
    part1 = -part1;
  }
  *num = part2;
  int i = 6;
  while (part2 > 0 || i > 0) {
    part1 *= 10;
    (*scale)--;
    part2 /= 10;
    i--;
  }
  *num += part1;
}

void convert_float_scale_eql_zero(int *scale, int num, s21_decimal *dst) {
  *scale = -(*scale);
  corrector(&num, scale);
  dst->bits[0] = num;
  set_scale_decimal(dst, *scale);
}

void convert_float_scale_positive(int *scale, int num, s21_decimal *dst) {
  float num_copy_f = num;
  int num_copy = num;
  int coeff = 1;
  while (*scale > 0) {
    if (num_copy_f * 10 > 2147483647.0) {
      break;
    }
    num_copy_f *= 10;
    coeff *= 10;
    (*scale)--;
  }
  num_copy = num * coeff;
  dst->bits[0] = num_copy;
  if (*scale > 0) {
    s21_bcd bcd = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0};
    init_bcd(&bcd);
    for (int i = 0; i < 4; i++) {
    }
    convert_from_decimal_to_bcd(dst, &bcd);
    while (*scale > 0) {
      int i = 4;
      while (i > 0) {
        left_bit_shift_in_bcd(&bcd);
        i--;
      }
      (*scale)--;
    }
    convert_from_bcd_to_decimal(&bcd, dst);
  }
  set_scale_decimal(dst, *scale);
}

// BCD type
void init_bcd(s21_bcd *value) {
  for (int i = 0; i < BYTES_IN_BCD; i++) {
    value->digits[i] = 0;
  }
  value->sign = 0;
  value->scale = 0;
}

int is_bit_set_bcd(s21_bcd *value, int index) {
  int index_in_bits = index / INT8_BIT;
  int index_in_int = index % INT8_BIT;
  int bit_mask = 1 << index_in_int;
  int result = (value->digits[index_in_bits] & bit_mask) ? 1 : 0;
  return result;
}

void set_bit_bcd(s21_bcd *value, int index) {
  int index_in_bits = index / INT8_BIT;
  int index_in_int = index % INT8_BIT;
  int bit_mask = 1 << index_in_int;
  value->digits[index_in_bits] = value->digits[index_in_bits] | bit_mask;
}

void unset_bit_bcd(s21_bcd *value, int index) {
  int index_in_bits = index / INT8_BIT;
  int index_in_int = index % INT8_BIT;
  int bit_mask = 1 << index_in_int;
  value->digits[index_in_bits] = value->digits[index_in_bits] & (~bit_mask);
}

void left_bit_shift_in_bcd(s21_bcd *value) {
  for (int i = BYTES_IN_BCD - 1; i >= 0; i--) {
    value->digits[i] <<= 1;
    if (i > 0) {
      int highest_bit_in_right_int_index = (i - 1) * INT8_BIT + INT8_BIT - 1;
      if (is_bit_set_bcd(value, highest_bit_in_right_int_index)) {
        set_bit_bcd(value, highest_bit_in_right_int_index + 1);
      }
    }
  }
}

void right_bit_shift_in_bcd(s21_bcd *value) {
  for (int i = 0; i < BYTES_IN_BCD - 1; i++) {
    value->digits[i] >>= 1;
    if (i < BYTES_IN_BCD - 1) {
      int lowest_bit_in_left_int_index = i * INT8_BIT + INT8_BIT;
      if (is_bit_set_bcd(value, lowest_bit_in_left_int_index)) {
        set_bit_bcd(value, lowest_bit_in_left_int_index - 1);
      } else {
        unset_bit_bcd(value, lowest_bit_in_left_int_index - 1);
      }
    }
  }
}

uint8_t get_scale_bcd(s21_bcd value) { return value.scale; }

void convert_from_decimal_to_bcd(s21_decimal *decimal, s21_bcd *bcd) {
  bcd->sign = (uint8_t)get_sign_decimal(*decimal);
  bcd->scale = (uint8_t)get_scale_decimal(*decimal);

  int bits_count_in_decimal = (BYTES_IN_DECIMAL - 1) * INT_BIT;

  for (int shift_counter = 0; shift_counter < bits_count_in_decimal;
       ++shift_counter) {
    for (int i = 0; i < BYTES_IN_BCD * 2; ++i) {
      if (i % 2) {
        if (((bcd->digits[i / 2] >> 4) & MASK_1111) >= BCD_PREOVERFLOW_VALUE) {
          bcd->digits[i / 2] += 48;
        }
      } else {
        if ((bcd->digits[i / 2] & MASK_1111) >= BCD_PREOVERFLOW_VALUE) {
          bcd->digits[i / 2] += BCD_OVERFLOW_CORRRECTOR;
        }
      }
    }

    left_bit_shift_in_bcd(bcd);

    if (is_bit_set_decimal(decimal, bits_count_in_decimal - 1)) {
      set_bit_bcd(bcd, 0);
    }
    left_bit_shift_in_decimal(decimal);
  }
}

void convert_from_bcd_to_decimal(s21_bcd *bcd, s21_decimal *decimal) {
  uint32_t sign = (uint32_t)bcd->sign;
  uint32_t scale = (uint32_t)get_scale_bcd(*bcd);
  int bits_count_in_decimal = (BYTES_IN_DECIMAL - 1) * INT_BIT;

  for (int shift_counter = 0; shift_counter < bits_count_in_decimal - 1;
       shift_counter++) {
    if (is_bit_set_bcd(bcd, 0)) {
      set_bit_decimal(decimal, bits_count_in_decimal - 1);
    }
    right_bit_shift_in_decimal(decimal);
    right_bit_shift_in_bcd(bcd);
    for (int i = 0; i < BYTES_IN_BCD * 2; ++i) {
      if (i % 2) {
        if (((bcd->digits[i / 2] >> 4) & MASK_1111) >= 8) {
          bcd->digits[i / 2] -= 48;
        }
      } else {
        if ((bcd->digits[i / 2] & MASK_1111) >= 8) {
          bcd->digits[i / 2] -= 3;
        }
      }
    }
  }
  if (is_bit_set_bcd(bcd, 0)) {
    set_bit_decimal(decimal, bits_count_in_decimal - 1);
  }
  set_scale_decimal(decimal, scale);
  set_sign_decimal(decimal, sign);
}