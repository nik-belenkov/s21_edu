#include "test.h"

START_TEST(strcspn_0) {
  char *str1 = "check";
  char *str2 = "check";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_1) {
  char *str1 = "check";
  char *str2 = "kcehc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  char *str1 = "check";
  char *str2 = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  char *str1 = "";
  char *str2 = "check";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4) {
  char *str1 =
      "Science, of course, works miracles, but happiness is much more valuable "
      "than being right.";
  char *str2 = "h";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_5) {
  char *str1 = "School 21";
  char *str2 = "12";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_6) {
  char *str1 = "ABCabcaBBc";
  char *str2 = "a";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_7) {
  char *str1 = "C10ne";
  char *str2 = "02468";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_8) {
  char *str1 = "School 21\n";
  char *str2 = "\n";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_9) {
  char *str1 = "Go\n0d night";
  char *str2 = " ";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("case_strcspn");

  tcase_add_test(tc, strcspn_0);
  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);

  suite_add_tcase(s, tc);
  return s;
}