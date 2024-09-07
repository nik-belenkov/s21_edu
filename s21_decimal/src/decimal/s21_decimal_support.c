#include "s21_decimal.h"

void null_decimal(s21_decimal *value) {
  for (int i = 0; i < 4; i++) {
    value->bits[i] = 0;
  }
}

void null_big_decimal(s21_big_decimal *value) {
  for (int i = 0; i < 8; i++) {
    value->bits[i] = 0;
  }
}

unsigned int get_bit(s21_decimal *value, int bit) {
  unsigned int mask = 1;
  int num_int = 0;
  search_bit(bit, &mask, &num_int);
  return (value->bits[num_int] & mask) == 0 ? 0 : 1;
}

int set_bit(s21_decimal *value, int num, int bit) {
  unsigned int mask = 1;
  int error = 0, num_byte = 0;
  search_bit(num, &mask, &num_byte);

  if (bit == 0) {
    mask = ~mask;
    value->bits[num_byte] = value->bits[num_byte] & mask;
  } else {
    value->bits[num_byte] = value->bits[num_byte] | mask;
  }
  return error;
}

int get_bit_int(unsigned int value, int bit) {
  unsigned int mask = 1;
  return (value & mask << bit) == 0 ? 0 : 1;
}

int set_bit_int(unsigned int *bits, int num, int bit) {
  unsigned int mask = 1;
  int error = 0;
  mask = mask << num;

  if (bit == 0) {
    *bits = *bits & ~mask;
  } else {
    *bits = *bits | mask;
  }

  return error;
}

unsigned big_get_sign(s21_big_decimal value) {
  unsigned sing = value.bits[7] >> 31;
  return sing;
}

void set_sign(s21_decimal *value, int sign) { set_bit(value, 127, sign); }

unsigned int get_scale(s21_decimal value) {
  unsigned int scale = value.bits[3] & SCALE_MASK;
  return scale >> 16;
}

unsigned int big_get_scale(s21_big_decimal value) {
  unsigned int scale = value.bits[7] & SCALE_MASK;
  return scale >> 16;
}

int set_scale(s21_decimal *value, unsigned int scale) {
  int error = 0;
  if (scale > 28) {
    error = 1;
  }
  scale = scale << 16;
  value->bits[3] = value->bits[3] | scale;
  return error;
}

void big_set_scale(s21_big_decimal *value, unsigned int scale) {
  for (int shift = 16; shift <= 23; ++shift) {
    unsigned int mask = 0;
    mask = 1U << shift;

    if (scale > 0 && scale % 2 == 1) {
      value->bits[7] |= mask;
    } else {
      value->bits[7] &= ~mask;
    }

    scale /= 2;
  }
}

void big_set_scale_null(s21_big_decimal *value) { value->bits[7] = 0; }

unsigned int big_get_bit(s21_big_decimal value, int bit) {
  unsigned int mask = 1;
  int num_int = 0;
  big_search_bit(bit, &mask, &num_int);
  return (value.bits[num_int] & mask) == 0 ? 0 : 1;
}

int big_set_bit(s21_big_decimal *value, int num, int bit) {
  unsigned int mask = 1;
  int error = 0, num_byte = 0;
  big_search_bit(num, &mask, &num_byte);

  if (bit == 0) {
    mask = ~mask;
    value->bits[num_byte] = value->bits[num_byte] & mask;
  } else {
    value->bits[num_byte] = value->bits[num_byte] | mask;
  }

  return error;
}

void search_bit(int bit, unsigned int *mask, int *num_int) {
  if (bit < 32) {
    *num_int = 0;
    *mask = *mask << bit;
  } else if (32 <= bit && bit < 64) {
    *num_int = 1;
    *mask = *mask << (bit - 32);
  } else if (64 <= bit && bit < 96) {
    *num_int = 2;
    *mask = *mask << (bit - 64);
  } else if (96 <= bit && bit < 128) {
    *num_int = 3;
    *mask = *mask << (bit - 96);
  }
}

