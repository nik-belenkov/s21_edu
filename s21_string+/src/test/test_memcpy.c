#include "test.h"

START_TEST(memcpy_0) {
  char dest[16] = "aAbB\t\0";
  char src[16] = "\n\0";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_1) {
  char dest[16] = "Dest\n";
  char src[16] = "\\\n";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_2) {
  char dest[32] = "School 2";
  char src[32] = "1\0\\1";
  s21_size_t n = 5;
  ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_3) {
  char dest[16] = "\0";
  char *src = " ";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_4) {
  char dest[32] = "memcopy_?-)(-?_ ";
  char *src = "o-o";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_5) {
  char dest[16] = "\n/n";
  char *src = "-6-7";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_6) {
  char dest[16] = "0oO23";
  char *src = "\0\f";
  s21_size_t n = 6;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_7) {
  char dest[16] = "%hf*-5";
  char *src = "\0\f";
  s21_size_t n = 2;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_8) {
  char dest[64] = "QWERTY";
  char *src = "Y";
  s21_size_t n = 2;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_9) {
  char dest[128] =
      ":((()))!,.. abcdefghijklmnopqrstuvwxyz 0123456789 "
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ 9876543210";
  char src[64] = "0\\(.)-(.)//0";
  s21_size_t n = 11;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("case_memcpy");

  tcase_add_test(tc, memcpy_0);
  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  tcase_add_test(tc, memcpy_6);
  tcase_add_test(tc, memcpy_7);
  tcase_add_test(tc, memcpy_8);
  tcase_add_test(tc, memcpy_9);

  suite_add_tcase(s, tc);
  return s;
}