#include "test.h"

void set_decimal(s21_decimal *value, int bits_count) {
  init_decimal(value);

  for (int i = 0; i < bits_count; i++) {
    // для теста заполним не все
    // if (i % 2) {
    // if (i % 2 == 0)
    { set_bit_decimal(value, i); }
  }
}

START_TEST(decimal_to_int_01) {
  s21_decimal inp = {{0x00000002, 0, 0, 0}};
  int out = -123456789;
  int res = 2;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_02) {
  s21_decimal inp = {{0x00000002, 0, 0, 0x80000000}};
  int out = 123456789;
  int res = -2;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_03) {
  s21_decimal inp = {{0x008DA99D, 0x00000000, 0x00000000, 0x00000000}};
  int out = -1;
  int res = 9283997;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_04) {
  s21_decimal inp = {{0x001DF538, 0x00000000, 0x00000000, 0x00000000}};
  int out = -1;
  int res = 1963320;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_05) {
  s21_decimal inp = {{0x7FFFFFFF, 0, 0, 0}};
  int out = -1;
  int res = 2147483647;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_06) {
  s21_decimal inp = {{0x7FFFFFFF, 0, 0, 0x80000000}};
  int out = 1;
  int res = -2147483647;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_07) {
  s21_decimal inp = {{0x0952CB88, 0x00000000, 0x00000000, 0x80000000}};
  int out = 1;
  int res = -156421000;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_08) {
  s21_decimal inp = {{0x320B2584, 0x00000000, 0x00000000, 0x80000000}};
  int out = 1;
  int res = -839591300;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_09) {
  s21_decimal inp = {{0x051BAFE4, 0x00000000, 0x00000000, 0x80000000}};
  int out = 1;
  int res = -85700580;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_10) {
  s21_decimal inp = {{0x37F74F04, 0x00000000, 0x00000000, 0x00000000}};
  int out = -1;
  int res = 938954500;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_11) {
  s21_decimal inp = {{0x014E7158, 0x00000000, 0x00000000, 0x80000000}};
  int out = 1;
  int res = -21918040;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_12) {
  s21_decimal inp = {{0x06D8D5C8, 0x00000000, 0x00000000, 0x00000000}};
  int out = -1;
  int res = 114873800;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_13) {
  s21_decimal inp = {{0x06325B08, 0x00000000, 0x00000000, 0x00000000}};
  int out = -1;
  int res = 103963400;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_14) {
  s21_decimal inp = {{0x6DC32AB8, 0x00000000, 0x00000000, 0x80000000}};
  int out = 1;
  int res = -1841507000;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_15) {
  s21_decimal inp = {{0x80000000, 0x00000000, 0x00000000, 0x80000000}};
  int out = 1;
  int res = -2147483648;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_int_16) {
  s21_decimal inp = {{0xFFFF, 0x00000000, 0x00000000, 0x00000000}};
  int out = -1;
  int res = 65535;
  int error = s21_from_decimal_to_int(inp, &out);
  ck_assert_int_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *suite_decimal_to_int(void) {
  Suite *s = suite_create("\033[45mS21_FROM_DECIMAL_TO_INT\033[0m");
  TCase *tc = tcase_create("s21_from_decimal_to_int_tc");

  tcase_add_test(tc, decimal_to_int_01);
  tcase_add_test(tc, decimal_to_int_02);
  tcase_add_test(tc, decimal_to_int_03);
  tcase_add_test(tc, decimal_to_int_04);
  tcase_add_test(tc, decimal_to_int_05);
  tcase_add_test(tc, decimal_to_int_06);
  tcase_add_test(tc, decimal_to_int_07);
  tcase_add_test(tc, decimal_to_int_08);
  tcase_add_test(tc, decimal_to_int_09);
  tcase_add_test(tc, decimal_to_int_10);
  tcase_add_test(tc, decimal_to_int_11);
  tcase_add_test(tc, decimal_to_int_12);
  tcase_add_test(tc, decimal_to_int_13);
  tcase_add_test(tc, decimal_to_int_14);
  tcase_add_test(tc, decimal_to_int_15);
  tcase_add_test(tc, decimal_to_int_16);

  suite_add_tcase(s, tc);
  return s;
}