#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = s21_check_valid_matrix(A) ? OK : INCORRECT_MATRIX;
  if (code != INCORRECT_MATRIX) {
    code = s21_create_matrix(A->columns, A->rows, result);
    if (code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }
  return code;
}