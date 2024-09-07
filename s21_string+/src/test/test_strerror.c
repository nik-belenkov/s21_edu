#include "test.h"

START_TEST(strerror_0) {
  int num = 0;
  ck_assert_str_eq(strerror(num), s21_strerror(num));
}
END_TEST

START_TEST(strerror_1) {
  int num = 16;
  ck_assert_str_eq(strerror(num), s21_strerror(num));
}
END_TEST

START_TEST(strerror_2) {
  int num = 41;
  ck_assert_str_eq(strerror(num), s21_strerror(num));
}
END_TEST

START_TEST(strerror_3) {
  int num = 42;
  ck_assert_str_eq(strerror(num), s21_strerror(num));
}
END_TEST

START_TEST(strerror_4) {
  int num = 49;
  ck_assert_str_eq(strerror(num), s21_strerror(num));
}
END_TEST

START_TEST(strerror_5) {
  int num = 58;
  ck_assert_str_eq(strerror(num), s21_strerror(num));
}
END_TEST

START_TEST(strerror_6) {
  int num = 70;
  ck_assert_str_eq(strerror(num), s21_strerror(num));
}
END_TEST

START_TEST(strerror_7) {
  int num = 113;
  ck_assert_str_eq(strerror(num), s21_strerror(num));
}
END_TEST

START_TEST(strerror_8) {
  int num = 133;
  ck_assert_str_eq(strerror(num), s21_strerror(num));
}
END_TEST

START_TEST(strerror_9) {
  int num = 300;
  ck_assert_str_eq(strerror(num), s21_strerror(num));
}
END_TEST

START_TEST(strerror_10) {
  const char *got = s21_strerror(-1);
  char *expected = strerror(-1);
  ck_assert_str_eq(got, expected);
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("case_strerror");

  tcase_add_test(tc, strerror_0);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);
  tcase_add_test(tc, strerror_5);
  tcase_add_test(tc, strerror_6);
  tcase_add_test(tc, strerror_7);
  tcase_add_test(tc, strerror_8);
  tcase_add_test(tc, strerror_9);
  tcase_add_test(tc, strerror_10);

  suite_add_tcase(s, tc);
  return s;
}