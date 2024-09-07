#include "test.h"

START_TEST(s21_is_less_01) {
  s21_decimal value_1 = {{32, 0, 0, 0}};
  s21_decimal value_2 = {{64, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_less_02) {
  s21_decimal value_1 = {{64, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{64, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_less_03) {
  s21_decimal value_1 = {{64, 0, 0, 0x000C0000}};
  s21_decimal value_2 = {{64, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_less_04) {
  s21_decimal value_1 = {{64, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{32, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

//---FALSE---
START_TEST(s21_is_less_05) {
  s21_decimal value_1 = {{64, 0, 0, 0}};
  s21_decimal value_2 = {{32, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_less_06) {
  s21_decimal value_1 = {{64, 0, 0, 0}};
  s21_decimal value_2 = {{64, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_less_07) {
  s21_decimal value_1 = {{64, 0, 0, 0}};
  s21_decimal value_2 = {{64, 0, 0, 0x000C0000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_less_08) {
  s21_decimal value_1 = {{32, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{64, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_less_09) {
  s21_decimal value_1 = {{64, 0, 0, 0x000C0000}};
  s21_decimal value_2 = {{64, 0, 0, 0x000C0000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_less_10) {
  s21_decimal value_1 = {{32, 0, 0, 0x80110000}};
  s21_decimal value_2 = {{64, 0, 0, 0x80110000}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_less_11) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  set_sign(&value_1, S21_NEGATIVE);
  set_sign(&value_2, S21_POSITIVE);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_less_12) {
  s21_decimal value_1 = {{123000, 0, 0, 0}};
  set_scale(&value_1, 3);
  s21_decimal value_2 = {{123, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_less_13) {
  s21_decimal value_1 = {{1230000, 0, 0, 0}};
  set_sign(&value_1, S21_NEGATIVE);
  set_scale(&value_1, 3);
  s21_decimal value_2 = {{123, 0, 0, 0}};
  set_sign(&value_2, S21_NEGATIVE);
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

Suite *suite_is_less(void) {
  Suite *s = suite_create("\033[45mS21_IS_LESS\033[0m");
  TCase *tc = tcase_create("s21_is_less_tc");

  tcase_add_test(tc, s21_is_less_01);
  tcase_add_test(tc, s21_is_less_02);
  tcase_add_test(tc, s21_is_less_03);
  tcase_add_test(tc, s21_is_less_04);
  tcase_add_test(tc, s21_is_less_05);
  tcase_add_test(tc, s21_is_less_06);
  tcase_add_test(tc, s21_is_less_07);
  tcase_add_test(tc, s21_is_less_08);
  tcase_add_test(tc, s21_is_less_09);
  tcase_add_test(tc, s21_is_less_10);
  tcase_add_test(tc, s21_is_less_11);
  tcase_add_test(tc, s21_is_less_12);
  tcase_add_test(tc, s21_is_less_13);

  suite_add_tcase(s, tc);
  return s;
}