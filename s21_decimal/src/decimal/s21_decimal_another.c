#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_decimal value_1 = {{1, 0, 0, 0}};

  int error = S21_OK;

  if (get_sign_decimal(value) == 0) {
    error = s21_truncate(value, result);
  } else {
    error = s21_truncate(value, result);

    set_sign(result, 0);
    s21_add(*result, value_1, result);
    set_sign(result, 1);
  }
  return error;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_decimal buffer = {{0, 0, 0, 0}};
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_10 = {{10, 0, 0, 0}};
  s21_decimal value_5 = {{5, 0, 0, 0}};

  int sign = get_sign_decimal(value);
  set_sign(&value, S21_POSITIVE);

  int error = S21_OK;

  s21_mul(value, value_10, &buffer);
  error = s21_truncate(buffer, &buffer);
  buffer = s21_mod(buffer, value_10);

  if (s21_is_greater_or_equal(buffer, value_5) == 1 && error == 0) {
    error = s21_truncate(value, &value);
    error = s21_add(value, value_1, &value);
  } else {
    error = s21_truncate(value, &value);
  }

  *result = value;
  set_sign(result, sign);

  return error;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_decimal buffer = {{0, 0, 0, 0}};
  s21_decimal value_10 = {{10, 0, 0, 0}};

  int sign = get_sign_decimal(value);
  set_sign(&value, S21_POSITIVE);
  int scale = get_scale(value);

  normalize_by_scale(&value, scale);

  int error = S21_OK;
  while (scale > 0) {
    buffer = s21_mod(value, value_10);
    s21_sub(value, buffer, &value);
    s21_div(value, value_10, &value);
    scale--;
  }

  *result = value;
  set_sign(result, sign);

  return error;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;

  result->bits[3] =
      ((get_sign_decimal(value) ^ 1) << 31) | (get_scale(value) << 16);

  return 0;
}
