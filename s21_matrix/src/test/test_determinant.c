#include "test.h"

START_TEST(determinant_01) {
  matrix_t A = {};
  double det = 0;
  ck_assert_int_eq(s21_determinant(&A, &det), INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_02) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 2, &A);
  set_elements(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_03) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 3, &A);
  set_elements(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_04) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(2, 2, &A);
  set_elements(&A, 3, 3);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, -18);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_05) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 21);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_06) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_07) {
  const int size = 4;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_08) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, 1e-6);
  ck_assert_int_eq(code, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_09) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, 1e-6);
  ck_assert_int_eq(code, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_10) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;
  m.matrix[0][1] = -4;
  m.matrix[1][0] = -2;
  m.matrix[1][1] = -3;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 7, 1e-6);
  ck_assert_int_eq(code, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_11) {
  const int size = 1;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -5, 1e-6);
  ck_assert_int_eq(code, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_12) {
  matrix_t m = {0};
  int rows = rand() % 100 + 1;
  rows = -rows;
  s21_create_matrix(rows, rows, &m);
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_13) {
  matrix_t m = {0};
  int rows = 4;
  int cols = 5;
  s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = rand() * (DBL_MAX - DBL_MIN) / DBL_MAX + DBL_MIN;
    }
  }
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

Suite *suite_determinant(void) {
  Suite *s = suite_create("\033[45mS21_DETERMINANT\033[0m");
  TCase *tc = tcase_create("case_determinant");

  tcase_add_test(tc, determinant_01);
  tcase_add_test(tc, determinant_02);
  tcase_add_test(tc, determinant_03);
  tcase_add_test(tc, determinant_04);
  tcase_add_test(tc, determinant_05);
  tcase_add_test(tc, determinant_06);
  tcase_add_test(tc, determinant_07);
  tcase_add_test(tc, determinant_08);
  tcase_add_test(tc, determinant_09);
  tcase_add_test(tc, determinant_10);
  tcase_add_test(tc, determinant_11);
  tcase_add_loop_test(tc, determinant_12, 0, 100);
  tcase_add_test(tc, determinant_13);

  suite_add_tcase(s, tc);
  return s;
}