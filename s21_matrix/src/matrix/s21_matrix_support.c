#include "s21_matrix.h"

int s21_check_valid_matrix(matrix_t *A) {
  int code = FAILURE;
  if (A != NULL) {
    if (A->columns > 0 && A->rows > 0 && A->matrix != NULL) {
      code = SUCCESS;
      for (int i = 0; i < A->rows; i++) {
        if (A->matrix[i] == NULL) {
          code = FAILURE;
          break;
        }
      }
    }
  }
  return code;
}

int is_equal_size(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? SUCCESS : FAILURE;
}

void set_elements(matrix_t *A, double start, double step) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = start;
      start += step;
    }
  }
}