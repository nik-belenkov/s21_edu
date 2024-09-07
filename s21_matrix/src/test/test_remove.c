#include "test.h"

START_TEST(remove_01) {
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(remove_02) {
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(remove_03) {
  matrix_t A = {};
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

Suite *suite_remove_matrix(void) {
  Suite *s = suite_create("\033[45mS21_REMOVE\033[0m");
  TCase *tc = tcase_create("case_remove");

  tcase_add_test(tc, remove_01);
  tcase_add_test(tc, remove_02);
  tcase_add_test(tc, remove_03);

  suite_add_tcase(s, tc);

  return s;
}