#include "test.h"

START_TEST(int_to_decimal_01) {
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(2, &out);
  s21_decimal res = {{0x00000002, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_02) {
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(-2, &out);
  s21_decimal res = {{0x00000002, 0, 0, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_03) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(9283997, &out);
  s21_decimal res = {{0x008DA99D, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_04) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(1963320, &out);
  s21_decimal res = {{0x001DF538, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_05) {
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(2147483647, &out);
  s21_decimal res = {{0x7FFFFFFF, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_06) {
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_int_to_decimal(-2147483647, &out);
  s21_decimal res = {{0x7FFFFFFF, 0, 0, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_07) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(-156421000, &out);
  s21_decimal res = {{0x0952CB88, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_08) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(-839591300, &out);
  s21_decimal res = {{0x320B2584, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_09) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(-85700580, &out);
  s21_decimal res = {{0x051BAFE4, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_10) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(938954500, &out);
  s21_decimal res = {{0x37F74F04, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_11) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(-21918040, &out);
  s21_decimal res = {{0x014E7158, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_12) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(114873800, &out);
  s21_decimal res = {{0x06D8D5C8, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_13) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(103963400, &out);
  s21_decimal res = {{0x06325B08, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_14) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(-1841507000, &out);
  s21_decimal res = {{0x6DC32AB8, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(int_to_decimal_15) {
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_int_to_decimal(-2147483648, &out);
  s21_decimal res = {{0x80000000, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *suite_int_to_decimal(void) {
  Suite *s = suite_create("\033[45mS21_FROM_INT_TO_DECIMAL\033[0m");
  TCase *tc = tcase_create("s21_from_int_to_decimal_tc");

  tcase_add_test(tc, int_to_decimal_01);
  tcase_add_test(tc, int_to_decimal_02);
  tcase_add_test(tc, int_to_decimal_03);
  tcase_add_test(tc, int_to_decimal_04);
  tcase_add_test(tc, int_to_decimal_05);
  tcase_add_test(tc, int_to_decimal_06);
  tcase_add_test(tc, int_to_decimal_07);
  tcase_add_test(tc, int_to_decimal_08);
  tcase_add_test(tc, int_to_decimal_09);
  tcase_add_test(tc, int_to_decimal_10);
  tcase_add_test(tc, int_to_decimal_11);
  tcase_add_test(tc, int_to_decimal_12);
  tcase_add_test(tc, int_to_decimal_13);
  tcase_add_test(tc, int_to_decimal_14);
  tcase_add_test(tc, int_to_decimal_15);

  suite_add_tcase(s, tc);
  return s;
}