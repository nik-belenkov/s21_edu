#include "test.h"

START_TEST(s21_div_0) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{70, 0, 0, 0}};
  set_scale(&value_1, 1);
  set_scale(&value_2, 2);
  int code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_div_1) {
  s21_decimal value_1 = {{0x88888888, 0x88888888, 0x88888888, 0}};
  s21_decimal value_2 = {{0x2, 0, 0, 0}};
  set_sign(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0x44444444, 0x44444444, 0x44444444, 0}};
  set_sign(&check, 1);
  int code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_div_2) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{8, 0, 0, 0}};
  set_sign(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{125, 0, 0, 0}};
  set_scale(&check, 2);
  int code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_ZERO_DIV);
}
END_TEST

START_TEST(s21_div_4) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  set_scale(&value_2, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{1000u, 0, 0, 0}};
  int code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal value_1 = {{100, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  set_scale(&value_1, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{1, 0, 0, 0}};
  int code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_div_6) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  set_scale(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  // s21_decimal check = {{0, 0, 0, 0}};
  int code = s21_div(value_1, value_2, &result);
  // ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_BIG);
}
END_TEST

Suite *suite_div(void) {
  Suite *s = suite_create("\033[45mS21_DIV\033[0m");
  TCase *tc = tcase_create("case_div");

  tcase_add_test(tc, s21_div_0);
  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  tcase_add_test(tc, s21_div_3);
  tcase_add_test(tc, s21_div_4);
  tcase_add_test(tc, s21_div_5);
  tcase_add_test(tc, s21_div_6);

  suite_add_tcase(s, tc);
  return s;
}
