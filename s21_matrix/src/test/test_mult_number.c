#include "test.h"

START_TEST(mult_number_01) {
  matrix_t A = {};
  double number = 3.14;
  s21_create_matrix(3, 3, &A);
  set_elements(&A, 1, 1);
  ck_assert_int_eq(s21_mult_number(&A, number, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_02) {
  matrix_t A = {};
  matrix_t result = {};
  double number = INFINITY;
  s21_create_matrix(3, 3, &A);
  set_elements(&A, 1, 1);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_03) {
  matrix_t A = {};
  matrix_t result = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  set_elements(&A, 1, 1);
  A.matrix[2][2] = INFINITY;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_04) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(mult_number_05) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  set_elements(&A, 1, 1);
  s21_create_matrix(3, 3, &eq_matrix);
  set_elements(&eq_matrix, 3, 3);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(mult_number_06) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 2;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 3, A.matrix[2][2] = 4;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 2, eq_matrix.matrix[0][1] = 4,
  eq_matrix.matrix[0][2] = 6;
  eq_matrix.matrix[1][0] = 0, eq_matrix.matrix[1][1] = 8,
  eq_matrix.matrix[1][2] = 4;
  eq_matrix.matrix[2][0] = 4, eq_matrix.matrix[2][1] = 6,
  eq_matrix.matrix[2][2] = 8;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

Suite *suite_mult_number(void) {
  Suite *s = suite_create("\033[45mS21_MULT_NUMBER\033[0m");
  TCase *tc = tcase_create("case_mult_number");

  tcase_add_test(tc, mult_number_01);
  tcase_add_test(tc, mult_number_02);
  tcase_add_test(tc, mult_number_03);
  tcase_add_test(tc, mult_number_04);
  tcase_add_test(tc, mult_number_05);
  tcase_add_test(tc, mult_number_06);

  suite_add_tcase(s, tc);
  return s;
}