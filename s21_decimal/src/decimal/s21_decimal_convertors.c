#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int err_code = FAIL;
  init_decimal(dst);
  uint8_t sign = 0;
  sign = src < 0 ? S21_NEGATIVE : S21_POSITIVE;
  src = sign == S21_POSITIVE ? src : -src;
  dst->bits[0] = src;
  set_sign_decimal(dst, sign);
  err_code = OK;
  return err_code;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int err_code = OK;
  int result = 0;
  result = src.bits[0];
  if (!is_positive_decimal(src)) {
    result = -result;
  }
  *dst = result;
  return err_code;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int err_code = OK;
  init_decimal(dst);
  err_code = check_float_range(fabsf(src));
  if (err_code == OK) {
    bool minus = false;
    if (src < 0) {
      minus = true;
    }
    int scale = 0;
    uint32_t abs_src = 0;
    scanf_float(src, &abs_src, &scale);
    if (scale <= 0) {
      convert_float_scale_eql_zero(&scale, abs_src, dst);
    } else {
      convert_float_scale_positive(&scale, abs_src, dst);
    }
    if (minus) {
      set_sign_decimal(dst, 1);
    }
  }
  return err_code;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int err_code = FAIL;
  if (dst != NULL) {
    double tmp = 0;
    int scale = 0;
    for (int i = 0; i < 96; i++) {
      if (get_bit(&src, i)) tmp += pow(2, i);
    }
    scale = get_scale(src);
    if (scale > 0) {
      for (int i = scale; i > 0; i--) {
        tmp /= 10.0;
      }
    }
    *dst = (float)tmp;
    if (get_bit(&src, 127)) {
      *dst *= -1;
    } else {
      *dst *= 1;
    }
    err_code = OK;
  }
  return err_code;
}
