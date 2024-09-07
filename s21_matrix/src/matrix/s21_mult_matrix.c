#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = INCORRECT_MATRIX;
  if (s21_check_valid_matrix(A) && s21_check_valid_matrix(B)) {
    code = CALCULATION_ERROR;
    if (A->columns == B->rows) {
      code = s21_create_matrix(A->rows, B->columns, result);
      if (code == OK) {
        s21_multiply(A, B, result);
      }
    } else {
      result->rows = 0;
      result->columns = 0;
      result->matrix = NULL;
    }
  }
  return code;
}

void s21_multiply(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < B->rows; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
}