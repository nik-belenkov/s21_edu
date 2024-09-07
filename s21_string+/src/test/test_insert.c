#include "test.h"

START_TEST(normal_data) {
  char first[] = {"test"};
  char second[] = {"cat"};
  char *item = NULL;

  item = s21_insert(first, second, 0);
  ck_assert_str_eq(item, "cattest");
  free(item);

  item = s21_insert(first, second, 1);
  ck_assert_str_eq(item, "tcatest");
  free(item);

  item = s21_insert(first, second, 4);
  ck_assert_str_eq(item, "testcat");
  free(item);
}
END_TEST

START_TEST(incorect_data) {
  char first[] = {"test"};
  char second[] = {"cat"};
  char *item = NULL;

  item = s21_insert(NULL, second, 2);
  ck_assert_ptr_null(item);
  free(item);

  item = s21_insert(first, second, -5);
  ck_assert_ptr_null(item);
  free(item);

  item = s21_insert(first, second, 6);
  ck_assert_ptr_null(item);
  free(item);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s;
  TCase *tc_core, *tc1_core;

  s = suite_create("Test insert");

  tc_core = tcase_create("Normal data");
  tc1_core = tcase_create("Incorect data");

  tcase_add_test(tc_core, normal_data);
  tcase_add_test(tc1_core, incorect_data);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc1_core);

  return s;
}