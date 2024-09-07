#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code = INCORRECT_MATRIX;
  if (result != NULL) {
    code = (rows > 0 && columns > 0) ? OK : INCORRECT_MATRIX;
    if (code == OK) {
      result->matrix = (double **)calloc(rows, sizeof(double *));
      if (result->matrix != NULL) {
        for (int i = 0; i < rows; i++) {
          result->matrix[i] = (double *)calloc(columns, sizeof(double));
          if (result->matrix[i] == NULL) {
            code = INCORRECT_MATRIX;
            break;
          }
        }
        result->columns = columns;
        result->rows = rows;
      } else {
        code = INCORRECT_MATRIX;
      }
    }
  }
  return code;
}