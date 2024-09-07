#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = FAILURE;
  if (A->rows == B->rows && A->columns == B->columns) {
    code = SUCCESS;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > DIFF) {
          code = FAILURE;
          break;
        }
      }
    }
  }
  return code;
}