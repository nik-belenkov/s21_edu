#include "test.h"

START_TEST(calc_complements_01) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_02) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(1, 3, &A);
  set_elements(&A, 1, 3);
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_03) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &eq_matrix);
  A.matrix[0][0] = 5;
  eq_matrix.matrix[0][0] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(calc_complements_04) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 3, A.matrix[1][1] = 4;
  eq_matrix.matrix[0][0] = 4, eq_matrix.matrix[0][1] = -3;
  eq_matrix.matrix[1][0] = -2, eq_matrix.matrix[1][1] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(calc_complements_05) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 10,
  eq_matrix.matrix[0][2] = -20;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = -14,
  eq_matrix.matrix[1][2] = 8;
  eq_matrix.matrix[2][0] = -8, eq_matrix.matrix[2][1] = -2,
  eq_matrix.matrix[2][2] = 4;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

Suite *suite_calc_complements(void) {
  Suite *s = suite_create("\033[45mS21_CALC_COMPLEMENTS\033[0m");
  TCase *tc = tcase_create("case_calc_complements");

  tcase_add_test(tc, calc_complements_01);
  tcase_add_test(tc, calc_complements_02);
  tcase_add_test(tc, calc_complements_03);
  tcase_add_test(tc, calc_complements_04);
  tcase_add_test(tc, calc_complements_05);

  suite_add_tcase(s, tc);
  return s;
}