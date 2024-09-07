#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = INCORRECT_MATRIX;
  if (s21_check_valid_matrix(A) && s21_check_valid_matrix(B)) {
    code = CALCULATION_ERROR;
    if (is_equal_size(A, B)) {
      code = s21_create_matrix(A->rows, A->columns, result);
      if (code == OK) {
        subtraction(A, B, result);
      }
    }
  }
  return code;
}

void subtraction(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
}