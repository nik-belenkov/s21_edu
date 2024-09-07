#include "test.h"

START_TEST(sscanf_0) {
  const char *str_1 = "hello world";
  char s21_1[20] = {0};
  char s21_2[20] = {0};
  char std_1[20] = {0};
  char std_2[20] = {0};
  ck_assert_int_eq(s21_sscanf(str_1, "%s %s", s21_1, s21_2),
                   sscanf(str_1, "%s %s", std_1, std_2));
  ck_assert_str_eq(s21_1, std_1);
  ck_assert_str_eq(s21_2, std_2);
}
END_TEST

START_TEST(sscanf_1) {
  const char *str_1 = "empty %%";
  char ch_1, ch_2;
  ck_assert_int_eq(s21_sscanf(str_1, "%c", &ch_1), sscanf(str_1, "%c", &ch_2));
  ck_assert_int_eq(ch_1, ch_2);
}
END_TEST

START_TEST(sscanf_2) {
  const char *str_1 = "q w/rty";
  char x, y, z;
  char a, b, c;
  ck_assert_int_eq(s21_sscanf(str_1, "%c %c %c", &a, &b, &c),
                   sscanf(str_1, "%c %c %c", &x, &y, &z));
  ck_assert_int_eq(a, x);
  ck_assert_int_eq(b, y);
  ck_assert_int_eq(c, z);
}
END_TEST

Suite *suite_sscanf() {
  Suite *s = suite_create("suite_sscanf");
  TCase *tc = tcase_create("case_sscanf");

  tcase_add_test(tc, sscanf_0);
  tcase_add_test(tc, sscanf_1);
  tcase_add_test(tc, sscanf_2);
  suite_add_tcase(s, tc);
  return s;
}