void big_search_bit(int bit, unsigned int *mask, int *num_int) {
  if (bit < 32) {
    *num_int = 0;
    *mask = *mask << bit;
  } else if (32 <= bit && bit < 64) {
    *num_int = 1;
    *mask = *mask << (bit - 32);
  } else if (64 <= bit && bit < 96) {
    *num_int = 2;
    *mask = *mask << (bit - 64);
  } else if (96 <= bit && bit < 128) {
    *num_int = 3;
    *mask = *mask << (bit - 96);
  } else if (128 <= bit && bit < 160) {
    *num_int = 4;
    *mask = *mask << (bit - 128);
  } else if (160 <= bit && bit < 192) {
    *num_int = 5;
    *mask = *mask << (bit - 160);
  } else if (192 <= bit && bit < 224) {
    *num_int = 6;
    *mask = *mask << (bit - 192);
  } else if (224 <= bit && bit < 256) {
    *num_int = 7;
    *mask = *mask << (bit - 224);
  }
}

void convert_to_big(s21_decimal value, s21_big_decimal *result) {
  null_big_decimal(result);
  result->bits[7] = value.bits[3];
  for (int i = 0; i < 3; i++) {
    result->bits[i] = value.bits[i];
  }
}

int big_round_banker(s21_big_decimal *result) {
  int scale = big_get_scale(*result);
  int sign = big_get_sign(*result);

  s21_big_decimal temp_ost, temp_null, ten;

  int error = 0;
  if (!scale) return error;

  null_big_decimal(&temp_ost);
  null_big_decimal(&temp_null);
  null_big_decimal(&ten);
  ten.bits[0] = 10;

  int is_greater = 0;
  int tale = 0;
  while (!is_greater && scale >= 0) {
    is_greater = 1;

    for (int i = 96; i < 224; i++) {
      if (big_get_bit(*result, i)) {
        is_greater = 0;
        break;
      }
    }
    if (big_is_greater(temp_ost, temp_null)) tale++;
    if (!is_greater) {
      temp_ost = big_mod(*result, ten, result);
      scale--;
    }

    if (scale > 28 && is_greater) {
      temp_ost = big_mod(*result, ten, result);
      scale--;
      is_greater = 0;
    }
  }

  if (!is_greater && scale == 0) {
    error = FAIL;
    return error;
  }

  s21_big_decimal five_mask = {{0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};
  s21_big_decimal one = {{0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};

  if (big_is_equal_bit(temp_ost, five_mask)) {
    if (big_get_bit(*result, 0) || tale > 1) {
      bitwise_add(*result, one, result);
    }
  } else if (big_is_greater(temp_ost, five_mask)) {
    bitwise_add(*result, one, result);
  }

  s21_big_decimal val = *result;

  while (!big_get_bit(*result, 0) && scale > 0) {
    s21_big_decimal tmp = big_mod(val, ten, &val);
    if (big_is_equal_bit(tmp, temp_null)) {
      scale--;
      for (int i = 0; i < 8; i++) {
        result->bits[i] = val.bits[i];
      }
    } else {
      break;
    }
  }

  big_set_scale(result, scale);

  big_set_bit(result, 255, sign);

  return error;
}

void bitwise_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  unsigned int rem = 0;

  for (int i = 0; i < 32 * 7; i++) {
    unsigned int bit_1 = big_get_bit(value_1, i),
                 bit_2 = big_get_bit(value_2, i), temp = 0;
    temp = bit_1 + bit_2 + rem;
    rem = get_bit_int(temp, 1);
    set_bit_int(&temp, 1, 0);
    big_set_bit(result, i, temp);
  }

  big_set_bit(result, 32 * 7, 0);
}

int big_bit_shift(s21_big_decimal *value, int shift) {
  int error = 0;
  unsigned int temp = 0;

  for (int i = 223; i > (223 - shift); i--) {
    if (big_get_bit(*value, i) == 1) {
      error = 1;
    }
  }

  if (error == 0) {
    for (int k = 223 - shift; k >= 0; k--) {
      temp = big_get_bit(*value, k);
      big_set_bit(value, k + shift, temp);
    }
    for (int i = 0; i < shift; i++) {
      big_set_bit(value, i, 0);
    }
  }
  return error;
}

s21_big_decimal big_shift(s21_big_decimal value, int shift) {
  big_bit_shift(&value, shift);
  return value;
}

int convert_from_big(s21_big_decimal value, s21_decimal *result) {
  null_decimal(result);

  int error = 0;

  if (((value.bits[3])) || (value.bits[4]) || (value.bits[5]) ||
      (value.bits[6])) {
    error = S21_BIG;
  } else {
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    result->bits[3] = value.bits[7];
  }

  if (error && big_get_bit(value, 255)) {
    error = S21_SMALL;
  }

  return error;
}

int big_normalize(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  unsigned int scale_1 = 0, scale_2 = 0;
  int scale = 0, error = 0;

  scale_1 = big_get_scale(*value_1);
  scale_2 = big_get_scale(*value_2);

  if (scale_1 == scale_2) return error;
  scale = scale_1 - scale_2;

  if (scale < 0 && scale_2 < 60) {
    scale = -scale;
    scale_1 += scale;
    for (int i = 0; i < scale; i++) {
      mul_10(value_1);
    }
    big_set_scale(value_1, scale_1);

  } else if (scale > 0 && scale_1 < 60) {
    scale_2 += scale;
    for (int i = 0; i < scale; i++) {
      mul_10(value_2);
    }
    big_set_scale(value_2, scale_2);
  }
  return error;
}

int normalize_by_scale(s21_decimal *value, int scale) {
  s21_decimal value_10 = {{10, 0, 0, 0}};

  int error = 0;
  while (scale > 0 && error == 0) {
    error = s21_mul(*value, value_10, value);
    scale--;
  }

  return error;
}

int mul_10(s21_big_decimal *value) {
  int overflow = 0;

  s21_big_decimal value_1;
  s21_big_decimal value_2;

  null_big_decimal(&value_1);
  null_big_decimal(&value_2);

  value_1 = *value;
  value_2 = *value;

  overflow += big_bit_shift(&value_1, 3);
  overflow += big_bit_shift(&value_2, 1);

  overflow += big_add(value_1, value_2, value);

  return overflow;
}

void big_invertation(s21_big_decimal *value) {
  s21_big_decimal one;
  null_big_decimal(&one);

  one.bits[0] = 1;
  for (int i = 0; i < 7; i++) {
    value->bits[i] = ~value->bits[i];
  }

  bitwise_add(*value, one, value);
}

int check_valid(s21_decimal value_1, s21_decimal value_2) {
  int error = 0;

  int null_check_one = check_null_bits(value_1);
  int null_check_two = check_null_bits(value_2);

  if (null_check_one != 0) {
    error = null_check_one;
  }
  if (null_check_two != 0) {
    error = null_check_two;
  }

  return error;
}

int check_null_bits(s21_decimal value) {
  int result = 0;

  for (unsigned i = 96; i < 112; i++) {
    unsigned result_1 = get_bit(&value, i);
    result = result_1 + result;
  }
  for (unsigned i = 120; i < 127; i++) {
    unsigned result_1 = get_bit(&value, i);
    result = result_1 + result;
  }
  if (get_sign_decimal(value) == 1) {
    result *= -1;
  }
  return result == 0 ? 0 : result < 0 ? 2 : 1;
}

void big_sum_bit(s21_big_decimal value, s21_big_decimal *result) {
  for (int i = 0, in_next = 0; i < 32 * 7; i++) {
    int tmp = 0;
    int x = big_get_bit(*result, i);
    int y = big_get_bit(value, i);

    tmp = x + y + in_next;

    if (tmp > 1) {
      in_next = 1;
      tmp %= 2;
    } else {
      in_next = 0;
    }

    big_set_bit(result, i, tmp);
  }
}