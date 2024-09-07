#include "test.h"

START_TEST(create_01) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_02) {
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_03) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 0, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_04) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(0, 5, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_05) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, -3, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_06) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(-3, 5, &A), INCORRECT_MATRIX);
}
END_TEST

Suite *suite_create_matrix(void) {
  Suite *s = suite_create("\033[45mS21_CREATE\033[0m");
  TCase *tc = tcase_create("case_create");

  tcase_add_test(tc, create_01);
  tcase_add_test(tc, create_02);
  tcase_add_test(tc, create_03);
  tcase_add_test(tc, create_04);
  tcase_add_test(tc, create_05);
  tcase_add_test(tc, create_06);

  suite_add_tcase(s, tc);
  return s;
}