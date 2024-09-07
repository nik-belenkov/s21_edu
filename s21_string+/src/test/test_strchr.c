#include "test.h"

START_TEST(strchr_0) {
  char str[32] = "School 21 \nn/ 12 loohcS";
  int c = '\n';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_1) {
  char str[16] = "Dlrow olleh\0";
  int c = 3;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  char *str = "School 21 \nn/ 12 loohcS";
  int c = 12;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  char *str = "Dlrow olleh\0000";
  int c = '\0';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_4) {
  char *str = "";
  int c = 0;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_5) {
  char *str = "z\t\0";
  int c = 'z';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_6) {
  char *str = "ZzYyXxWwVvAaBbCcDdEeFf";
  int c = 'b';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_7) {
  char *str = "HooOOkkKKZkk";
  int c = 'Z';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("case_strchr");

  tcase_add_test(tc, strchr_0);
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);

  suite_add_tcase(s, tc);
  return s;
}