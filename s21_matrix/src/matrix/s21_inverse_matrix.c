#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (s21_check_valid_matrix(A)) {
    if (A->columns == A->rows) {
      double determinant = 0.0;
      s21_determinant(A, &determinant);
      if (fabs(determinant - 0) > DIFF) {
        matrix_t temporary_complements;
        code = s21_calc_complements(A, &temporary_complements);
        if (code == 0) {
          matrix_t temporary_transpose;
          code = s21_transpose(&temporary_complements, &temporary_transpose);
          if (code == 0) {
            s21_mult_number(&temporary_transpose, 1 / determinant, result);
          }
          s21_remove_matrix(&temporary_transpose);
        }
        s21_remove_matrix(&temporary_complements);
      } else {
        code = CALCULATION_ERROR;
      }
    } else {
      code = CALCULATION_ERROR;
    }
  } else {
    code = INCORRECT_MATRIX;
  }
  return code;
}