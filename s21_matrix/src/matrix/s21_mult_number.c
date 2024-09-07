#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = s21_check_valid_matrix(A);
  if (code != FAILURE) {
    code = number != NAN ? OK : CALCULATION_ERROR;
  } else {
    code = INCORRECT_MATRIX;
  }

  if (code != CALCULATION_ERROR && code != INCORRECT_MATRIX) {
    code = s21_create_matrix(A->rows, A->columns, result);
  }

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return code;
}