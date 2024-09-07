#include "test.h"

START_TEST(sub_01) {
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(sub_02) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_03) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  set_elements(&A, 1, 1);
  set_elements(&B, 1, 1);
  B.matrix[3][3] = INFINITY;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_04) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  set_elements(&A, 1, 1);
  set_elements(&B, 1, 1);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(sub_05) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(sub_06) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = -2, eq_matrix.matrix[1][1] = 4,
  eq_matrix.matrix[1][2] = 5;
  eq_matrix.matrix[2][0] = -3, eq_matrix.matrix[2][1] = -4,
  eq_matrix.matrix[2][2] = 5;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(sub_07) {
  matrix_t A = {};
  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 2, A.matrix[0][1] = 3, A.matrix[0][2] = 0;
  A.matrix[1][0] = 1, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  matrix_t B = {};
  B.rows = 2;
  B.columns = 3;
  B.matrix = (double **)malloc(2 * sizeof(double *));
  B.matrix[0] = (double *)calloc(3, sizeof(double));
  B.matrix[1] = NULL;
  matrix_t result = {};
  s21_create_matrix(2, 3, &result);
  matrix_t F = {};
  s21_create_matrix(2, 3, &F);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &F), SUCCESS);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  B.rows = 0;
  B.columns = 0;
  free(B.matrix[0]);
  free(B.matrix);
  s21_remove_matrix(&result);
  s21_remove_matrix(&F);
}
END_TEST

Suite *suite_sub(void) {
  Suite *s = suite_create("\033[45mS21_SUB\033[0m");
  TCase *tc = tcase_create("case_sub");

  tcase_add_test(tc, sub_01);
  tcase_add_test(tc, sub_02);
  tcase_add_test(tc, sub_03);
  tcase_add_test(tc, sub_04);
  tcase_add_test(tc, sub_05);
  tcase_add_test(tc, sub_06);
  tcase_add_test(tc, sub_07);

  suite_add_tcase(s, tc);
  return s;
}