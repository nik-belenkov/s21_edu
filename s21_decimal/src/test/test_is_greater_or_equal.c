#include "test.h"

START_TEST(s21_is_greater_or_equal_01) {
  s21_decimal value_1 = {{64, 0, 0, 0}};
  s21_decimal value_2 = {{32, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_02) {
  s21_decimal value_1 = {{64, 0, 0, 0}};
  s21_decimal value_2 = {{64, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_03) {
  s21_decimal value_1 = {{64, 0, 0, 0}};
  s21_decimal value_2 = {{64, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_04) {
  s21_decimal value_1 = {{64, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{64, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 1);
}
END_TEST

//---FALSE---
START_TEST(s21_is_greater_or_equal_05) {
  s21_decimal value_1 = {{32, 0, 0, 0}};
  s21_decimal value_2 = {{64, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_06) {
  s21_decimal value_1 = {{64, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{64, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), 0);
}
END_TEST

Suite *suite_is_greater_or_equal(void) {
  Suite *s = suite_create("\033[45mS21_IS_GREATER_OR_EQUAL\033[0m");
  TCase *tc = tcase_create("s21_is_greater_or_equal_tc");

  tcase_add_test(tc, s21_is_greater_or_equal_01);
  tcase_add_test(tc, s21_is_greater_or_equal_02);
  tcase_add_test(tc, s21_is_greater_or_equal_03);
  tcase_add_test(tc, s21_is_greater_or_equal_04);
  tcase_add_test(tc, s21_is_greater_or_equal_05);
  tcase_add_test(tc, s21_is_greater_or_equal_06);

  suite_add_tcase(s, tc);
  return s;
}
