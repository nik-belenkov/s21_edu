#include "test.h"

START_TEST(s21_round_0) {
  s21_decimal value_1 = {{7464923, 0, 0, 0}};
  set_scale(&value_1, 5);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_decimal result;
  int code = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_round_1) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  set_scale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result;
  int code = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal value_1 = {{7464923, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_scale(&value_1, 5);
  s21_decimal check = {{75, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal result;
  int code = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_scale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal result;
  int code = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

Suite *suite_round(void) {
  Suite *s = suite_create("\033[45mS21_ROUND\033[0m");
  TCase *tc = tcase_create("case_round");

  tcase_add_test(tc, s21_round_0);
  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);

  suite_add_tcase(s, tc);
  return s;
}