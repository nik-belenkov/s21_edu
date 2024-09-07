#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define FAIL 1

#define MINUS_MASK 0x80000000      // 10000000 00000000 00000000 00000000
#define SCALE_MASK 0x00ff0000      // 00000000 11111111 00000000 00000000
#define SCALE_MAX 28               // 00000000 00011100 00000000 00000000
#define BITS_MAX 0xffffffff        // 11111111 11111111 11111111 11111111
#define MASK_1111 15               // 00000000 00000000 00000000 11111111
#define BCD_OVERFLOW_CORRRECTOR 3  // 0011
#define BCD_PREOVERFLOW_VALUE 5    // 0101
#define INT_MIN -2147483648
#define S21_DECIMAL_DEFAULT 0
// #define MAX_INT 79228162514264337593543950334  // = 2 ^ 96 - 1
#define S21_INF 1. / 0.
#define EPS 1e-7

#define BYTES_IN_DECIMAL 4
#define INT_BIT 32
#define BYTES_IN_BCD 15  //  (29 / 2 ≈ 15)
#define INT8_BIT 8

#define S21_POSITIVE 0
#define S21_NEGATIVE 1

#define BYTES_IN_BIG 8

// Core types
// DECIMAL type
typedef struct {
  uint32_t bits[BYTES_IN_DECIMAL];
} s21_decimal;

// BIG_DECIMAL type
typedef struct {
  unsigned bits[BYTES_IN_BIG];
} s21_big_decimal;

// BCD type
typedef struct {
  uint8_t digits[BYTES_IN_BCD];
  uint8_t sign;
  uint8_t scale;
} s21_bcd;

void convert_from_bcd_to_decimal(s21_bcd *bcd, s21_decimal *decimal);

// Core functions
void init_decimal(s21_decimal *value);

int is_bit_set_decimal(s21_decimal *value, int index);
void set_bit_decimal(s21_decimal *value, int index);
void unset_bit_decimal(s21_decimal *value, int index);

void left_bit_shift_in_decimal(s21_decimal *value);
void right_bit_shift_in_decimal(s21_decimal *value);

int get_sign_decimal(s21_decimal value);
int get_scale_decimal(s21_decimal value);
void set_scale_decimal(s21_decimal *value, uint32_t scale);
void set_sign_decimal(s21_decimal *value, uint32_t sign);
int is_positive_decimal(s21_decimal value);

void init_bcd(s21_bcd *value);
int is_bit_set_bcd(s21_bcd *value, int index);
void set_bit_bcd(s21_bcd *value, int index);
void unset_bit_bcd(s21_bcd *value, int index);

void left_bit_shift_in_bcd(s21_bcd *value);
void right_bit_shift_in_bcd(s21_bcd *value);

uint8_t get_scale_bcd(s21_bcd value);

void convert_from_decimal_to_bcd(s21_decimal *decimal, s21_bcd *bcd);

int compare_float_as_string(float value_1, float value_2);
int check_float_range(float value);

typedef enum s21_arithmetic_error_code {
  S21_OK,
  S21_BIG,
  S21_SMALL,
  S21_ZERO_DIV
} s21_arithmetic_error_code;

// Arithmetic operators
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Comparison operators
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// Support comparison
int big_is_greater(s21_big_decimal value_1, s21_big_decimal value_2);
int is_equal_bit(s21_decimal value_1, s21_decimal value_2);
int big_is_equal_bit(s21_big_decimal value_1, s21_big_decimal value_2);
int is_equal_null(s21_big_decimal *value_1, s21_big_decimal *value_2);
int big_is_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int big_is_less(s21_big_decimal value_1, s21_big_decimal value_2);

// Convertors and parsers
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Support convertors
int compare_float_as_string(float value_1, float value_2);
int check_float_range(float value);
void corrector(int *mantisse, int *scale);
void scanf_float(float src, uint32_t *num, int *scale);
void convert_float_scale_eql_zero(int *scale, int num, s21_decimal *dst);
void convert_float_scale_positive(int *scale, int num, s21_decimal *dst);

// Another functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Support functions
void null_decimal(s21_decimal *value);
unsigned int get_bit(s21_decimal *value, int bit);
int set_bit(s21_decimal *value, int num, int bit);
int get_bit_int(unsigned int value, int bit);
int set_bit_int(unsigned int *bits, int num, int bit);
void set_sign(s21_decimal *value, int sign);
unsigned int get_scale(s21_decimal value);
int set_scale(s21_decimal *value, unsigned int scale);
void search_bit(int bit, unsigned int *mask, int *num_int);
void big_search_bit(int bit, unsigned int *mask, int *num_int);
int check_valid(s21_decimal value_1, s21_decimal value_2);
int check_null_bits(s21_decimal value);
int normalize_by_scale(s21_decimal *value, int scale);
s21_decimal s21_mod(s21_decimal value_1, s21_decimal value_2);

// Big arithmetic operators
int big_add(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result);
int big_sub(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result);
s21_big_decimal big_mod(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);

// Big support functions
void null_big_decimal(s21_big_decimal *value);
unsigned big_get_sign(s21_big_decimal value);
unsigned int big_get_scale(s21_big_decimal value);
void big_set_scale(s21_big_decimal *value, unsigned int scale);
void big_set_scale_null(s21_big_decimal *value);
unsigned int big_get_bit(s21_big_decimal value, int bit);
int big_set_bit(s21_big_decimal *value, int num, int bit);
void convert_to_big(s21_decimal value, s21_big_decimal *result);
int big_round_banker(s21_big_decimal *result);
void bitwise_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
int big_bit_shift(s21_big_decimal *value, int shift);
s21_big_decimal big_shift(s21_big_decimal value, int shift);
int convert_from_big(s21_big_decimal value, s21_decimal *result);
int big_normalize(s21_big_decimal *value_1, s21_big_decimal *value_2);
int mul_10(s21_big_decimal *value);
void big_invertation(s21_big_decimal *value);
void big_sum_bit(s21_big_decimal value, s21_big_decimal *result);

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define ERROR_CONVERT 1

// Test functions
void set_binary_number(s21_decimal *number, const char *string_number);

#endif