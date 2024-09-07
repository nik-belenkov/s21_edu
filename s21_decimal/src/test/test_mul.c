#include "test.h"

START_TEST(s21_test_mul_0) {
  s21_decimal value_1 = {{27, 0, 0, 0}};
  s21_decimal value_2 = {{13, 0, 0, 0}};
  s21_decimal result;

  int code = s21_mul(value_1, value_2, &result);

  s21_decimal answer = {{351, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_mul_1) {
  s21_decimal value_1 = {{27, 0, 0, 0}};
  s21_decimal value_2 = {{13, 0, 0, 0}};
  set_sign_decimal(&value_1, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_mul(value_1, value_2, &result);

  s21_decimal answer = {{351, 0, 0, 0}};
  set_sign_decimal(&answer, S21_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_mul_2) {
  s21_decimal value_1 = {{33, 0, 0, 0}};
  s21_decimal value_2 = {{7, 0, 0, 0}};
  set_sign_decimal(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_mul(value_1, value_2, &result);

  s21_decimal answer = {{231, 0, 0, 0}};
  set_sign_decimal(&answer, S21_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_mul_3) {
  s21_decimal value_1 = {{30, 0, 0, 0}};
  s21_decimal value_2 = {{70, 0, 0, 0}};
  set_sign_decimal(&value_1, S21_NEGATIVE);
  set_sign_decimal(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_mul(value_1, value_2, &result);

  s21_decimal answer = {{2100, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_mul_4) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result;

  int code = s21_mul(value_1, value_2, &result);

  s21_decimal answer = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_BIG);
}
END_TEST

START_TEST(s21_test_mul_5) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_mul(value_1, value_2, &result);

  s21_decimal answer = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_SMALL);
}
END_TEST

START_TEST(s21_test_mul_6) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result;

  int code = s21_mul(value_1, value_2, &result);

  s21_decimal answer = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_mul_7) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, S21_NEGATIVE);
  set_sign(&value_2, S21_NEGATIVE);
  set_scale(&value_1, 2);
  s21_decimal result;

  int code = s21_mul(value_1, value_2, &result);

  s21_decimal answer = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_BIG);
}
END_TEST

START_TEST(s21_test_mul_8) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, S21_NEGATIVE);
  set_sign(&value_2, S21_NEGATIVE);
  set_scale(&value_2, 2);
  s21_decimal result;

  int code = s21_mul(value_1, value_2, &result);

  s21_decimal answer = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_BIG);
}
END_TEST

Suite *suite_mul(void) {
  Suite *s = suite_create("\033[45mS21_MUL\033[0m");
  TCase *tc = tcase_create("case_mul");

  tcase_add_test(tc, s21_test_mul_0);
  tcase_add_test(tc, s21_test_mul_1);
  tcase_add_test(tc, s21_test_mul_2);
  tcase_add_test(tc, s21_test_mul_3);
  tcase_add_test(tc, s21_test_mul_4);
  tcase_add_test(tc, s21_test_mul_5);
  tcase_add_test(tc, s21_test_mul_6);
  tcase_add_test(tc, s21_test_mul_7);
  tcase_add_test(tc, s21_test_mul_8);

  suite_add_tcase(s, tc);
  return s;
}