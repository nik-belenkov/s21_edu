#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;

  convert_to_big(value_1, &big_value_1);
  convert_to_big(value_2, &big_value_2);

  return big_is_less(big_value_1, big_value_2);
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_greater(value_1, value_2);
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;

  convert_to_big(value_1, &big_value_1);
  convert_to_big(value_2, &big_value_2);

  if (!big_is_less(big_value_1, big_value_2) &&
      !big_is_equal(big_value_1, big_value_2)) {
    result = 1;
  } else {
    result = 0;
  }

  return result;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_less(value_1, value_2);
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;

  convert_to_big(value_1, &big_value_1);
  convert_to_big(value_2, &big_value_2);

  return big_is_equal(big_value_1, big_value_2);
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}

//******************************************************************************************************
int big_is_greater(s21_big_decimal value_1, s21_big_decimal value_2) {
  int result = 0;

  for (int i = 254; i >= 0; i--) {
    if (big_get_bit(value_1, i) != big_get_bit(value_2, i)) {
      if (big_get_bit(value_1, i) == 1) {
        result = 1;
      }
      break;
    }
  }

  return result;
}

int is_equal_bit(s21_decimal value_1, s21_decimal value_2) {
  int result = 1;

  for (int i = 2; i >= 0; i--) {
    if (value_1.bits[i] != value_2.bits[i]) {
      result = 0;
      break;
    }
  }

  return result;
}

int big_is_equal_bit(s21_big_decimal value_1, s21_big_decimal value_2) {
  int result = 1;

  for (int i = 223; i >= 0; i--) {
    if (big_get_bit(value_1, i) != big_get_bit(value_2, i)) {
      result = 0;
      break;
    }
  }

  return result;
}

int is_equal_null(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  s21_big_decimal null;
  int result = 0;
  null_big_decimal(&null);

  if (big_is_equal_bit(*value_1, null)) {
    big_set_bit(value_1, 255, 0);
    result = 1;
  }
  if (big_is_equal_bit(*value_1, null)) {
    big_set_bit(value_2, 255, 0);
    result = 1;
  }
  return result;
}

int big_is_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  int result = 1;

  big_normalize(&value_1, &value_2);
  is_equal_null(&value_1, &value_2);

  if (big_get_sign(value_1) != big_get_sign(value_2)) {
    result = 0;
  } else {
    for (int i = 0; i <= 32 * 7; i++) {
      if (big_get_bit(value_1, i) != big_get_bit(value_2, i)) {
        result = 0;
        break;
      }
    }
  }

  return result;
}

int big_is_less(s21_big_decimal value_1, s21_big_decimal value_2) {
  int result = 0;

  big_normalize(&value_1, &value_2);
  is_equal_null(&value_1, &value_2);

  int sign_1 = big_get_bit(value_1, 255), sign_2 = big_get_bit(value_2, 255);
  if (sign_1 != sign_2) {
    if (sign_1 == 1) {
      result = 1;
    }
  } else if (big_is_equal(value_1, value_2)) {
    result = 0;
  } else {
    for (int i = 254; i >= 0; i--) {
      if (big_get_bit(value_1, i) != big_get_bit(value_2, i)) {
        if (big_get_bit(value_2, i) == 1) {
          result = 1;
        }
        break;
      }
    }

    if (sign_1 == 1 && sign_2 == 1) {
      result = (result == 1) ? 0 : 1;
    }
  }
  return result;
}