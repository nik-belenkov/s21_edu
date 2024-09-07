#include "test.h"

START_TEST(normal_data) {
  char *str;

  str = s21_to_lower("A");
  ck_assert_str_eq(str, "a");
  free(str);

  str = s21_to_lower("TeSt1_TE.....ST");
  ck_assert_str_eq(str, "test1_te.....st");
  free(str);

  str = s21_to_lower("1234...123");
  ck_assert_str_eq(str, "1234...123");
  free(str);
}
END_TEST

START_TEST(incorect_data) {
  char *str;

  str = s21_to_lower(NULL);
  ck_assert_ptr_null(str);
}
END_TEST

Suite *suite_to_lower(void) {
  Suite *s;
  TCase *tc_core, *tc1_core;

  s = suite_create("Test to_lower");

  tc_core = tcase_create("Normal data");
  tc1_core = tcase_create("Incorect data");

  tcase_add_test(tc_core, normal_data);
  tcase_add_test(tc1_core, incorect_data);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc1_core);

  return s;
}