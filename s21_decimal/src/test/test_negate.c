#include "test.h"

START_TEST(s21_negate_0) {
  s21_decimal value_1 = {{5, 0xFFFFFFFF, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal check = {{5, 0xFFFFFFFF, 0, 0}};
  s21_decimal result;
  int code = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_negate_1) {
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal check = {{1, 1, 1, 0x80000000}};
  s21_decimal result;
  int code = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

Suite *suite_negate(void) {
  Suite *s = suite_create("\033[45mS21_NEGATE\033[0m");
  TCase *tc = tcase_create("case_negate");

  tcase_add_test(tc, s21_negate_0);
  tcase_add_test(tc, s21_negate_1);

  suite_add_tcase(s, tc);
  return s;
}