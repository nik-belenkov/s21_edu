#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <math.h>

#include "s21_matrix.h"

void run_one_test(Suite *tc);
void run_tests(void);

Suite *suite_create_matrix(void);
Suite *suite_remove_matrix(void);
Suite *suite_sum(void);
Suite *suite_sub(void);
Suite *suite_transpose(void);
Suite *suite_equal(void);
Suite *suite_mult_number(void);
Suite *suite_mult_matrix(void);
Suite *suite_calc_complements(void);
Suite *suite_determinant(void);
Suite *suite_inverse(void);

#endif
// TEST_H