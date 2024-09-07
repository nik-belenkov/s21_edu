#include "test.h"

START_TEST(s21_truncate_0) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  set_scale(&value_1, 1);
  s21_decimal check = {{3, 0, 0, 0}};
  s21_decimal result;
  int code = s21_truncate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_truncate_1) {
  s21_decimal value_1 = {{123456, 0, 0, 0}};
  set_scale(&value_1, 3);
  set_sign(&value_1, 1);
  s21_decimal check = {{123, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal result;
  int code = s21_truncate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

Suite *suite_truncate(void) {
  Suite *s = suite_create("\033[45mS21_TRUNCATE\033[0m");
  TCase *tc = tcase_create("case_truncate");

  tcase_add_test(tc, s21_truncate_0);
  tcase_add_test(tc, s21_truncate_1);

  suite_add_tcase(s, tc);
  return s;
}