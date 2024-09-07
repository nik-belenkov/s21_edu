#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int code = OK;
  if (s21_check_valid_matrix(A)) {
    if (A->rows == A->columns) {
      if (A->rows == 1 && A->columns == 1) {
        *result = A->matrix[0][0];
      } else {
        *result = calculate_determinant(A);
      }
    } else {
      code = CALCULATION_ERROR;
    }
  } else {
    code = INCORRECT_MATRIX;
  }
  return code;
}

double calculate_determinant(matrix_t *A) {
  double determinant = 0.0;
  if (A->rows == 2) {
    determinant =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      matrix_t minor;
      get_minor(1, i + 1, A, &minor);
      determinant +=
          pow(-1, i) * A->matrix[0][i] * calculate_determinant(&minor);
      s21_remove_matrix(&minor);
    }
  }
  return determinant;
}