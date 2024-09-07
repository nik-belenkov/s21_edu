#include "test.h"

START_TEST(memcmp_0) {
  char *str1 = "check";
  char *str2 = "check";
  s21_size_t n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_1) {
  char *str1 = "0";
  char *str2 = "0";
  s21_size_t n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  char *str1 = "Linux";
  char *str2 = "Lin000";
  s21_size_t n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  char *str1 = "Start";
  char *str2 = "S";
  s21_size_t n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  char *str1 = "End";
  char *str2 = "dnE";
  s21_size_t n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_5) {
  char *str1 =
      "abcdefghijklmnopqrstuvwXyz 0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ "
      "9876543210";
  char *str2 =
      "abcdefghijklmnopqrstuvwxyz 0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ "
      "9876534210";
  s21_size_t n = 72;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  char *str1 =
      "abcdefghijklmnopqrstuvwxyz 0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ "
      "9876534210";
  char *str2 =
      "abcdefghijklmnopqrstuvwxyz 0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ "
      "9876543210";
  s21_size_t n = 72;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_7) {
  char *str1 =
      "abcdefghijklmnopqrstuvwxyz 0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ "
      "9876543210";
  char *str2 =
      "abcdefghijklmnopqrstuvwxyz 0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ "
      "9876543210";
  s21_size_t n = 72;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_8) {
  int arr1[] = {1, 2, 3, 13, 73, 101, 33, 15};
  int arr2[] = {101, 35, 42, 66};
  s21_size_t n = 4;
  ck_assert_int_eq(memcmp(arr1, arr2, n), s21_memcmp(arr1, arr2, n));
}
END_TEST

START_TEST(memcmp_9) {
  int arr1[] = {1, 2, 3, 73, 13, 101, 33, 15};
  int arr2[] = {1, 2, 3, 13, 37, 101, 33, 15};
  s21_size_t n = 2;
  ck_assert_int_eq(memcmp(arr1, arr2, n), s21_memcmp(arr1, arr2, n));
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s = suite_create("suite_memcmp");
  TCase *tc = tcase_create("case_memcmp");

  tcase_add_test(tc, memcmp_0);
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);

  suite_add_tcase(s, tc);
  return s;
}