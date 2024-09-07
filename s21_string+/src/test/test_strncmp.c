#include "test.h"

START_TEST(strncmp_1) {
  const char str_1[15] = "School";
  const char str_2[15] = "School";
  size_t n_1 = 5;
  size_t n_2 = 10;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n_1), strncmp(str_1, str_2, n_1));
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n_2), strncmp(str_1, str_2, n_2));
}
END_TEST

START_TEST(strncmp_2) {
  const char str_1[15] = "123456789";
  const char str_2[15] = "0123456789";
  size_t n_1 = 15;
  size_t n_2 = 5;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n_1), strncmp(str_1, str_2, n_1));
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n_2), strncmp(str_1, str_2, n_2));
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s = suite_create("suite_strncmp");
  TCase *tc = tcase_create("case_strncmp");

  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);

  suite_add_tcase(s, tc);
  return s;
}