#include "test.h"

START_TEST(decimal_to_float_0) {
  float res = 2;
  float out = -1234567;
  s21_decimal inp = {{0x00000002, 0, 0, 0}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  // ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_1) {
  float res = -321.2;
  float out = 1234567;
  s21_decimal inp = {{0x00000C8C, 0, 0, 0x80010000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  // ck_assert_float_eq_tol(out/res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_2) {
  float res = 321.2;
  float out = 1234567;
  s21_decimal inp = {{0x00000C8C, 0, 0, 0x00010000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_3) {
  float res = 321213200;
  float out = 1234567;
  s21_decimal inp = {{0x13255310, 0, 0, 0}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_4) {
  float res = 9732131234575756436473.323123474;
  float out = -1234567;
  s21_decimal inp = {{0xC7238000, 0x9472ED75, 0x0000020F, 0}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_5) {
  float res = 73.329959999;
  float out = -1234567;
  s21_decimal inp = {{0x006FE484, 0, 0, 0x00050000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_6) {
  float res = 0.003;
  float out = -1234567;
  s21_decimal inp = {{0x00000003, 0, 0, 0x00030000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_7) {
  float res = 0.00312345;
  float out = -1234567;
  s21_decimal inp = {{0x0004C419, 0, 0, 0x00080000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_8) {
  float res = 0.0000000312396;
  float out = -1234567;
  s21_decimal inp = {{0x0004C44C, 0, 0, 0x000D0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_9) {
  float res = 0.000000000000000009392939;
  float out = -1234567;
  s21_decimal inp = {{0x008F532B, 0, 0, 0x00180000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_10) {
  float res = 0.0000000000000000000000000001;
  float out = -1234567;
  s21_decimal inp = {{0x00000001, 0, 0, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_10_5) {
  float res = 0.0000000000000000000000000002;
  float out = -1234567;
  s21_decimal inp = {{0x00000002, 0, 0, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_11) {
  // float res = .00000000000000000000000000000000193929383838292;
  // //1.939293838382919998e-33
  float *out = NULL;
  s21_decimal inp = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_decimal_to_float(inp, out);
  // ck_assert_float_eq(out, res);
  // ck_assert_float_eq_tol(out/res, 1, 1e-6);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(decimal_to_float_12) {
  float res = 2.183182e+21f;  // 2183182381923912939123.365656f;
  float out = -1234567;
  s21_decimal inp = {{0x8ADB0000, 0x59BC8E01, 0x00000076, 0}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_13) {
  float res = 79215000000000000000000000000.365656;
  float out = -1234567;
  s21_decimal inp = {{0xCF000000, 0xAC05AE5D, 0xFFF51CBA, 0}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_14) {
  float res = 7015000000000000000000000000.365656;
  float out = -1234567;
  s21_decimal inp = {{0xC7000000, 0xFFD18396, 0x16AAAC07, 0}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_15) {
  float res = 0.0000000000000000000000000565;
  float out = -1234567;
  s21_decimal inp = {{0x00000235, 0, 0, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_16) {
  float res = 0.0000000000000000000000007374;
  float out = -1234567;
  s21_decimal inp = {{0x00001CCE, 0, 0, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  // ck_assert_float_eq(out, res);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_17) {
  float res = 0.0000000000000000000000085860;
  float out = -1234567;
  // s21_decimal inp = {{0x0000218A, 0, 0, 0x001B0000}};
  s21_decimal inp = {{0x00014F64, 0, 0, 0x1C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  // ck_assert_float_eq(out, res);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_18) {
  float res = 0.000000000000000000000099999999999;
  float out = -1234567;
  s21_decimal inp = {{0x00000001, 0, 0, 0x00160000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_19) {
  float res = 0.00000000000000000000073766666662636;
  float out = -1234567;
  s21_decimal inp = {{0x00708F1B, 0, 0, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_to_float_20) {
  float res = 0.0000000000000000000073736361612636;
  float out = -1234567;
  s21_decimal inp = {{0x00708344, 0, 0, 0x001B0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_to_float_21) {
  float res = 0.0000000000000000000000007374;
  float out = -1234567;
  s21_decimal inp = {{0x00001CCE, 0, 0, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_22) {
  float res = -1.307818E+07;
  float out = 1234567;
  s21_decimal inp = {{0x00C78EA4, 0x00000000, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_23) {
  float res = -30914.76;
  float out = 1234567;
  s21_decimal inp = {{0x002F2C14, 0x00000000, 0x00000000, 0x80020000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_24) {
  float res = 1.97E-26;
  float out = -1234567;
  s21_decimal inp = {{0x000000C5, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_25) {
  float res = -750.9904;
  float out = 1234567;
  s21_decimal inp = {{0x00729790, 0x00000000, 0x00000000, 0x80040000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_26) {
  float res = 72932.2;
  float out = -1234567;
  s21_decimal inp = {{0x000B20EA, 0x00000000, 0x00000000, 0x00010000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_27) {
  float res = 7.526432E-06;
  float out = -1234567;
  s21_decimal inp = {{0x0072D820, 0x00000000, 0x00000000, 0x000C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_29) {
  float res = -1.391184E+17;
  float out = -1234567;
  s21_decimal inp = {{0x9DB88000, 0x01EE3F72, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_30) {
  float res = 3.693497E-09;
  float out = -1234567;
  s21_decimal inp = {{0x00385BB9, 0x00000000, 0x00000000, 0x000F0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_31) {
  float res = 351871.4;
  float out = -1234567;
  s21_decimal inp = {{0x0035B0FA, 0x00000000, 0x00000000, 0x00010000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_32) {
  float res = 0.1175977;
  float out = -1234567;
  s21_decimal inp = {{0x0011F1A9, 0x00000000, 0x00000000, 0x00070000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_33) {
  float res = -2.013319E-14;
  float out = 1234567;
  s21_decimal inp = {{0x001EB887, 0x00000000, 0x00000000, 0x80140000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_34) {
  float res = -280.7036;
  float out = 1234567;
  s21_decimal inp = {{0x002AD4FC, 0x00000000, 0x00000000, 0x80040000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_35) {
  float res = -3.196059E+18;
  float out = 1234567;
  s21_decimal inp = {{0x2030B000, 0x2C5AAEBA, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_36) {
  float res = -138892000000000;  //-1.38892e+14;
  float out = 1234567;
  s21_decimal inp = {{0x50527800, 0x00007E52, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_37) {
  float res = 6.068951E+09;
  float out = -1234567;
  s21_decimal inp = {{0x69BCD7D8, 0x00000001, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_38) {
  float res = -1.190043E+24;
  float out = 1234567;
  s21_decimal inp = {{0xF98C0000, 0x5C3C75F5, 0x0000FC00, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_39) {
  float res = 4.5E-27;
  float out = -1234567;
  s21_decimal inp = {{0x0000002D, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_40) {
  float res = -7.442655E+23;
  float out = 1234567;
  s21_decimal inp = {{0x1B360000, 0xB6AE8261, 0x00009D9A, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_41) {
  float res = 8.763741E+26;
  float out = -1234567;
  s21_decimal inp = {{0x8CD00000, 0x28107A63, 0x02D4EB6F, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_42) {
  float res = -5E-28;
  float out = 1234567;
  s21_decimal inp = {{0x00000005, 0x00000000, 0x00000000, 0x801C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_43) {
  float res = 1.333345E+13;
  float out = -1234567;
  s21_decimal inp = {{0x6F8D0680, 0x00000C20, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_44) {
  float res = -3.85058E-06;
  float out = 1234567;
  s21_decimal inp = {{0x0005E022, 0x00000000, 0x00000000, 0x800B0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_45) {
  float res = 1.325723E-09;
  float out = -1234567;
  s21_decimal inp = {{0x00143A9B, 0x00000000, 0x00000000, 0x000F0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_46) {
  float res = -5.831514E+23;
  float out = 1234567;
  s21_decimal inp = {{0x30840000, 0xB3639777, 0x00007B7C, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_47) {
  float res = -1.337444E-22;
  float out = 1234567;
  s21_decimal inp = {{0x00146864, 0x00000000, 0x00000000, 0x801C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_48) {
  float res = 1.230342E+28;
  float out = -1234567;
  s21_decimal inp = {{0xAD800000, 0xA66BA8BD, 0x27C12686, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_49) {
  float res = -8.335803E-07;
  float out = 1234567;
  s21_decimal inp = {{0x007F31BB, 0x00000000, 0x00000000, 0x800D0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_50) {
  float res = 9.197E-25;
  float out = -1234567;
  s21_decimal inp = {{0x000023ED, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_51) {
  float res = 2.922531E+25;
  float out = -1234567;
  s21_decimal inp = {{0x9AB80000, 0x3ACC2F60, 0x00182CB3, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_52) {
  float res = 1.581408E+19;
  float out = -1234567;
  s21_decimal inp = {{0x319C0000, 0xDB76E5F9, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_53) {
  float res = -3.2E-27;
  float out = 1234567;
  s21_decimal inp = {{0x00000020, 0x00000000, 0x00000000, 0x801C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_54) {
  float res = 1.290434E-09;
  float out = -1234567;
  s21_decimal inp = {{0x0013B0C2, 0x00000000, 0x00000000, 0x000F0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_55) {
  float res = -1.162378E-20;
  float out = 1234567;
  s21_decimal inp = {{0x0011BC8A, 0x00000000, 0x00000000, 0x801A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_56) {
  float res = -1.609435E+11;
  float out = 1234567;
  s21_decimal inp = {{0x78FAEAE0, 0x00000025, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_57) {
  float res = -2.747507E-06;
  float out = 1234567;
  s21_decimal inp = {{0x0029EC73, 0x00000000, 0x00000000, 0x800C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_58) {
  float res = -2.E-28;
  float out = 1234567;
  s21_decimal inp = {{0x00000002, 0x00000000, 0x00000000, 0x801C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_59) {
  float res = -9.564972E-05;
  float out = 1234567;
  s21_decimal inp = {{0x0091F32C, 0x00000000, 0x00000000, 0x800B0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_60) {
  float res = 6.76729E-11;
  float out = -1234567;
  s21_decimal inp = {{0x000A5379, 0x00000000, 0x00000000, 0x00100000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_61) {
  float res = -1.56421E+08;
  float out = 1234567;
  s21_decimal inp = {{0x0952CB88, 0x00000000, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_62) {
  float res = 1.248784E-11;
  float out = -1234567;
  s21_decimal inp = {{0x00130E10, 0x00000000, 0x00000000, 0x00110000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_63) {
  float res = 4E-28;
  float out = -1234567;
  s21_decimal inp = {{0x00000004, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_64) {
  float res = -7.518575E+13;
  float out = 1234567;
  s21_decimal inp = {{0x8BEBC180, 0x00004461, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_65) {
  float res = 1.759471E+20;
  float out = -1234567;
  s21_decimal inp = {{0x0821C000, 0x89C1AB3E, 0x00000009, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_66) {
  float res = -1.730171E+16;
  float out = 1234567;
  s21_decimal inp = {{0x468E8C00, 0x003D77D0, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_67) {
  float res = -0.005833615;
  float out = 1234567;
  s21_decimal inp = {{0x0059038F, 0x00000000, 0x00000000, 0x80090000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_68) {
  float res = -1.083782E+27;
  float out = 1234567;
  s21_decimal inp = {{0x27C00000, 0xF1EDC3B6, 0x03807BC3, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_69) {
  float res = -2.543952E+11;
  float out = 1234567;
  s21_decimal inp = {{0x3B22B200, 0x0000003B, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_70) {
  float res = 8.122079E+09;
  float out = -1234567;
  s21_decimal inp = {{0xE41D1718, 0x00000001, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_71) {
  float res = -1.381688E-13;
  float out = 1234567;
  s21_decimal inp = {{0x00151538, 0x00000000, 0x00000000, 0x80130000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_72) {
  float res = 5.3419E+17;
  float out = -1234567;
  s21_decimal inp = {{0x8890E000, 0x0769D2F9, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_73) {
  float res = -1.899235E+25;
  float out = -1234567;
  s21_decimal inp = {{0xD8B80000, 0x5B459112, 0x000FB5C9, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_74) {
  float res = 0.01434358;
  float out = -1234567;
  s21_decimal inp = {{0x0015E2F6, 0x00000000, 0x00000000, 0x00080000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_75) {
  float res = -8.395913E+08;
  float out = 1234567;
  s21_decimal inp = {{0x320B2584, 0x00000000, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_76) {
  float res = 2.963941E-09;
  float out = -1234567;
  s21_decimal inp = {{0x002D39E5, 0x00000000, 0x00000000, 0x000F0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_77) {
  float res = -4.555E-25;
  float out = 1234567;
  s21_decimal inp = {{0x000011CB, 0x00000000, 0x00000000, 0x801C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_78) {
  float res = 1.511913E-20;
  float out = -1234567;
  s21_decimal inp = {{0x001711E9, 0x00000000, 0x00000000, 0x001A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_79) {
  float res = 12.18852;
  float out = -1234567;
  s21_decimal inp = {{0x00129924, 0x00000000, 0x00000000, 0x00050000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_80) {
  float res = 8.216155E-11;
  float out = -1234567;
  s21_decimal inp = {{0x007D5E5B, 0x00000000, 0x00000000, 0x00110000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_81) {
  float res = -0.7325138;
  float out = 1234567;
  s21_decimal inp = {{0x006FC5D2, 0x00000000, 0x00000000, 0x80070000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_82) {
  float res = 49394.41;
  float out = -1234567;
  s21_decimal inp = {{0x004B5EB1, 0x00000000, 0x00000000, 0x00020000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_83) {
  float res = 0.0002621874;
  float out = -1234567;
  s21_decimal inp = {{0x002801B2, 0x00000000, 0x00000000, 0x000A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_84) {
  float res = 5.880856E+15;
  float out = -1234567;
  s21_decimal inp = {{0x7CDAF000, 0x0014E49B, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_85) {
  float res = -7.0487E-24;
  float out = 1234567;
  s21_decimal inp = {{0x00011357, 0x00000000, 0x00000000, 0x801C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_86) {
  float res = 1.661392E-16;
  float out = -1234567;
  s21_decimal inp = {{0x001959D0, 0x00000000, 0x00000000, 0x00160000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_87) {
  float res = -3.749618E-17;
  float out = 1234567;
  s21_decimal inp = {{0x003936F2, 0x00000000, 0x00000000, 0x80170000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_88) {
  float res = -1.078071E+10;
  float out = 1234567;
  s21_decimal inp = {{0x82949470, 0x00000002, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_89) {
  float res = -942.165;
  float out = 1234567;
  s21_decimal inp = {{0x000E6055, 0x00000000, 0x00000000, 0x80030000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_90) {
  float res = 8.128622E+24;
  float out = -1234567;
  s21_decimal inp = {{0x0CF80000, 0x7B4932DD, 0x0006B94D, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_91) {
  float res = 3.478075E-10;
  float out = -1234567;
  s21_decimal inp = {{0x0035123B, 0x00000000, 0x00000000, 0x00100000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_92) {
  float res = -0.2220105;
  float out = 1234567;
  s21_decimal inp = {{0x0021E049, 0x00000000, 0x00000000, 0x80070000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_93) {
  float res = -4.057507E-11;
  float out = 1234567;
  s21_decimal inp = {{0x003DE9A3, 0x00000000, 0x00000000, 0x80110000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_94) {
  float res = -7.703651E+13;
  float out = 1234567;
  s21_decimal inp = {{0x75D03380, 0x00004610, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_95) {
  float res = 4.329224E-09;
  float out = -1234567;
  s21_decimal inp = {{0x00420F08, 0x00000000, 0x00000000, 0x000F0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_96) {
  float res = -3.238849E-06;
  float out = 1234567;
  s21_decimal inp = {{0x00316BC1, 0x00000000, 0x00000000, 0x800C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_97) {
  float res = -5.937755E-18;
  float out = 1234567;
  s21_decimal inp = {{0x005A9A5B, 0x00000000, 0x00000000, 0x80180000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_98) {
  float res = 9.214601E-09;
  float out = -1234567;
  s21_decimal inp = {{0x008C9A89, 0x00000000, 0x00000000, 0x000F0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_99) {
  float res = -2.788572E+14;
  float out = 1234567;
  s21_decimal inp = {{0x80595C00, 0x0000FD9E, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_100) {
  float res = -0.2386963;
  float out = 1234567;
  s21_decimal inp = {{0x00246C13, 0x00000000, 0x00000000, 0x80070000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_101) {
  float res = -4.803305E-20;
  float out = 1234567;
  s21_decimal inp = {{0x00494AE9, 0x00000000, 0x00000000, 0x801A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_102) {
  float res = -6.715998E+27;
  float out = 1234567;
  s21_decimal inp = {{0xFEC00000, 0x19B4CE7F, 0x15B357E5, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_103) {
  float res = 1.001074E+27;
  float out = -1234567;
  s21_decimal inp = {{0xE3400000, 0x47EB885C, 0x033C11AA, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_104) {
  float res = 1.061498E+12;
  float out = -1234567;
  s21_decimal inp = {{0x26361280, 0x000000F7, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_105) {
  float res = -5.398762E+13;
  float out = 1234567;
  s21_decimal inp = {{0xF8E99100, 0x00003119, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_106) {
  float res = 2.011937E-05;
  float out = -1234567;
  s21_decimal inp = {{0x001EB321, 0x00000000, 0x00000000, 0x000B0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_107) {
  float res = 1.208047E+28;
  float out = -1234567;
  s21_decimal inp = {{0xE9C00000, 0xEEAB1663, 0x2708BB06, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_108) {
  float res = -3.577309;
  float out = 1234567;
  s21_decimal inp = {{0x003695DD, 0x00000000, 0x00000000, 0x80060000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_109) {
  float res = -0.01349936;
  float out = 1234567;
  s21_decimal inp = {{0x00149930, 0x00000000, 0x00000000, 0x80080000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_110) {
  float res = 2.636795E+21;
  float out = -1234567;
  s21_decimal inp = {{0x4E1F8000, 0xF0E1AA29, 0x0000008E, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_111) {
  float res = 1.886762E+28;
  float out = -1234567;
  s21_decimal inp = {{0xBE800000, 0xAE79E847, 0x3CF6EDF1, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_112) {
  float res = 1.13723E+20;
  float out = -1234567;
  s21_decimal inp = {{0xED5C4000, 0x2A377B38, 0x00000006, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-5);
  // ck_assert_float_eq_tol(out, res, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST
// 0xED5C4000, 0x2A377B38, 0x00000006
// 6
// 3042035557742690304
// 1.137225e20
START_TEST(decimal_to_float_113) {
  float res = 2.03361E-23;
  float out = -1234567;
  s21_decimal inp = {{0x00031A61, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_114) {
  float res = -3.082871E+14;
  float out = 1234567;
  s21_decimal inp = {{0xAF159700, 0x00011862, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_115) {
  float res = -4.087111E-10;
  float out = 1234567;
  s21_decimal inp = {{0x003E5D47, 0x00000000, 0x00000000, 0x80100000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_116) {
  float res = -1.082272E+23;
  float out = 1234567;
  s21_decimal inp = {{0x14400000, 0x021DDBB8, 0x000016EB, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_117) {
  float res = -9.243464E-20;
  float out = 1234567;
  s21_decimal inp = {{0x008D0B48, 0x00000000, 0x00000000, 0x801A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_118) {
  float res = -1.351883E-11;
  float out = 1234567;
  s21_decimal inp = {{0x0014A0CB, 0x00000000, 0x00000000, 0x80110000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_119) {
  float res = 1.0670360E+22;
  float out = -1234567;
  s21_decimal inp = {{0x811C0000, 0x70FDEE02, 0x00000242, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  // ck_assert_float_eq_tol(out, res, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_120) {
  float res = -1.655359E-07;
  float out = 1234567;
  s21_decimal inp = {{0x0019423F, 0x00000000, 0x00000000, 0x800D0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_121) {
  float res = -2.818527E-09;
  float out = 1234567;
  s21_decimal inp = {{0x002B01DF, 0x00000000, 0x00000000, 0x800F0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_122) {
  float res = 2.02466E-23;
  float out = -1234567;
  s21_decimal inp = {{0x000316E2, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_123) {
  float res = 2.310628E-10;
  float out = -1234567;
  s21_decimal inp = {{0x002341E4, 0x00000000, 0x00000000, 0x00100000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_124) {
  float res = 2968.287;
  float out = -1234567;
  s21_decimal inp = {{0x002D4ADF, 0x00000000, 0x00000000, 0x00030000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_125) {
  float res = 1.229755E-18;
  float out = -1234567;
  s21_decimal inp = {{0x0012C3BB, 0x00000000, 0x00000000, 0x00180000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_126) {
  float res = 1.059234E-14;
  float out = -1234567;
  s21_decimal inp = {{0x001029A2, 0x00000000, 0x00000000, 0x00140000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_127) {
  float res = -64208.49;
  float out = 1234567;
  s21_decimal inp = {{0x0061F971, 0x00000000, 0x00000000, 0x80020000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_128) {
  float res = 2.186795E+15;
  float out = -1234567;
  s21_decimal inp = {{0xE32BEE00, 0x0007C4E0, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_129) {
  float res = -2.191804E+07;
  float out = 1234567;
  s21_decimal inp = {{0x014E7158, 0x00000000, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_130) {
  float res = 6.5419E-24;
  float out = -1234567;
  s21_decimal inp = {{0x0000FF8B, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_131) {
  float res = -1.152604E+26;
  float out = 1234567;
  s21_decimal inp = {{0xF9C00000, 0xCDD8046A, 0x005F5756, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_132) {
  float res = 6.767653E+21;
  float out = -1234567;
  s21_decimal inp = {{0x0AB08000, 0xE00D62F0, 0x0000016E, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_133) {
  float res = -4.926002E+14;
  float out = 1234567;
  s21_decimal inp = {{0x6BEFF200, 0x0001C004, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_134) {
  float res = 1.194919E+26;
  float out = -1234567;
  s21_decimal inp = {{0x4F700000, 0xE0F3DC90, 0x0062D764, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_135) {
  float res = 0.2616035;
  float out = -1234567;
  s21_decimal inp = {{0x0027EAE3, 0x00000000, 0x00000000, 0x00070000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_136) {
  float res = -2.989957E+13;
  float out = 1234567;
  s21_decimal inp = {{0x893FB080, 0x00001B31, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_137) {
  float res = -4.6185E-24;
  float out = 1234567;
  s21_decimal inp = {{0x0000B469, 0x00000000, 0x00000000, 0x801C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_138) {
  float res = -0.003898347;
  float out = 1234567;
  s21_decimal inp = {{0x003B7BEB, 0x00000000, 0x00000000, 0x80090000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_139) {
  float res = 11.08692;
  float out = -1234567;
  s21_decimal inp = {{0x0010EAD4, 0x00000000, 0x00000000, 0x00050000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_140) {
  float res = -0.003970314;
  float out = 1234567;
  s21_decimal inp = {{0x003C950A, 0x00000000, 0x00000000, 0x80090000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_141) {
  float res = 1.054338E-15;
  float out = -1234567;
  s21_decimal inp = {{0x00101682, 0x00000000, 0x00000000, 0x00150000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_142) {
  float res = -32.53767;
  float out = 1234567;
  s21_decimal inp = {{0x0031A607, 0x00000000, 0x00000000, 0x80050000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_143) {
  float res = 0.06596097;
  float out = -1234567;
  s21_decimal inp = {{0x0064A601, 0x00000000, 0x00000000, 0x00080000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_144) {
  float res = 8.861377E+25;
  float out = -1234567;
  s21_decimal inp = {{0xE7E80000, 0x18E914DA, 0x00494CB2, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_145) {
  float res = 2.0E-28;
  float out = -1234567;
  s21_decimal inp = {{0x00000002, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_146) {
  float res = 3191.227;
  float out = -1234567;
  s21_decimal inp = {{0x0030B1BB, 0x00000000, 0x00000000, 0x00030000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_147) {
  float res = 0.938446;
  float out = -1234567;
  s21_decimal inp = {{0x000E51CE, 0x00000000, 0x00000000, 0x00060000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_148) {
  float res = -3.894784E-17;
  float out = 1234567;
  s21_decimal inp = {{0x003B6E00, 0x00000000, 0x00000000, 0x80170000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_149) {
  float res = 7.679175E+14;
  float out = -1234567;
  s21_decimal inp = {{0xB9CDE700, 0x0002BA6A, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_150) {
  float res = 9.389545E+08;
  float out = -1234567;
  s21_decimal inp = {{0x37F74F04, 0x00000000, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_151) {
  float res = -8.570058E+07;
  float out = 1234567;
  s21_decimal inp = {{0x051BAFE4, 0x00000000, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_152) {
  float res = 1.069406E-20;
  float out = -1234567;
  s21_decimal inp = {{0x0010515E, 0x00000000, 0x00000000, 0x001A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_153) {
  float res = 1963320;
  float out = -1234567;
  s21_decimal inp = {{0x001DF538, 0x00000000, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_154) {
  float res = 1631.409;
  float out = -1234567;
  s21_decimal inp = {{0x0018E4B1, 0x00000000, 0x00000000, 0x00030000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_155) {
  float res = -9.583782E-09;
  float out = 1234567;
  s21_decimal inp = {{0x00923CA6, 0x00000000, 0x00000000, 0x800F0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_156) {
  float res = 4.934571E+14;
  float out = -1234567;
  s21_decimal inp = {{0xEF284B00, 0x0001C0CB, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_157) {
  float res = 10.23795;
  float out = -1234567;
  s21_decimal inp = {{0x000F9F33, 0x00000000, 0x00000000, 0x00050000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_158) {
  float res = -703088.8;
  float out = 1234567;
  s21_decimal inp = {{0x006B4868, 0x00000000, 0x00000000, 0x80010000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_159) {
  float res = -1.061253E+17;
  float out = 1234567;
  s21_decimal inp = {{0xE82E8800, 0x01790865, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_160) {
  float res = 0.0001655871;
  float out = -1234567;
  s21_decimal inp = {{0x0019443F, 0x00000000, 0x00000000, 0x000A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_161) {
  float res = -158.45;
  float out = 1234567;
  s21_decimal inp = {{0x00003DE5, 0x00000000, 0x00000000, 0x80020000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_162) {
  float res = 2.961945E+11;
  float out = 1234567;
  s21_decimal inp = {{0xF69165A0, 0x00000044, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_163) {
  float res = -1.62E-26;
  float out = 1234567;
  s21_decimal inp = {{0x000000A2, 0x00000000, 0x00000000, 0x801C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_164) {
  float res = -212.0078;
  float out = 1234567;
  s21_decimal inp = {{0x0020598E, 0x00000000, 0x00000000, 0x80040000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_165) {
  float res = 1.683534E-20;
  float out = -1234567;
  s21_decimal inp = {{0x0019B04E, 0x00000000, 0x00000000, 0x001A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_166) {
  float res = 1.360221E+25;
  float out = -1234567;
  s21_decimal inp = {{0x01480000, 0x4818EABE, 0x000B4061, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_167) {
  float res = 4.304772E-15;
  float out = -1234567;
  s21_decimal inp = {{0x0041AF84, 0x00000000, 0x00000000, 0x00150000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_168) {
  float res = 2.341019E+14;
  float out = -1234567;
  s21_decimal inp = {{0x18973B00, 0x0000D4EA, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_169) {
  float res = 2.241625E-06;
  float out = -1234567;
  s21_decimal inp = {{0x00223459, 0x00000000, 0x00000000, 0x000C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_170) {
  float res = -1.3E-27;
  float out = 1234567;
  s21_decimal inp = {{0x0000000D, 0x00000000, 0x00000000, 0x801C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_171) {
  float res = 3E-28;
  float out = -1234567;
  s21_decimal inp = {{0x00000003, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_172) {
  float res = -6.89053E+23;
  float out = 1234567;
  s21_decimal inp = {{0xD4540000, 0xA35284BD, 0x000091E9, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_173) {
  float res = -1.335107E-17;
  float out = 1234567;
  s21_decimal inp = {{0x00145F43, 0x00000000, 0x00000000, 0x80170000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_174) {
  float res = 4.299471E+28;
  float out = -1234567;
  s21_decimal inp = {{0xA1C00000, 0x5E84AF70, 0x8AEC63FB, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_175) {
  float res = 5.439797E-13;
  float out = -1234567;
  s21_decimal inp = {{0x00530135, 0x00000000, 0x00000000, 0x00130000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_176) {
  float res = 9283997;
  float out = -1234567;
  s21_decimal inp = {{0x008DA99D, 0x00000000, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_177) {
  float res = -5.917783E-20;
  float out = 1234567;
  s21_decimal inp = {{0x005A4C57, 0x00000000, 0x00000000, 0x801A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_178) {
  float res = -4.605351E-08;
  float out = 1234567;
  s21_decimal inp = {{0x004645A7, 0x00000000, 0x00000000, 0x800E0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_179) {
  float res = 3.67147E-07;
  float out = -1234567;
  s21_decimal inp = {{0x00059A2B, 0x00000000, 0x00000000, 0x000C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_180) {
  float res = 7.805752E-14;
  float out = -1234567;
  s21_decimal inp = {{0x00771B38, 0x00000000, 0x00000000, 0x00140000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_181) {
  float res = -5E-28;
  float out = 1234567;
  s21_decimal inp = {{0x00000005, 0x00000000, 0x00000000, 0x801C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_182) {
  float res = 1.029686E+16;
  float out = -1234567;
  s21_decimal inp = {{0x8A9A1800, 0x002494F0, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_183) {
  float res = -1.623241E+11;
  float out = 1234567;
  s21_decimal inp = {{0xCB4533A0, 0x00000025, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_184) {
  float res = 0.01401084;
  float out = -1234567;
  s21_decimal inp = {{0x001560FC, 0x00000000, 0x00000000, 0x00080000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_185) {
  float res = 16.07887;
  float out = -1234567;
  s21_decimal inp = {{0x001888CF, 0x00000000, 0x00000000, 0x00050000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_186) {
  float res = -2.094895E+21;
  float out = 1234567;
  s21_decimal inp = {{0x45F18000, 0x90821F45, 0x00000071, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_187) {
  float res = -4.274481E-16;
  float out = 1234567;
  s21_decimal inp = {{0x00413931, 0x00000000, 0x00000000, 0x80160000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_188) {
  float res = 7.869093E+14;
  float out = -1234567;
  s21_decimal inp = {{0x994C0500, 0x0002CBB0, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_189) {
  float res = -1.272028E-09;
  float out = 1234567;
  s21_decimal inp = {{0x001368DC, 0x00000000, 0x00000000, 0x800F0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_190) {
  float res = -5.217951E-12;
  float out = 1234567;
  s21_decimal inp = {{0x004F9E9F, 0x00000000, 0x00000000, 0x80120000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_191) {
  float res = -386648.3;
  float out = 1234567;
  s21_decimal inp = {{0x003AFF73, 0x00000000, 0x00000000, 0x80010000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_192) {
  float res = 3.61813E+09;
  float out = -1234567;
  s21_decimal inp = {{0xD7A84850, 0x00000000, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_193) {
  float res = -109.3412;
  float out = 1234567;
  s21_decimal inp = {{0x0010AF24, 0x00000000, 0x00000000, 0x80040000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_194) {
  float res = 4.581238E+18;
  float out = -1234567;
  s21_decimal inp = {{0x45856000, 0x3F93D3B0, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_195) {
  float res = -6.603116E-17;
  float out = 1234567;
  s21_decimal inp = {{0x0064C16C, 0x00000000, 0x00000000, 0x80170000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_196) {
  float res = -1.320119E+10;
  float out = 1234567;
  s21_decimal inp = {{0x12DA2C70, 0x00000003, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_197) {
  float res = 2.82232E-12;
  float out = -1234567;
  s21_decimal inp = {{0x00044E78, 0x00000000, 0x00000000, 0x00110000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_198) {
  float res = -1841507000;
  float out = 1234567;
  s21_decimal inp = {{0x6DC32AB8, 0x00000000, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_199) {
  float res = -2.262675E-19;
  float out = 1234567;
  s21_decimal inp = {{0x00228693, 0x00000000, 0x00000000, 0x80190000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_200) {
  float res = 2.464824E-20;
  float out = -1234567;
  s21_decimal inp = {{0x00259C38, 0x00000000, 0x00000000, 0x001A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_201) {
  float res = 1.511738E-07;
  float out = -1234567;
  s21_decimal inp = {{0x0017113A, 0x00000000, 0x00000000, 0x000D0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_202) {
  float res = 1.720869E-06;
  float out = -1234567;
  s21_decimal inp = {{0x001A4225, 0x00000000, 0x00000000, 0x000C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_203) {
  float res = 8.2E-27;
  float out = -1234567;
  s21_decimal inp = {{0x00000052, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_204) {
  float res = -10.51995;
  float out = 1234567;
  s21_decimal inp = {{0x00100D5B, 0x00000000, 0x00000000, 0x80050000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_205) {
  float res = 1.603923E+24;
  float out = -1234567;
  s21_decimal inp = {{0x896C0000, 0xD70DD7BD, 0x000153A4, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_206) {
  float res = 119471.1;
  float out = -1234567;
  s21_decimal inp = {{0x00123AD7, 0x00000000, 0x00000000, 0x00010000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_207) {
  float res = 6.965003E+25;
  float out = -1234567;
  s21_decimal inp = {{0x44F80000, 0xB125DD81, 0x00399CF7, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_208) {
  float res = 1.296483E+17;
  float out = -1234567;
  s21_decimal inp = {{0x233BB800, 0x01CC9A71, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_209) {
  float res = -5.872053E+13;
  float out = 1234567;
  s21_decimal inp = {{0xF054E880, 0x00003567, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_210) {
  float res = -1.481293E+23;
  float out = 1234567;
  s21_decimal inp = {{0x26820000, 0x1AFE5755, 0x00001F5E, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_211) {
  float res = -2.851002E-18;
  float out = 1234567;
  s21_decimal inp = {{0x002B80BA, 0x00000000, 0x00000000, 0x80180000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_212) {
  float res = 112195.3;
  float out = -1234567;
  s21_decimal inp = {{0x00111EA1, 0x00000000, 0x00000000, 0x00010000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_213) {
  float res = 1.039634E+08;
  float out = -1234567;
  s21_decimal inp = {{0x06325B08, 0x00000000, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_214) {
  float res = 3.406830E+13;
  float out = -1234567;
  s21_decimal inp = {{0x24EB6B00, 0x00001EFC, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_215) {
  float res = 6.772869E+11;
  float out = -1234567;
  s21_decimal inp = {{0xB171F120, 0x0000009D, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_216) {
  float res = -1.268637E+15;
  float out = 1234567;
  s21_decimal inp = {{0x91BBE200, 0x000481D1, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_217) {
  float res = -0.001798262;
  float out = 1234567;
  s21_decimal inp = {{0x001B7076, 0x00000000, 0x00000000, 0x80090000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_218) {
  float res = -3.38201E-15;
  float out = 1234567;
  s21_decimal inp = {{0x00052919, 0x00000000, 0x00000000, 0x80140000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_219) {
  float res = -3.263142E-13;
  float out = 1234567;
  s21_decimal inp = {{0x0031CAA6, 0x00000000, 0x00000000, 0x80130000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_220) {
  float res = 1.2E-27;
  float out = -1234567;
  s21_decimal inp = {{0x0000000C, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_221) {
  float res = 3.812988E+22;
  float out = -1234567;
  s21_decimal inp = {{0xCF7C0000, 0x06623F3C, 0x00000813, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_222) {
  float res = 3.308621E+16;
  float out = -1234567;
  s21_decimal inp = {{0x92039400, 0x00758BBB, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_223) {
  float res = -1.322553E-20;
  float out = 1234567;
  s21_decimal inp = {{0x00142E39, 0x00000000, 0x00000000, 0x801A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_224) {
  float res = 1.148738E+08;
  float out = -1234567;
  s21_decimal inp = {{0x06D8D5C8, 0x00000000, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_225) {
  float res = -1.991151E+10;
  float out = 1234567;
  s21_decimal inp = {{0xA2D187F0, 0x00000004, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_226) {
  float res = 884496.5;
  float out = -1234567;
  s21_decimal inp = {{0x0086F6A5, 0x00000000, 0x00000000, 0x00010000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_227) {
  float res = 4.1E-27;
  float out = -1234567;
  s21_decimal inp = {{0x00000029, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_228) {
  float res = 4.65E-26;
  float out = -1234567;
  s21_decimal inp = {{0x000001D1, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_229) {
  float res = 9.713084E+17;
  float out = -1234567;
  s21_decimal inp = {{0xF55A6000, 0x0D7AC7D7, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_230) {
  float res = -2.557154E+19;
  float out = 1234567;
  s21_decimal inp = {{0x6BB14000, 0x62E05C25, 0x00000001, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_231) {
  float res = -0.6512141;
  float out = 1234567;
  s21_decimal inp = {{0x00635E0D, 0x00000000, 0x00000000, 0x80070000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_232) {
  float res = 3.490169E+16;
  float out = -1234567;
  s21_decimal inp = {{0xF282C400, 0x007BFEE6, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_233) {
  float res = 5.061718E-20;
  float out = -1234567;
  s21_decimal inp = {{0x004D3C56, 0x00000000, 0x00000000, 0x001A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_234) {
  float res = 6.59684E+22;
  float out = -1234567;
  s21_decimal inp = {{0xEEE80000, 0x27750C6F, 0x00000DF8, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_235) {
  float res = -1.918654E-19;
  float out = 1234567;
  s21_decimal inp = {{0x001D46BE, 0x00000000, 0x00000000, 0x80190000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_236) {
  float res = -1.215304E-18;
  float out = 1234567;
  s21_decimal inp = {{0x00128B48, 0x00000000, 0x00000000, 0x80180000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_237) {
  float res = -3.20701E-15;
  float out = 1234567;
  s21_decimal inp = {{0x0004E4BD, 0x00000000, 0x00000000, 0x80140000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_238) {
  float res = -2.55141E+17;
  float out = 1234567;
  s21_decimal inp = {{0x40A35000, 0x038A7163, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_239) {
  float res = -1.751754E+22;
  float out = 1234567;
  s21_decimal inp = {{0x684A0000, 0xA0B3FA18, 0x000003B5, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_240) {
  float res = -1.188452E+26;
  float out = 1234567;
  s21_decimal inp = {{0xD2400000, 0x3393C802, 0x00624E73, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_241) {
  float res = 3.867E-25;
  float out = -1234567;
  s21_decimal inp = {{0x00000F1B, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  // ck_assert_float_eq(out, res);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_242) {
  float res = 44301.02;
  float out = -1234567;
  s21_decimal inp = {{0x00439916, 0x00000000, 0x00000000, 0x00020000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_243) {
  float res = 2.48E-26;
  float out = -1234567;
  s21_decimal inp = {{0x000000F8, 0x00000000, 0x00000000, 0x001C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_244) {
  float res = -3.094722E-11;
  float out = 1234567;
  s21_decimal inp = {{0x002F38C2, 0x00000000, 0x00000000, 0x80110000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_245) {
  float res = -0.0001411886;
  float out = 1234567;
  s21_decimal inp = {{0x00158B2E, 0x00000000, 0x00000000, 0x800A0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  // ck_assert_float_eq(out, res);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_246) {
  float res = 4.721357E-18;
  float out = -1234567;
  s21_decimal inp = {{0x00480ACD, 0x00000000, 0x00000000, 0x00180000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_247) {
  float res = -62473980000;  //-6.247398E+10; //62473980000
  float out = 1234567;
  s21_decimal inp = {{0x8BBD4860, 0x0000000E, 0x00000000, 0x80000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_248) {
  float res = -1.663049E-18;
  float out = 1234567;
  s21_decimal inp = {{0x00196049, 0x00000000, 0x00000000, 0x80180000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out, res, 1e-17);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_249) {
  float res = 4.894282E+14;
  float out = -1234567;
  s21_decimal inp = {{0xE2010A00, 0x0001BD21, 0x00000000, 0x00000000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(decimal_to_float_250) {
  float res = 7.748195E-06;
  float out = -1234567;
  s21_decimal inp = {{0x00763A63, 0x00000000, 0x00000000, 0x000C0000}};
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq_tol(out / res, 1, 1e-6);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(dc_to_fl_1) {
  float number = 1.0;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-7);
}
END_TEST
START_TEST(dc_to_fl_2) {
  float number = 0.1;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-1);
}
END_TEST
START_TEST(dc_to_fl_3) {
  float number = -0.1;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-1);
}
END_TEST
START_TEST(dc_to_fl_4) {
  float number = 0.0;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-7);
}
END_TEST
START_TEST(dc_to_fl_5) {
  float number = 0.0123456789;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-7);
}
END_TEST

Suite *suite_decimal_to_float(void) {
  Suite *s = suite_create("\033[45mS21_FROM_DECIMAL_TO_FLOAT\033[0m");
  TCase *tc = tcase_create("s21_from_decimal_to_float_tc");

  tcase_add_test(tc, decimal_to_float_0);
  tcase_add_test(tc, decimal_to_float_1);
  tcase_add_test(tc, decimal_to_float_2);
  tcase_add_test(tc, decimal_to_float_3);
  tcase_add_test(tc, decimal_to_float_4);
  tcase_add_test(tc, decimal_to_float_5);
  tcase_add_test(tc, decimal_to_float_6);
  tcase_add_test(tc, decimal_to_float_7);
  tcase_add_test(tc, decimal_to_float_8);
  tcase_add_test(tc, decimal_to_float_9);
  tcase_add_test(tc, decimal_to_float_10);
  tcase_add_test(tc, decimal_to_float_10_5);
  tcase_add_test(tc, decimal_to_float_11);
  tcase_add_test(tc, decimal_to_float_12);
  tcase_add_test(tc, decimal_to_float_13);
  tcase_add_test(tc, decimal_to_float_14);
  tcase_add_test(tc, decimal_to_float_15);
  tcase_add_test(tc, decimal_to_float_16);
  tcase_add_test(tc, decimal_to_float_17);
  tcase_add_test(tc, decimal_to_float_18);
  tcase_add_test(tc, decimal_to_float_19);
  tcase_add_test(tc, decimal_to_float_20);
  tcase_add_test(tc, decimal_to_float_21);
  tcase_add_test(tc, decimal_to_float_22);
  tcase_add_test(tc, decimal_to_float_23);
  tcase_add_test(tc, decimal_to_float_24);
  tcase_add_test(tc, decimal_to_float_25);
  tcase_add_test(tc, decimal_to_float_26);
  tcase_add_test(tc, decimal_to_float_27);
  tcase_add_test(tc, decimal_to_float_29);
  tcase_add_test(tc, decimal_to_float_30);
  tcase_add_test(tc, decimal_to_float_31);
  tcase_add_test(tc, decimal_to_float_32);
  tcase_add_test(tc, decimal_to_float_33);
  tcase_add_test(tc, decimal_to_float_34);
  tcase_add_test(tc, decimal_to_float_35);
  tcase_add_test(tc, decimal_to_float_36);
  tcase_add_test(tc, decimal_to_float_37);
  tcase_add_test(tc, decimal_to_float_38);
  tcase_add_test(tc, decimal_to_float_39);
  tcase_add_test(tc, decimal_to_float_40);
  tcase_add_test(tc, decimal_to_float_41);
  tcase_add_test(tc, decimal_to_float_42);
  tcase_add_test(tc, decimal_to_float_43);
  tcase_add_test(tc, decimal_to_float_44);
  tcase_add_test(tc, decimal_to_float_45);
  tcase_add_test(tc, decimal_to_float_46);
  tcase_add_test(tc, decimal_to_float_47);
  tcase_add_test(tc, decimal_to_float_48);
  tcase_add_test(tc, decimal_to_float_49);
  tcase_add_test(tc, decimal_to_float_50);
  tcase_add_test(tc, decimal_to_float_51);
  tcase_add_test(tc, decimal_to_float_52);
  tcase_add_test(tc, decimal_to_float_53);
  tcase_add_test(tc, decimal_to_float_54);
  tcase_add_test(tc, decimal_to_float_55);
  tcase_add_test(tc, decimal_to_float_56);
  tcase_add_test(tc, decimal_to_float_57);
  tcase_add_test(tc, decimal_to_float_58);
  tcase_add_test(tc, decimal_to_float_59);
  tcase_add_test(tc, decimal_to_float_60);
  tcase_add_test(tc, decimal_to_float_61);
  tcase_add_test(tc, decimal_to_float_62);
  tcase_add_test(tc, decimal_to_float_63);
  tcase_add_test(tc, decimal_to_float_64);
  tcase_add_test(tc, decimal_to_float_65);
  tcase_add_test(tc, decimal_to_float_66);
  tcase_add_test(tc, decimal_to_float_67);
  tcase_add_test(tc, decimal_to_float_68);
  tcase_add_test(tc, decimal_to_float_69);
  tcase_add_test(tc, decimal_to_float_70);
  tcase_add_test(tc, decimal_to_float_71);
  tcase_add_test(tc, decimal_to_float_72);
  tcase_add_test(tc, decimal_to_float_73);
  tcase_add_test(tc, decimal_to_float_74);
  tcase_add_test(tc, decimal_to_float_75);
  tcase_add_test(tc, decimal_to_float_76);
  tcase_add_test(tc, decimal_to_float_77);
  tcase_add_test(tc, decimal_to_float_78);
  tcase_add_test(tc, decimal_to_float_79);
  tcase_add_test(tc, decimal_to_float_80);
  tcase_add_test(tc, decimal_to_float_81);
  tcase_add_test(tc, decimal_to_float_82);
  tcase_add_test(tc, decimal_to_float_83);
  tcase_add_test(tc, decimal_to_float_84);
  tcase_add_test(tc, decimal_to_float_85);
  tcase_add_test(tc, decimal_to_float_86);
  tcase_add_test(tc, decimal_to_float_87);
  tcase_add_test(tc, decimal_to_float_88);
  tcase_add_test(tc, decimal_to_float_89);
  tcase_add_test(tc, decimal_to_float_90);
  tcase_add_test(tc, decimal_to_float_91);
  tcase_add_test(tc, decimal_to_float_92);
  tcase_add_test(tc, decimal_to_float_93);
  tcase_add_test(tc, decimal_to_float_94);
  tcase_add_test(tc, decimal_to_float_95);
  tcase_add_test(tc, decimal_to_float_96);
  tcase_add_test(tc, decimal_to_float_97);
  tcase_add_test(tc, decimal_to_float_98);
  tcase_add_test(tc, decimal_to_float_99);
  tcase_add_test(tc, decimal_to_float_100);
  tcase_add_test(tc, decimal_to_float_101);
  tcase_add_test(tc, decimal_to_float_102);
  tcase_add_test(tc, decimal_to_float_103);
  tcase_add_test(tc, decimal_to_float_104);
  tcase_add_test(tc, decimal_to_float_105);
  tcase_add_test(tc, decimal_to_float_106);
  tcase_add_test(tc, decimal_to_float_107);
  tcase_add_test(tc, decimal_to_float_108);
  tcase_add_test(tc, decimal_to_float_109);
  tcase_add_test(tc, decimal_to_float_110);
  tcase_add_test(tc, decimal_to_float_111);
  tcase_add_test(tc, decimal_to_float_112);
  tcase_add_test(tc, decimal_to_float_113);
  tcase_add_test(tc, decimal_to_float_114);
  tcase_add_test(tc, decimal_to_float_115);
  tcase_add_test(tc, decimal_to_float_116);
  tcase_add_test(tc, decimal_to_float_117);
  tcase_add_test(tc, decimal_to_float_118);
  tcase_add_test(tc, decimal_to_float_119);
  tcase_add_test(tc, decimal_to_float_120);
  tcase_add_test(tc, decimal_to_float_121);
  tcase_add_test(tc, decimal_to_float_122);
  tcase_add_test(tc, decimal_to_float_123);
  tcase_add_test(tc, decimal_to_float_124);
  tcase_add_test(tc, decimal_to_float_125);
  tcase_add_test(tc, decimal_to_float_126);
  tcase_add_test(tc, decimal_to_float_127);
  tcase_add_test(tc, decimal_to_float_128);
  tcase_add_test(tc, decimal_to_float_129);
  tcase_add_test(tc, decimal_to_float_130);
  tcase_add_test(tc, decimal_to_float_131);
  tcase_add_test(tc, decimal_to_float_132);
  tcase_add_test(tc, decimal_to_float_133);
  tcase_add_test(tc, decimal_to_float_134);
  tcase_add_test(tc, decimal_to_float_135);
  tcase_add_test(tc, decimal_to_float_136);
  tcase_add_test(tc, decimal_to_float_137);
  tcase_add_test(tc, decimal_to_float_138);
  tcase_add_test(tc, decimal_to_float_139);
  tcase_add_test(tc, decimal_to_float_140);
  tcase_add_test(tc, decimal_to_float_141);
  tcase_add_test(tc, decimal_to_float_142);
  tcase_add_test(tc, decimal_to_float_143);
  tcase_add_test(tc, decimal_to_float_144);
  tcase_add_test(tc, decimal_to_float_145);
  tcase_add_test(tc, decimal_to_float_146);
  tcase_add_test(tc, decimal_to_float_147);
  tcase_add_test(tc, decimal_to_float_148);
  tcase_add_test(tc, decimal_to_float_149);
  tcase_add_test(tc, decimal_to_float_150);
  tcase_add_test(tc, decimal_to_float_151);
  tcase_add_test(tc, decimal_to_float_152);
  tcase_add_test(tc, decimal_to_float_153);
  tcase_add_test(tc, decimal_to_float_154);
  tcase_add_test(tc, decimal_to_float_155);
  tcase_add_test(tc, decimal_to_float_156);
  tcase_add_test(tc, decimal_to_float_157);
  tcase_add_test(tc, decimal_to_float_158);
  tcase_add_test(tc, decimal_to_float_159);
  tcase_add_test(tc, decimal_to_float_160);
  tcase_add_test(tc, decimal_to_float_161);
  tcase_add_test(tc, decimal_to_float_162);
  tcase_add_test(tc, decimal_to_float_163);
  tcase_add_test(tc, decimal_to_float_164);
  tcase_add_test(tc, decimal_to_float_165);
  tcase_add_test(tc, decimal_to_float_166);
  tcase_add_test(tc, decimal_to_float_167);
  tcase_add_test(tc, decimal_to_float_168);
  tcase_add_test(tc, decimal_to_float_169);
  tcase_add_test(tc, decimal_to_float_170);
  tcase_add_test(tc, decimal_to_float_171);
  tcase_add_test(tc, decimal_to_float_172);
  tcase_add_test(tc, decimal_to_float_173);
  tcase_add_test(tc, decimal_to_float_174);
  tcase_add_test(tc, decimal_to_float_175);
  tcase_add_test(tc, decimal_to_float_176);
  tcase_add_test(tc, decimal_to_float_177);
  tcase_add_test(tc, decimal_to_float_178);
  tcase_add_test(tc, decimal_to_float_179);
  tcase_add_test(tc, decimal_to_float_180);
  tcase_add_test(tc, decimal_to_float_181);
  tcase_add_test(tc, decimal_to_float_182);
  tcase_add_test(tc, decimal_to_float_183);
  tcase_add_test(tc, decimal_to_float_184);
  tcase_add_test(tc, decimal_to_float_185);
  tcase_add_test(tc, decimal_to_float_186);
  tcase_add_test(tc, decimal_to_float_187);
  tcase_add_test(tc, decimal_to_float_188);
  tcase_add_test(tc, decimal_to_float_189);
  tcase_add_test(tc, decimal_to_float_190);
  tcase_add_test(tc, decimal_to_float_191);
  tcase_add_test(tc, decimal_to_float_192);
  tcase_add_test(tc, decimal_to_float_193);
  tcase_add_test(tc, decimal_to_float_194);
  tcase_add_test(tc, decimal_to_float_195);
  tcase_add_test(tc, decimal_to_float_196);
  tcase_add_test(tc, decimal_to_float_197);
  tcase_add_test(tc, decimal_to_float_198);
  tcase_add_test(tc, decimal_to_float_199);
  tcase_add_test(tc, decimal_to_float_200);
  tcase_add_test(tc, decimal_to_float_201);
  tcase_add_test(tc, decimal_to_float_202);
  tcase_add_test(tc, decimal_to_float_203);
  tcase_add_test(tc, decimal_to_float_204);
  tcase_add_test(tc, decimal_to_float_205);
  tcase_add_test(tc, decimal_to_float_206);
  tcase_add_test(tc, decimal_to_float_207);
  tcase_add_test(tc, decimal_to_float_208);
  tcase_add_test(tc, decimal_to_float_209);
  tcase_add_test(tc, decimal_to_float_210);
  tcase_add_test(tc, decimal_to_float_211);
  tcase_add_test(tc, decimal_to_float_212);
  tcase_add_test(tc, decimal_to_float_213);
  tcase_add_test(tc, decimal_to_float_214);
  tcase_add_test(tc, decimal_to_float_215);
  tcase_add_test(tc, decimal_to_float_216);
  tcase_add_test(tc, decimal_to_float_217);
  tcase_add_test(tc, decimal_to_float_218);
  tcase_add_test(tc, decimal_to_float_219);
  tcase_add_test(tc, decimal_to_float_220);
  tcase_add_test(tc, decimal_to_float_221);
  tcase_add_test(tc, decimal_to_float_222);
  tcase_add_test(tc, decimal_to_float_223);
  tcase_add_test(tc, decimal_to_float_224);
  tcase_add_test(tc, decimal_to_float_225);
  tcase_add_test(tc, decimal_to_float_226);
  tcase_add_test(tc, decimal_to_float_227);
  tcase_add_test(tc, decimal_to_float_228);
  tcase_add_test(tc, decimal_to_float_229);
  tcase_add_test(tc, decimal_to_float_230);
  tcase_add_test(tc, decimal_to_float_231);
  tcase_add_test(tc, decimal_to_float_232);
  tcase_add_test(tc, decimal_to_float_233);
  tcase_add_test(tc, decimal_to_float_234);
  tcase_add_test(tc, decimal_to_float_235);
  tcase_add_test(tc, decimal_to_float_236);
  tcase_add_test(tc, decimal_to_float_237);
  tcase_add_test(tc, decimal_to_float_238);
  tcase_add_test(tc, decimal_to_float_239);
  tcase_add_test(tc, decimal_to_float_240);
  tcase_add_test(tc, decimal_to_float_241);
  tcase_add_test(tc, decimal_to_float_242);
  tcase_add_test(tc, decimal_to_float_243);
  tcase_add_test(tc, decimal_to_float_244);
  tcase_add_test(tc, decimal_to_float_245);
  tcase_add_test(tc, decimal_to_float_246);
  tcase_add_test(tc, decimal_to_float_247);
  tcase_add_test(tc, decimal_to_float_248);
  tcase_add_test(tc, decimal_to_float_249);
  tcase_add_test(tc, decimal_to_float_250);

  tcase_add_test(tc, dc_to_fl_1);
  tcase_add_test(tc, dc_to_fl_2);
  tcase_add_test(tc, dc_to_fl_3);
  tcase_add_test(tc, dc_to_fl_4);
  tcase_add_test(tc, dc_to_fl_5);

  suite_add_tcase(s, tc);
  return s;
}