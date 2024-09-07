#include "test.h"

START_TEST(memchr_0) {
  char *str = "";
  int c = '\0';
  s21_size_t n = 0;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_1) {
  char *str = "School 21";
  int c = 50;
  s21_size_t n = 9;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_2) {
  char *str = "Linux";
  int c = 48;
  s21_size_t n = 5;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_3) {
  char *str = "Start";
  int c = 'S';
  s21_size_t n = 1;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_4) {
  char *str = "End";
  int c = 'd';
  s21_size_t n = 3;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_5) {
  char *str = "Middle of the night";
  int c = ' ';
  s21_size_t n = 10;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_6) {
  char *str = "Hello w\0rld";
  int c = 'd';
  s21_size_t n = 15;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_7) {
  char *str = "Hello\nworld";
  int c = 'w';
  s21_size_t n = 7;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_8) {
  char *str = "Hello54world";
  int c = '4';
  s21_size_t n = 13;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_9) {
  int arr[] = {1, 2, 3, 13, 73, 101, 33, 15};
  int c = 101;
  s21_size_t n = sizeof(int) * 8;
  ck_assert_ptr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("case_memchr");

  tcase_add_test(tc, memchr_0);
  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  tcase_add_test(tc, memchr_6);
  tcase_add_test(tc, memchr_7);
  tcase_add_test(tc, memchr_8);
  tcase_add_test(tc, memchr_9);

  suite_add_tcase(s, tc);
  return s;
}