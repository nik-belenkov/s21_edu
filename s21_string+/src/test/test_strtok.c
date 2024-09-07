#include "test.h"

START_TEST(strtok_0) {
  char str[] = "Hello, World! This is a test.";
  char s21_str[] = "Hello, World! This is a test.";
  const char *delim = " ,.!";

  char *token = S21_NULL;
  char *s21_token = S21_NULL;

  ck_assert_pstr_eq(token = strtok(str, delim),
                    s21_token = s21_strtok(s21_str, delim));
  while (token != S21_NULL && s21_token != S21_NULL) {
    ck_assert_pstr_eq(token = strtok(S21_NULL, delim),
                      s21_token = s21_strtok(S21_NULL, delim));
  }
  ck_assert_ptr_null(token);
  ck_assert_ptr_null(s21_token);
}
END_TEST

START_TEST(strtok_1) {
  static char str[] = "?a???b,,,#c";
  static char s21_str[] = "?a???b,,,#c";
  ck_assert_pstr_eq(strtok(str, "?"), s21_strtok(s21_str, "?"));
  ck_assert_pstr_eq(strtok(S21_NULL, ","), s21_strtok(S21_NULL, ","));
  ck_assert_pstr_eq(strtok(S21_NULL, "#"), s21_strtok(S21_NULL, "#"));
  ck_assert_pstr_eq(strtok(S21_NULL, "?"), s21_strtok(S21_NULL, "?"));
}
END_TEST

START_TEST(strtok_2) {
  static char str[] = "abcde";
  static char s21_str[] = "abcde";
  const char delim[] = "!,:";

  char *token = S21_NULL;

  ck_assert_pstr_eq(token = strtok(str, delim), s21_strtok(s21_str, delim));
  ck_assert_pstr_eq(token = strtok(S21_NULL, delim),
                    s21_strtok(S21_NULL, delim));
  ck_assert_pstr_eq(token = strtok(S21_NULL, delim),
                    s21_strtok(S21_NULL, delim));
  ck_assert_pstr_eq(token = strtok(S21_NULL, delim),
                    s21_strtok(S21_NULL, delim));
  ck_assert_pstr_eq(token = strtok(S21_NULL, delim),
                    s21_strtok(S21_NULL, delim));
  ck_assert_pstr_eq(token = strtok(S21_NULL, delim),
                    s21_strtok(S21_NULL, delim));
  ck_assert_pstr_eq(token = strtok(S21_NULL, delim),
                    s21_strtok(S21_NULL, delim));
}
END_TEST

START_TEST(strtok_3) {
  const char delim[] = "!,:";
  ck_assert_pstr_eq(strtok(S21_NULL, delim), s21_strtok(S21_NULL, delim));
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("case_strtok");

  tcase_add_test(tc, strtok_0);
  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);

  suite_add_tcase(s, tc);
  return s;
}