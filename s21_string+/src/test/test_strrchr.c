#include <limits.h>

#include "test.h"

START_TEST(strrchr_0) {
  // The test case when there is a sequence of characters in a string with
  // the single occurance of the character
  char str[UCHAR_MAX + 1] = {0, 0, [UCHAR_MAX] = '\0'};
  for (int ch = 0; ch < UCHAR_MAX; ch++) {
    str[ch] = ch;
  }

  for (int ch = 0; ch < UCHAR_MAX; ch++) {
    ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
  }
}
END_TEST

START_TEST(strrchr_1) {
  // The test case when there is a sequence of characters in a string with
  // the doubled occurance of each character
  char str[2 * UCHAR_MAX + 1] = {0, 0, [2 * UCHAR_MAX] = '\0'};
  for (int ch = 0; ch < 2 * UCHAR_MAX; ch++) {
    str[ch] = (ch % UCHAR_MAX);
  }

  for (int ch = 0; ch < UCHAR_MAX; ch++) {
    ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
  }
}
END_TEST

START_TEST(strrchr_2) {
  // The test case when there is only one character in a string
  char str[] = "0";

  str[0] = '0';
  for (int ch = 0; ch < UCHAR_MAX; ch++) {
    str[0] = ch;
    ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
  }
}
END_TEST

START_TEST(strrchr_3) {
  char *str = "Test";
  int ch = '\0';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char *str = "";
  int c = '\0';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("case_strrchr");

  tcase_add_test(tc, strrchr_0);
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);

  suite_add_tcase(s, tc);
  return s;
}