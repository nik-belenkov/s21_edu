#include "test.h"

START_TEST(s21_is_greater_01) {
  s21_decimal value_1 = {{64, 0, 0, 0}};
  s21_decimal value_2 = {{32, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_greater_02) {
  s21_decimal value_1 = {{64, 0, 0, 0}};
  s21_decimal value_2 = {{64, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_greater_03) {
  s21_decimal value_1 = {{64, 0, 0, 0}};
  s21_decimal value_2 = {{64, 0, 0, 0x000C0000}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_greater_04) {
  s21_decimal value_1 = {{32, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{64, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 1);
}
END_TEST

//---FALSE---
START_TEST(s21_is_greater_05) {
  s21_decimal value_1 = {{32, 0, 0, 0}};
  s21_decimal value_2 = {{64, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_greater_06) {
  s21_decimal value_1 = {{64, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{64, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_greater_07) {
  s21_decimal value_1 = {{64, 0, 0, 0x000C0000}};
  s21_decimal value_2 = {{64, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_greater_08) {
  s21_decimal value_1 = {{64, 0, 0, 0x000C0000}};
  s21_decimal value_2 = {{64, 0, 0, 0x000C0000}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_greater_09) {
  s21_decimal value_1 = {{64, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{32, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_greater(value_1, value_2), 0);
}
END_TEST

Suite *suite_is_greater(void) {
  Suite *s = suite_create("\033[45mS21_IS_GREATER\033[0m");
  TCase *tc = tcase_create("s21_is_greater_tc");

  tcase_add_test(tc, s21_is_greater_01);
  tcase_add_test(tc, s21_is_greater_02);
  tcase_add_test(tc, s21_is_greater_03);
  tcase_add_test(tc, s21_is_greater_04);
  tcase_add_test(tc, s21_is_greater_05);
  tcase_add_test(tc, s21_is_greater_06);
  tcase_add_test(tc, s21_is_greater_07);
  tcase_add_test(tc, s21_is_greater_08);
  tcase_add_test(tc, s21_is_greater_09);

  suite_add_tcase(s, tc);
  return s;
}