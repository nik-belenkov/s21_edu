#include "test.h"

START_TEST(strncpy_1) {
  char dest_1_1[20] = "hello world";
  char dest_1_2[20] = "hello world";
  const char src_1[10] = "goood";
  size_t n_1 = 3;
  ck_assert_str_eq(s21_strncpy(dest_1_1, src_1, n_1),
                   strncpy(dest_1_2, src_1, n_1));

  char dest_2_1[20] = "hello world";
  char dest_2_2[20] = "hello world";
  const char src_2[10] = "goood";
  size_t n_2 = 5;
  ck_assert_str_eq(s21_strncpy(dest_2_1, src_2, n_2),
                   strncpy(dest_2_2, src_2, n_2));

  char dest_3_1[20] = "hello world";
  char dest_3_2[20] = "hello world";
  const char src_3[10] = "goood";
  size_t n_3 = 8;
  ck_assert_str_eq(s21_strncpy(dest_3_1, src_3, n_3),
                   strncpy(dest_3_2, src_3, n_3));
}
END_TEST

START_TEST(strncpy_2) {
  char dest_1_1[20] = "0000000000";
  char dest_1_2[20] = "0000000000";
  const char src_1[10] = "XXX";
  size_t n_1 = 3;
  ck_assert_str_eq(s21_strncpy(dest_1_1, src_1, n_1),
                   strncpy(dest_1_2, src_1, n_1));

  char dest_2_1[20] = "123456789";
  char dest_2_2[20] = "123456789";
  const char src_2[10] = "goood";
  size_t n_2 = 5;
  ck_assert_str_eq(s21_strncpy(dest_2_1, src_2, n_2),
                   strncpy(dest_2_2, src_2, n_2));

  char dest_3_1[20] = "hello";
  char dest_3_2[20] = "hello";
  const char src_3[10] = "goood";
  size_t n_3 = 8;
  ck_assert_str_eq(s21_strncpy(dest_3_1, src_3, n_3),
                   strncpy(dest_3_2, src_3, n_3));
}
END_TEST

START_TEST(strncpy_3) {
  char dest_1_1[20] = "00000\t00000";
  char dest_1_2[20] = "00000\t00000";
  const char src_1[10] = "XXX";
  size_t n_1 = 10;
  ck_assert_str_eq(s21_strncpy(dest_1_1, src_1, n_1),
                   strncpy(dest_1_2, src_1, n_1));

  char dest_2_1[20] = "12345\n6789";
  char dest_2_2[20] = "12345\n6789";
  const char src_2[10] = "go\0od";
  size_t n_2 = 10;
  ck_assert_str_eq(s21_strncpy(dest_2_1, src_2, n_2),
                   strncpy(dest_2_2, src_2, n_2));

  char dest_3_1[20] = "hel\t\t\t\t\t\t\tlo";
  char dest_3_2[20] = "hel\t\t\t\t\t\t\tlo";
  const char src_3[10] = "goood";
  size_t n_3 = 7;
  ck_assert_str_eq(s21_strncpy(dest_3_1, src_3, n_3),
                   strncpy(dest_3_2, src_3, n_3));
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("case_strncpy");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);

  suite_add_tcase(s, tc);
  return s;
}