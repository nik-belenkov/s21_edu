#include "test.h"

START_TEST(trim_0) {
  char src[16] = "School 21";
  char trim_chars[] = "";
  char expected[16] = "School 21";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(trim_1) {
  char src[] = "";
  char trim_chars[] = "";
  char expected[] = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(trim_2) {
  char src[64] = "  was two spaces  ";
  char trim_chars[] = "";
  char expected[64] = "was two spaces";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(trim_3) {
  char src[64] = "+/-was any symbol=*!";
  char trim_chars[] = "+-*/!@=";
  char expected[64] = "was any symbol";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(trim_4) {
  char src[128] =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01223456789";
  char trim_chars[16] = "a9";
  char expected[] =
      "bcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0122345678";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(trim_5) {
  char src[64] = "     three_spaces_one_tab     ";
  // char trim_chars[] = S21_NULL;
  char *trim_chars = S21_NULL;
  char expected[64] = "three_spaces_one_tab";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(trim_6) {
  char src[16] = "School 21";
  char trim_chars[] = "";
  char expected[16] = "School 21";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(trim_7) {
  char src[16] = "School 21";
  char trim_chars[16] = "School 21";
  char expected[] = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(trim_8) {
  char src[16] = "School 21";
  char trim_chars[] = "";
  char expected[16] = "School 21";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(trim_9) {
  char src[32] = "        0-0         ";
  char trim_chars[] = "0 \t";
  char expected[] = "-";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s = suite_create("suite_trim");
  TCase *tc = tcase_create("case_trim");

  tcase_add_test(tc, trim_0);
  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);
  tcase_add_test(tc, trim_6);
  tcase_add_test(tc, trim_7);
  tcase_add_test(tc, trim_8);
  tcase_add_test(tc, trim_9);

  suite_add_tcase(s, tc);
  return s;
}