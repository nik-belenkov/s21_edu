#include "test.h"

START_TEST(strpbrk_0) {
  char *str1 = "check";
  char *str2 = "check";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_1) {
  char *str1 = "check";
  char *str2 = "kcehc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  char *str1 = "check";
  char *str2 = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  char *str1 = "";
  char *str2 = "check";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  char *str1 =
      "Science, of course, works miracles, but happiness is much more valuable "
      "than being right.";
  char *str2 = "h";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
  char *str1 = "School 21";
  char *str2 = "12";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_6) {
  char *str1 = "ABCabcaBBc";
  char *str2 = "a";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_7) {
  char *str1 = "C10ne";
  char *str2 = "02468";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_8) {
  char *str1 = "School 21\n";
  char *str2 = "\n";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_9) {
  char *str1 = "Go\n0d night";
  char *str2 = " ";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("case_strpbrk");

  tcase_add_test(tc, strpbrk_0);
  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);
  tcase_add_test(tc, strpbrk_7);
  tcase_add_test(tc, strpbrk_8);
  tcase_add_test(tc, strpbrk_9);

  suite_add_tcase(s, tc);
  return s;
}