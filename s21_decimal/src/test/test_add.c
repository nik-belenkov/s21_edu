#include "test.h"

START_TEST(s21_test_add_0) {
  s21_decimal value_1 = {{0, 2147483648, 0, 0}};
  s21_decimal value_2 = {{0, 2147483648, 0, 0}};
  s21_decimal result;
  s21_decimal check = {{0, 0, 1, 0}};
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_1) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  set_scale(&value_1, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  set_scale(&value_2, 2);
  s21_decimal result;
  s21_decimal check = {{416, 0, 0, 0}};
  set_scale(&check, 2);
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_2) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
  set_scale(&value_1, 1);
  s21_decimal value_2 = {{2, 0, 0, 0}};
  set_scale(&value_2, 1);
  s21_decimal result;
  s21_decimal check = {{0x1, 0x0, 0x1, 0}};
  set_scale(&check, 1);
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_4) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  set_scale(&value_1, 2);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  set_scale(&value_2, 1);
  s21_decimal result;
  s21_decimal check = {{2873, 0, 0, 0}};
  set_scale(&check, 2);
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_5) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_scale(&value_2, 1);
  s21_decimal result;
  s21_decimal check = {{0x9999999a, 0x99999999, 0x19999999, 0}};
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_6) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_scale(&value_1, 1);
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal result;
  s21_decimal check = {{0x9999999a, 0x99999999, 0x19999999, 0}};
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_7) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result;
  s21_decimal check = {{0, 0, 0, 0}};
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_BIG);
}
END_TEST

START_TEST(s21_test_add_8) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  set_scale(&value_1, 2);
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  set_scale(&value_2, 1);
  s21_decimal result;
  s21_decimal check = {{2847, 0, 0, 0}};
  set_scale(&check, 2);
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_9) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  set_scale(&value_1, 1);
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  set_scale(&value_2, 2);
  set_sign(&value_2, 1);
  s21_decimal result;
  s21_decimal check = {{416, 0, 0, 0}};
  set_scale(&check, 2);
  set_sign(&check, 1);
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_10) {
  s21_decimal value_1 = {{1614, 0, 0, 0}};
  set_scale(&value_1, 3);
  s21_decimal value_2 = {{46071, 0, 0, 0}};
  set_scale(&value_2, 2);
  s21_decimal result;
  s21_decimal check = {{462324, 0, 0, 0}};
  set_scale(&check, 3);
  int code = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_11) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_decimal value_2 = {{27, 0, 0, 0}};
  s21_decimal result;

  int code = s21_add(value_1, value_2, &result);

  s21_decimal answer = {{40, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_12) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal value_2 = {{7, 0, 0, 0}};
  set_sign_decimal(&value_1, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_add(value_1, value_2, &result);

  s21_decimal answer = {{28, 0, 0, 0}};
  set_sign_decimal(&answer, S21_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_13) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal value_2 = {{7, 0, 0, 0}};
  set_sign_decimal(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_add(value_1, value_2, &result);

  s21_decimal answer = {{28, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_14) {
  s21_decimal value_1 = {{50, 0, 0, 0}};
  s21_decimal value_2 = {{30, 0, 0, 0}};
  set_sign_decimal(&value_1, S21_NEGATIVE);
  set_sign_decimal(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_add(value_1, value_2, &result);

  s21_decimal answer = {{80, 0, 0, 0}};
  set_sign_decimal(&answer, S21_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_15) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign_decimal(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_add(value_1, value_2, &result);

  s21_decimal answer = {{0, 0, 0, 0}};
  set_sign_decimal(&answer, S21_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_16) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result;

  int code = s21_add(value_1, value_2, &result);

  s21_decimal answer = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_BIG);
}
END_TEST

START_TEST(s21_test_add_17) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign_decimal(&value_1, S21_NEGATIVE);
  set_sign_decimal(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_add(value_1, value_2, &result);

  s21_decimal answer = {{0, 0, 0, 0}};
  set_sign_decimal(&answer, S21_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_SMALL);
}
END_TEST

START_TEST(s21_test_add_18) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  set_sign(&value_1, S21_NEGATIVE);
  set_sign(&value_2, S21_NEGATIVE);
  set_scale(&value_1, 2);
  s21_decimal result;

  int code = s21_add(value_1, value_2, &result);

  s21_decimal answer = {{1005, 0, 0, 0}};
  set_sign(&answer, S21_NEGATIVE);
  set_scale(&answer, 2);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(get_scale(result), 2);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_add_19) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  set_scale(&value_2, 2);
  s21_decimal result;

  int code = s21_add(value_1, value_2, &result);

  s21_decimal answer = {{510, 0, 0, 0}};
  set_scale(&answer, 2);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

Suite *suite_add(void) {
  Suite *s = suite_create("\033[45mS21_ADD\033[0m");
  TCase *tc = tcase_create("case_add");

  tcase_add_test(tc, s21_test_add_0);
  tcase_add_test(tc, s21_test_add_1);
  tcase_add_test(tc, s21_test_add_2);
  tcase_add_test(tc, s21_test_add_3);
  tcase_add_test(tc, s21_test_add_4);
  tcase_add_test(tc, s21_test_add_5);
  tcase_add_test(tc, s21_test_add_6);
  tcase_add_test(tc, s21_test_add_7);
  tcase_add_test(tc, s21_test_add_8);
  tcase_add_test(tc, s21_test_add_9);
  tcase_add_test(tc, s21_test_add_10);
  tcase_add_test(tc, s21_test_add_11);
  tcase_add_test(tc, s21_test_add_12);
  tcase_add_test(tc, s21_test_add_13);
  tcase_add_test(tc, s21_test_add_14);
  tcase_add_test(tc, s21_test_add_15);
  tcase_add_test(tc, s21_test_add_16);
  tcase_add_test(tc, s21_test_add_17);
  tcase_add_test(tc, s21_test_add_18);
  tcase_add_test(tc, s21_test_add_19);

  suite_add_tcase(s, tc);
  return s;
}