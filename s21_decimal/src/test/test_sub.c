#include "test.h"

START_TEST(s21_test_sub_0) {
  s21_decimal value_1 = {{27, 0, 0, 0}};
  s21_decimal value_2 = {{13, 0, 0, 0}};
  s21_decimal result;

  int code = s21_sub(value_1, value_2, &result);

  s21_decimal answer = {{14, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_sub_1) {
  s21_decimal value_1 = {{33, 0, 0, 0}};
  s21_decimal value_2 = {{7, 0, 0, 0}};
  set_sign_decimal(&value_1, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_sub(value_1, value_2, &result);

  s21_decimal answer = {{40, 0, 0, 0}};
  set_sign_decimal(&answer, S21_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_sub_2) {
  s21_decimal value_1 = {{33, 0, 0, 0}};
  s21_decimal value_2 = {{7, 0, 0, 0}};
  set_sign_decimal(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_sub(value_1, value_2, &result);

  s21_decimal answer = {{40, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_sub_3) {
  s21_decimal value_1 = {{30, 0, 0, 0}};
  s21_decimal value_2 = {{70, 0, 0, 0}};
  set_sign_decimal(&value_1, S21_NEGATIVE);
  set_sign_decimal(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_sub(value_1, value_2, &result);

  s21_decimal answer = {{40, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_sub_4) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_sub(value_1, value_2, &result);

  s21_decimal answer = {{0, 0, 0, 0}};
  set_sign(&answer, S21_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_SMALL);
}
END_TEST

START_TEST(s21_test_sub_5) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_sub(value_1, value_2, &result);

  s21_decimal answer = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_BIG);
}
END_TEST

START_TEST(s21_test_sub_6) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  set_scale(&value_1, 2);
  s21_decimal result;

  int code = s21_sub(value_1, value_2, &result);

  s21_decimal answer = {{995, 0, 0, 0}};
  set_scale(&answer, 2);
  set_sign(&answer, S21_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(get_scale(result), 2);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_sub_7) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  set_scale(&value_2, 2);
  s21_decimal result;

  int code = s21_sub(value_1, value_2, &result);

  s21_decimal answer = {{490, 0, 0, 0}};
  set_scale(&answer, 2);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_sub_8) {
  s21_decimal value_1 = {{70, 0, 0, 0}};
  s21_decimal value_2 = {{30, 0, 0, 0}};
  set_sign_decimal(&value_1, S21_NEGATIVE);
  set_sign_decimal(&value_2, S21_NEGATIVE);
  s21_decimal result;

  int code = s21_sub(value_1, value_2, &result);

  s21_decimal answer = {{40, 0, 0, 0}};
  set_sign_decimal(&answer, S21_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

START_TEST(s21_test_sub_9) {
  s21_decimal value_1 = {{5000, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  set_scale(&value_1, 2);
  s21_decimal result;

  int code = s21_sub(value_1, value_2, &result);

  s21_decimal answer = {{40, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(result, answer), 1);
  ck_assert_int_eq(code, S21_OK);
}
END_TEST

Suite *suite_sub(void) {
  Suite *s = suite_create("\033[45mS21_SUB\033[0m");
  TCase *tc = tcase_create("case_sub");

  tcase_add_test(tc, s21_test_sub_0);
  tcase_add_test(tc, s21_test_sub_1);
  tcase_add_test(tc, s21_test_sub_2);
  tcase_add_test(tc, s21_test_sub_3);
  tcase_add_test(tc, s21_test_sub_4);
  tcase_add_test(tc, s21_test_sub_5);
  tcase_add_test(tc, s21_test_sub_6);
  tcase_add_test(tc, s21_test_sub_7);
  tcase_add_test(tc, s21_test_sub_8);
  tcase_add_test(tc, s21_test_sub_9);

  suite_add_tcase(s, tc);
  return s;
}