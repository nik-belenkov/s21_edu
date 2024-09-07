#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  null_decimal(result);

  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;
  s21_big_decimal big_result;

  convert_to_big(value_1, &big_value_1);
  convert_to_big(value_2, &big_value_2);

  big_add(big_value_1, big_value_2, &big_result);
  big_round_banker(&big_result);

  int error = convert_from_big(big_result, result);
  return error;
}

int big_add(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result) {
  unsigned int rem = 0;

  int sign_1 = big_get_sign(value_1);
  int sign_2 = big_get_sign(value_2);

  null_big_decimal(result);

  int error = S21_OK;
  error = big_normalize(&value_1, &value_2);

  unsigned int scale = big_get_scale(value_1);

  if (sign_1 != sign_2) {
    s21_big_decimal value_modul_1, value_modul_2;
    value_modul_1 = value_1;
    value_modul_2 = value_2;
    big_set_bit(&value_modul_1, 255, 0);
    big_set_bit(&value_modul_2, 255, 0);

    if (big_is_less(value_modul_1, value_modul_2) && sign_2) {
      big_set_bit(result, 255, 1);
    } else if (big_is_less(value_modul_2, value_modul_1) && sign_1) {
      big_set_bit(result, 255, 1);
    }
  }

  if (sign_1 == 1 && sign_2 == 1) {
    big_set_bit(result, 255, 1);
  }
  if (big_get_sign(value_1) == 1) {
    big_invertation(&value_1);
  }
  if (big_get_sign(value_2) == 1) {
    big_invertation(&value_2);
  }

  for (int i = 0; i < 32 * 7; i++) {
    unsigned int bit_1 = big_get_bit(value_1, i),
                 bit_2 = big_get_bit(value_2, i), temp = 0;
    temp = bit_1 + bit_2 + rem;
    rem = get_bit_int(temp, 1);
    set_bit_int(&temp, 1, 0);
    big_set_bit(result, i, temp);
  }
  big_set_scale(result, scale);

  if (big_get_bit(*result, 255) == 1) {
    big_invertation(result);
  }
  if (rem != 0) {
    if (!big_get_bit(*result, 127))
      error = 1;
    else
      error = 2;
  }

  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  null_decimal(result);

  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;
  s21_big_decimal big_result;

  convert_to_big(value_1, &big_value_1);
  convert_to_big(value_2, &big_value_2);

  big_sub(big_value_1, big_value_2, &big_result);
  big_round_banker(&big_result);

  int error = convert_from_big(big_result, result);
  return error;
}

int big_sub(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result) {
  int error = S21_OK;

  null_big_decimal(result);
  big_set_bit(&value_2, 255, !big_get_bit(value_2, 255));

  error = big_add(value_1, value_2, result);
  return error;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = check_valid(value_1, value_2);
  if (error != 0) return error;

  s21_big_decimal big_result;
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;

  null_decimal(result);
  null_big_decimal(&big_result);

  convert_to_big(value_1, &big_value_1);
  convert_to_big(value_2, &big_value_2);

  for (unsigned i = 0; i < 32 * 7; i++) {
    if (big_get_bit(big_value_2, i) == 1) {
      s21_big_decimal res = big_value_1;
      unsigned tmp = 0;
      while (tmp < i) {
        big_bit_shift(&res, 1);
        tmp += 1;
      }
      big_sum_bit(res, &big_result);
    }
  }

  big_result.bits[7] ^= big_value_1.bits[7];
  big_result.bits[7] ^= big_value_2.bits[7];

  int scale = big_get_scale(big_value_1) + big_get_scale(big_value_2);

  big_set_scale(&big_result, scale);
  big_round_banker(&big_result);

  error = convert_from_big(big_result, result);
  return error;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = S21_OK;
  if (is_equal_bit(value_2, (s21_decimal){{0, 0, 0, 0}})) return S21_ZERO_DIV;

  s21_big_decimal zero;
  s21_big_decimal big_result;
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;
  s21_big_decimal pre_frac;
  s21_big_decimal fraction;
  s21_big_decimal integral;

  convert_to_big(value_1, &big_value_1);
  convert_to_big(value_2, &big_value_2);

  int scale_1 = big_get_scale(big_value_1);
  int scale_2 = big_get_scale(big_value_2);

  null_decimal(result);
  big_set_scale_null(&big_value_1);
  big_set_scale_null(&big_value_2);

  null_big_decimal(&zero);
  null_big_decimal(&big_result);
  null_big_decimal(&pre_frac);
  null_big_decimal(&fraction);
  null_big_decimal(&integral);

  s21_big_decimal remainder = big_mod(big_value_1, big_value_2, &integral);
  int scale_result = 0;

  while ((big_is_greater(remainder, zero)) && scale_result <= 31) {
    scale_result++;
    mul_10(&remainder);
    remainder = big_mod(remainder, big_value_2, &pre_frac);
    big_set_scale(&pre_frac, scale_result);
    big_add(fraction, pre_frac, &fraction);
  }

  big_add(integral, fraction, &big_result);

  int overflow = 0;

  scale_result = big_get_scale(big_result);
  scale_result = scale_1 - scale_2 + scale_result;

  if (scale_result < 0) {
    while (scale_result < 0) {
      overflow += mul_10(&big_result);
      scale_result++;
    }
  }

  big_set_scale(&big_result, scale_result);
  big_round_banker(&big_result);
  overflow += convert_from_big(big_result, result);

  if (get_sign_decimal(value_1) == get_sign_decimal(value_2)) {
    set_bit(result, 127, 0);
  } else {
    set_bit(result, 127, 1);
  }

  if (overflow) {
    error = get_sign_decimal(*result) ? 2 : 1;
  }

  return error;
}

s21_big_decimal big_mod(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  big_set_scale_null(&value_1);
  big_set_scale_null(&value_2);

  s21_big_decimal value_2_1, value_2_2, rem, one, temp_val_1;
  null_big_decimal(&value_2_1);
  null_big_decimal(&value_2_2);
  null_big_decimal(&rem);
  null_big_decimal(result);
  null_big_decimal(&one);
  null_big_decimal(&temp_val_1);

  one.bits[0] = 1;
  temp_val_1 = value_1;
  value_2_1 = value_2;
  value_2_2 = value_2;

  int i = 0;
  while (1) {
    value_2_1 = big_shift(value_2_1, i);
    if (big_is_less(value_1, value_2_1)) {
      big_sub(value_1, value_2_2, &value_1);
      rem = value_1;
      value_2_1 = value_2;
      value_2_2 = value_2;
      if (big_is_less(value_1, value_2) == 1) {
        big_add(*result, big_shift(one, i - 1), result);
        break;
      }
      big_add(*result, big_shift(one, i - 1), result);

      i = 0;
    } else {
      i = i + 1;
      value_2_2 = value_2_1;
      value_2_1 = value_2;
    }
  }

  if (big_is_less(temp_val_1, value_2)) {
    rem = temp_val_1;
  }

  return rem;
}

s21_decimal s21_mod(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal result;

  s21_big_decimal buffer_value_1;
  s21_big_decimal buffer_value_2;
  s21_big_decimal buffer_result;

  convert_to_big(value_1, &buffer_value_1);
  convert_to_big(value_2, &buffer_value_2);
  null_big_decimal(&buffer_result);

  buffer_result = big_mod(buffer_value_1, buffer_value_2, &buffer_value_1);
  convert_from_big(buffer_result, &result);

  return result;
}