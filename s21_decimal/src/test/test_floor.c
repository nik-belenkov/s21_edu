#include "test.h"

START_TEST(s21_floor_0) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  set_scale(&value_1, 3);

  s21_decimal check = {{7444, 0, 0, 0}};

  s21_decimal result;
  int code = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_floor_1) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  set_scale(&value_1, 3);
  set_sign(&value_1, 1);

  s21_decimal check = {{7445, 0, 0, 0}};
  set_sign(&check, 1);

  s21_decimal result;
  int code = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

Suite *suite_floor(void) {
  Suite *s = suite_create("\033[45mS21_FLOOR\033[0m");
  TCase *tc = tcase_create("case_floor");

  tcase_add_test(tc, s21_floor_0);
  tcase_add_test(tc, s21_floor_1);

  suite_add_tcase(s, tc);
  return s;
}