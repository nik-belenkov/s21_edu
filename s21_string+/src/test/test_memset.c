#include "test.h"

START_TEST(memset_0) {
  char str[16] = "School 21";
  int c = '}';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_1) {
  char str1[16] = "1234567890";
  char str2[16] = "5432167890";
  int c = ';';
  s21_size_t n = 10;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_2) {
  char str1[16] = "zxczxczxczxc";
  char str2[16] = "zxczxczxczxc";
  int c = '\0';
  s21_size_t n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_3) {
  char str1[16] = "zxczxczxczxc";
  char str2[16] = "zxczxczxczxc";
  int c = '\n';
  s21_size_t n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_4) {
  char str[8] = "SDFALG";
  int c = ']';
  s21_size_t n = 6;
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_5) {
  char str1[8] = "C10ne";
  char str2[8] = "C10ne";
  s21_size_t n = 5;
  char c = '1';
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_6) {
  char str1[8] = "clang";
  char str2[8] = "clang";
  char c = 'A';
  s21_size_t n = 3;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_7) {
  char *str1 = "";
  char *str2 = "";
  char c = '\0';
  s21_size_t n = 0;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suite_memset(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("case_memset");

  tcase_add_test(tc, memset_0);
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  tcase_add_test(tc, memset_6);
  tcase_add_test(tc, memset_7);

  suite_add_tcase(s, tc);
  return s;
}