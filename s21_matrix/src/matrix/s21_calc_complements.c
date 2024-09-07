#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = s21_check_valid_matrix(A) ? OK : INCORRECT_MATRIX;
  code = result != NULL ? OK : INCORRECT_MATRIX;
  if (code == OK) {
    if (A->rows == A->columns) {
      code = s21_create_matrix(A->rows, A->columns, result);
      result->matrix[0][0] = 1;
      if (A->rows != 1) {
        for (int i = 0; i < A->rows; ++i) {
          for (int j = 0; j < A->columns; ++j) {
            double determinant = 0.0;
            matrix_t minor;
            code = get_minor(i + 1, j + 1, A, &minor);
            if (code == 0) {
              code = s21_determinant(&minor, &determinant);
              if (code == 0) {
                result->matrix[i][j] = pow(-1, i + j) * determinant;
              }
            }
            s21_remove_matrix(&minor);
          }
        }
      }
    } else {
      code = CALCULATION_ERROR;
    }
  }
  return code;
}

int get_minor(int row_pos, int column_pos, matrix_t *A, matrix_t *minor) {
  int code = INCORRECT_MATRIX;
  if (A->matrix != NULL) {
    code = s21_create_matrix(A->rows - 1, A->columns - 1, minor);
    if (code == OK) {
      int minor_row_pos = 0;
      int minor_column_pos = 0;
      for (int i = 0; i < A->rows; i++) {
        minor_row_pos = i;
        if (i > row_pos - 1) {
          minor_row_pos--;
        }
        for (int j = 0; j < A->columns; j++) {
          minor_column_pos = j;
          if (j > column_pos - 1) {
            minor_column_pos--;
          }
          if (i != row_pos - 1 && j != column_pos - 1) {
            minor->matrix[minor_row_pos][minor_column_pos] = A->matrix[i][j];
          }
        }
      }
    }
  }
  return code;
}