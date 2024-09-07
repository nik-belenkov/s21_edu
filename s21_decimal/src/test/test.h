#ifndef TEST_H
#define TEST_H

#include <check.h>

#include "s21_decimal.h"

void run_one_test(Suite *tc);
void run_tests(void);

Suite *suite_add(void);
Suite *suite_div(void);
Suite *suite_floor(void);
Suite *suite_decimal_to_float(void);
Suite *suite_decimal_to_int(void);
Suite *suite_float_to_decimal(void);
Suite *suite_int_to_decimal(void);
Suite *suite_is_equal(void);
Suite *suite_is_greater_or_equal(void);
Suite *suite_is_greater(void);
Suite *suite_is_less_or_equal(void);
Suite *suite_is_less(void);
Suite *suite_is_not_equal(void);
Suite *suite_mul(void);
Suite *suite_negate(void);
Suite *suite_round(void);
Suite *suite_sub(void);
Suite *suite_truncate(void);

#endif