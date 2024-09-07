#include "test.h"

START_TEST(s21_is_not_equal_01) {
  s21_decimal val1 = {{32, 0, 0, 0x80000000}};
  s21_decimal val2 = {{32, 0, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_not_equal(val1, val2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_02) {
  s21_decimal val1 = {{32, 0, 0, 0}};
  s21_decimal val2 = {{32, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(val1, val2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_020) {
  s21_decimal val1 = {{32, 0, 0, 0x01100000}};
  s21_decimal val2 = {{32, 0, 0, 0x01100000}};
  ck_assert_int_eq(s21_is_not_equal(val1, val2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_03) {
  s21_decimal val1 = {{32, 0, 0, 0x80000000}};
  s21_decimal val2 = {{32, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_04) {
  s21_decimal val1 = {{32, 0, 0, 0x80000000}};
  s21_decimal val2 = {{32, 1, 0, 0x80000000}};
  ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_05) {
  s21_decimal val1 = {{32, 0, 0, 0x80000000}};
  s21_decimal val2 = {{32, 0, 1, 0x80000000}};
  ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_06) {
  s21_decimal val1 = {{32, 0, 0, 0}};
  s21_decimal val2 = {{32, 1, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_07) {
  s21_decimal val1 = {{32, 0, 0, 0}};
  s21_decimal val2 = {{32, 0, 1, 0}};
  ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_08) {
  s21_decimal val1 = {{32, 0, 0, 0}};
  s21_decimal val2 = {{32, 0, 0, 0x00110000}};
  ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_09) {
  s21_decimal val1 = {{32, 0, 0, 0x80100000}};
  s21_decimal val2 = {{32, 0, 0, 0x80110000}};
  ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

Suite *suite_is_not_equal(void) {
  Suite *s = suite_create("\033[45mS21_IS_NOT_EQUAL\033[0m");
  TCase *tc = tcase_create("s21_is_not_equal_tc");

  tcase_add_test(tc, s21_is_not_equal_01);
  tcase_add_test(tc, s21_is_not_equal_02);
  tcase_add_test(tc, s21_is_not_equal_020);
  tcase_add_test(tc, s21_is_not_equal_03);
  tcase_add_test(tc, s21_is_not_equal_04);
  tcase_add_test(tc, s21_is_not_equal_05);
  tcase_add_test(tc, s21_is_not_equal_06);
  tcase_add_test(tc, s21_is_not_equal_07);
  tcase_add_test(tc, s21_is_not_equal_08);
  tcase_add_test(tc, s21_is_not_equal_09);

  suite_add_tcase(s, tc);
  return s;
}
