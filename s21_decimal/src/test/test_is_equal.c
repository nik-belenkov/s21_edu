#include "test.h"

START_TEST(s21_is_equal_01) {
  s21_decimal val1 = {{32, 0, 0, 0x80000000}};
  s21_decimal val2 = {{32, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(s21_is_equal_02) {
  s21_decimal val1 = {{32, 0, 0, 0x80000000}};
  s21_decimal val2 = {{32, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(val1, val2), 0);
}
END_TEST

START_TEST(s21_is_equal_03) {
  s21_decimal val1 = {{32, 0, 0, 0x80000000}};
  s21_decimal val2 = {{32, 1, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_equal(val1, val2), 0);
}
END_TEST

START_TEST(s21_is_equal_04) {
  s21_decimal val1 = {{32, 0, 0, 0x80000000}};
  s21_decimal val2 = {{32, 0, 1, 0x80000000}};
  ck_assert_int_eq(s21_is_equal(val1, val2), 0);
}
END_TEST

START_TEST(s21_is_equal_05) {
  s21_decimal val1 = {{32, 0, 0, 0}};
  s21_decimal val2 = {{32, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(s21_is_equal_06) {
  s21_decimal val1 = {{32, 0, 0, 0x80110000}};
  s21_decimal val2 = {{32, 0, 0, 0x80110000}};
  ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(s21_is_equal_07) {
  s21_decimal val1 = {{32, 0, 0, 0x00110000}};
  s21_decimal val2 = {{32, 0, 0, 0x00110000}};
  ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(s21_is_equal_08) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  set_sign(&value_2, S21_NEGATIVE);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_equal_09) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  set_sign(&value_2, S21_NEGATIVE);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
}
END_TEST

Suite *suite_is_equal(void) {
  Suite *s = suite_create("\033[45mS21_IS_EQUAL\033[0m");
  TCase *tc = tcase_create("s21_is_equal_tc");

  tcase_add_test(tc, s21_is_equal_01);
  tcase_add_test(tc, s21_is_equal_02);
  tcase_add_test(tc, s21_is_equal_03);
  tcase_add_test(tc, s21_is_equal_04);
  tcase_add_test(tc, s21_is_equal_05);
  tcase_add_test(tc, s21_is_equal_06);
  tcase_add_test(tc, s21_is_equal_07);
  tcase_add_test(tc, s21_is_equal_08);
  tcase_add_test(tc, s21_is_equal_09);

  suite_add_tcase(s, tc);
  return s;
}
