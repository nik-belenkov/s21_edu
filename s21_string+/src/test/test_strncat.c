#include "test.h"

START_TEST(strncat_0) {
  char dest[32] = "Ni Hao";
  char src[8] = " Sese";
  s21_size_t n = 3;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_1) {
  char dest[64] = "\0";
  char src[16] = "whoami55";
  s21_size_t n = 13;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_2) {
  char dest[64] = "\n";
  char src[16] = "zero;\0<byte";
  s21_size_t n = 9;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_3) {
  char dest[64] = "(.)_\t_(.)";
  char *src = "\0";
  s21_size_t n = 2;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_4) {
  char dest[32] = " \b";
  char src[32] = "\n 113 \n";
  s21_size_t n = 5;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_5) {
  char dest[32] = " O_0 ";
  char src[32] = "888";
  s21_size_t n = 0;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_6) {
  char dest[64] = " 0 ";
  char src[64] = "zxc";
  s21_size_t n = 2;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_7) {
  char dest[128] = " 0 ";
  char src[128] = "important messege is here AaBbCcDdEeFf-ZzYyXxWwVvQq";
  s21_size_t n = 33;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_8) {
  char dest[128] = "101010";
  char src[128] = "pascal live";
  s21_size_t n = 8;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_9) {
  char dest[128] = "OOOAAAUUUIII";
  char src[8] = "E";
  s21_size_t n = 6;
  ck_assert_pstr_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s = suite_create("suite_strncat");
  TCase *tc = tcase_create("case_strncat");

  tcase_add_test(tc, strncat_0);
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);

  suite_add_tcase(s, tc);
  return s;
}