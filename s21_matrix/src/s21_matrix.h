#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define DIFF 1E-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum return_code { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_check_valid_matrix(matrix_t *A);
int is_equal_size(matrix_t *A, matrix_t *B);

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void s21_multiply(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void subtraction(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void summation(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

void set_elements(matrix_t *A, double start, double step);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_calc_complements(matrix_t *A, matrix_t *result);
int get_minor(int row_pos, int column_pos, matrix_t *A, matrix_t *minor);

int s21_determinant(matrix_t *A, double *result);
double calculate_determinant(matrix_t *A);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif
// S21_MATRIX_H