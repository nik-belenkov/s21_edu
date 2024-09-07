#include "test.h"

#define SIZE 512

START_TEST(sprintf_f0) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Hello - %f";
  float number = NAN;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f1) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%f";
  float number = INFINITY;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f2) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Hello - %f";
  float number = -INFINITY;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f3) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Hello - %F";
  float number = INFINITY;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f4) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Hello - %F";
  float number = -INFINITY;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f5) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Hello - %F";
  float number = NAN;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f6) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is %f";
  float number = 1.01;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f7) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is %+.3f";
  float number = 35.001;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f8) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is % f";
  float number = 407.001;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f9) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is %f";
  float number = -72.123456;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f10) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%15f";
  float number = 53.15;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f11) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-15f";
  float number = 53.22;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f12) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%015f";
  float number = 53.022223;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f13) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.0f = number";
  float number = 91.0035;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f14) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.3f = number";
  float number = 91.0035;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f15) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.10f = number";
  float number = 91.0035;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f16) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%Lf";
  long double number = 101.687;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f17) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%+010.1f";
  float number = 1.03;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f18) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "number one is %.*F";
  float number1 = 1001.05;
  int precision = 4;
  ck_assert_int_eq(s21_sprintf(str1, format, precision, number1),
                   sprintf(str2, format, precision, number1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f19) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Need more floats: %+7.0f %4.5f %F %f and more %10F";
  double num1 = 1001.05, num2 = -0.0007, num3 = NAN, num4 = INFINITY,
         num5 = -INFINITY;
  ck_assert_int_eq(s21_sprintf(str1, format, num1, num2, num3, num4, num5),
                   sprintf(str2, format, num1, num2, num3, num4, num5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d0) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Just %d";
  int num = 10;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d1) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%+d";
  int num = 13;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d2) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "% d flag space";
  int num = 15;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d3) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%5d";
  int num = -17;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d4) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-8d";
  int num = 305;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d5) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%012d";
  int num = 609;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d6) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%0*d";
  int num = 3109;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, num),
                   sprintf(str2, format, 5, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d7) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.*d";
  int num = 15;
  ck_assert_int_eq(s21_sprintf(str1, format, 3, num),
                   sprintf(str2, format, 3, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d8) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%+5.10ld - number";
  long int num = 906669;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d9) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-16.9hd";
  short int num = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d10) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "it is %8.*ld";
  long num = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, num),
                   sprintf(str2, format, 5, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d11) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.0d";
  int num = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d12) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%05d";
  int num = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u0) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Just - %u";
  unsigned int num = 16609;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u1) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%13u";
  unsigned int num = 16609;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u2) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-16u";
  unsigned int num = 16609;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u3) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.5u";
  unsigned int num = 16609;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u4) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "% 5.5u";
  unsigned int num = 16609;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u5) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%hu";
  unsigned short int num = 16609;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u6) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%lu";
  unsigned long int num = 956710088001;
  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u7) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int num = 949149188001;
  ck_assert_int_eq(
      s21_sprintf(str1, format, num, 14, 1441, 14414, 9681),
      sprintf(str2, format, num, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}

START_TEST(sprintf_u8) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c0) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%c";
  char sym = 'O';
  ck_assert_int_eq(s21_sprintf(str1, format, sym), sprintf(str2, format, sym));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c1) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "hell%c";
  char sym = 'o';
  ck_assert_int_eq(s21_sprintf(str1, format, sym), sprintf(str2, format, sym));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c2) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-5c";
  char sym = '\n';
  ck_assert_int_eq(s21_sprintf(str1, format, sym), sprintf(str2, format, sym));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c3) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%15c";
  char sym = '\0';
  ck_assert_int_eq(s21_sprintf(str1, format, sym), sprintf(str2, format, sym));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c4) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-20c%c%c%c%c Hello!";
  char sym = 'z';
  ck_assert_int_eq(s21_sprintf(str1, format, sym, 'o', 'L', 'l', 'O'),
                   sprintf(str2, format, sym, 'o', 'L', 'l', 'O'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_percent) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "hell%c";
  ck_assert_int_eq(s21_sprintf(str1, format, '%'), sprintf(str2, format, '%'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s0) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%s";
  char *string = "Hello world. This is project C2-String_Plus";
  ck_assert_int_eq(s21_sprintf(str1, format, string),
                   sprintf(str2, format, string));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s1) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.15s";
  char *string = "Hello world. This is project C2-String_Plus";
  ck_assert_int_eq(s21_sprintf(str1, format, string),
                   sprintf(str2, format, string));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s2) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%35s";
  char *string = "School 21";
  ck_assert_int_eq(s21_sprintf(str1, format, string),
                   sprintf(str2, format, string));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s3) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-15.19s";
  char *string = "test case number s3 \t";
  ck_assert_int_eq(s21_sprintf(str1, format, string),
                   sprintf(str2, format, string));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s4) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "---%s---";
  char *string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_int_eq(s21_sprintf(str1, format, string),
                   sprintf(str2, format, string));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s5) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%s%s%s%s";
  char *string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s1 = "0123456789";
  char *s2 = "abcdefghiklmnopqrstuvwxyz";
  char *s3 = "!@#$^&*()_-=+ \t";
  ck_assert_int_eq(s21_sprintf(str1, format, string, s1, s2, s3),
                   sprintf(str2, format, string, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s6) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-35.19s";
  char *string = "test case666";
  ck_assert_int_eq(s21_sprintf(str1, format, string),
                   sprintf(str2, format, string));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g0) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%G";
  float number = NAN;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g1) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Hello - %g";
  float number = NAN;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g2) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is %G";
  float number = 1.01;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g3) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is %+g";
  float number = 35.001;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g4) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is % G";
  float number = 407.001;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g5) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is %g";
  float number = -72.34;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g6) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%15G";
  float number = 53.0015;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g7) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-15g";
  float number = 53.0015;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g8) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%015G";
  float number = 53.0015;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g9) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.3G = number";
  float number = 91.0035;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g10) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.10g = number";
  float number = 91.0035;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g11) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%LG";
  long double number = 101.687;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g12) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%+010.1g";
  float number = 1.05;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g13) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "one is %+010.1g, two is %-10G";
  float number1 = 1.05, number2 = 35.7;
  ck_assert_int_eq(s21_sprintf(str1, format, number1, number2),
                   sprintf(str2, format, number1, number2));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e0) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Hello - %E";
  float number = NAN;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e1) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Hello - %e";
  float number = NAN;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e2) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is %E";
  float number = 1.01;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e3) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is %+e";
  float number = 35.001;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e4) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is % E";
  float number = 407.001;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e5) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "Number is %+e";
  float number = -72.34;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e6) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%15E";
  float number = 53.0015;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e7) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-15e";
  float number = 53.0015;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e8) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%015E";
  float number = 53.0015;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e9) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.0e = number";
  float number = 9.0035;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e10) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.3e = number";
  float number = 91.0035;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e11) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.10e = number";
  float number = 91.0035;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e12) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%LE";
  long double number = 101.687;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e13) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%+010.1e";
  float number = 1.05;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o0) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "hello %15o";
  int number = 88001;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o1) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-16o";
  int number = 88001;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o2) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.8o";
  int number = 88001;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o3) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%-5.8o - hi";
  int number = 88001;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o4) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "--- %o ---";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o5) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "--- %#o ---";
  int number = 90669;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_o6) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%hd";
  short int number = 22460;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o7) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%lo";
  long int number = 32175018906669;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o8) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5o";
  long int number = 32175018906669;
  ck_assert_int_eq(s21_sprintf(str1, format, number, 51, 1945, 10101, 100),
                   sprintf(str2, format, number, 51, 1945, 10101, 100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h0) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%5x";
  unsigned number = 906669;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h1) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#-10x";
  unsigned number = 906669;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h2) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.15x";
  unsigned number = 906669;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h3) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned number = 906669;
  ck_assert_int_eq(
      s21_sprintf(str1, format, number, number, number, number, number, number),
      sprintf(str2, format, number, number, number, number, number, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h4) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#-5.10x";
  unsigned number = 906669;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h5) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#x";
  unsigned number = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h6) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#x";
  unsigned number = 40428;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_h7) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#hx";
  unsigned short number = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h8) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#lx";
  unsigned long number = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h9) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#2x";
  unsigned number = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h10) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#30X";
  unsigned number = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h11) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#-10X";
  unsigned number = 906669;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h12) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#-5.10X";
  unsigned number = 906669;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_h13) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#X";
  unsigned number = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h14) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#X";
  unsigned number = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_h15) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#hX";
  unsigned short number = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_h16) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%#lx";
  unsigned long number = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, number),
                   sprintf(str2, format, number));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p0) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p1) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p2) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p3) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%p";
  char *p = S21_NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, p), sprintf(str2, format, p));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_case_eof) {
  char str1[SIZE];
  char str2[SIZE];

  char *format = "%%";
  ck_assert_int_eq(s21_sprintf(str1, format, NULL),
                   sprintf(str2, format, NULL));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("case_sprintf");

  tcase_add_test(tc, sprintf_f0);
  tcase_add_test(tc, sprintf_f1);
  tcase_add_test(tc, sprintf_f2);
  tcase_add_test(tc, sprintf_f3);
  tcase_add_test(tc, sprintf_f4);
  tcase_add_test(tc, sprintf_f5);
  tcase_add_test(tc, sprintf_f6);
  tcase_add_test(tc, sprintf_f7);
  tcase_add_test(tc, sprintf_f8);
  tcase_add_test(tc, sprintf_f9);
  tcase_add_test(tc, sprintf_f10);
  tcase_add_test(tc, sprintf_f11);
  tcase_add_test(tc, sprintf_f12);
  tcase_add_test(tc, sprintf_f13);
  tcase_add_test(tc, sprintf_f14);
  tcase_add_test(tc, sprintf_f15);
  tcase_add_test(tc, sprintf_f16);
  tcase_add_test(tc, sprintf_f17);
  tcase_add_test(tc, sprintf_f18);
  tcase_add_test(tc, sprintf_f19);

  tcase_add_test(tc, sprintf_d0);
  tcase_add_test(tc, sprintf_d1);
  tcase_add_test(tc, sprintf_d2);
  tcase_add_test(tc, sprintf_d3);
  tcase_add_test(tc, sprintf_d4);
  tcase_add_test(tc, sprintf_d5);
  tcase_add_test(tc, sprintf_d6);
  tcase_add_test(tc, sprintf_d7);
  tcase_add_test(tc, sprintf_d8);
  tcase_add_test(tc, sprintf_d9);
  tcase_add_test(tc, sprintf_d10);
  tcase_add_test(tc, sprintf_d11);
  tcase_add_test(tc, sprintf_d12);

  tcase_add_test(tc, sprintf_u0);
  tcase_add_test(tc, sprintf_u1);
  tcase_add_test(tc, sprintf_u2);
  tcase_add_test(tc, sprintf_u3);
  tcase_add_test(tc, sprintf_u4);
  tcase_add_test(tc, sprintf_u5);
  tcase_add_test(tc, sprintf_u6);
  tcase_add_test(tc, sprintf_u7);
  tcase_add_test(tc, sprintf_u8);

  tcase_add_test(tc, sprintf_c0);
  tcase_add_test(tc, sprintf_c1);
  tcase_add_test(tc, sprintf_c2);
  tcase_add_test(tc, sprintf_c3);
  tcase_add_test(tc, sprintf_c4);

  tcase_add_test(tc, sprintf_percent);

  tcase_add_test(tc, sprintf_s0);
  tcase_add_test(tc, sprintf_s1);
  tcase_add_test(tc, sprintf_s2);
  tcase_add_test(tc, sprintf_s3);
  tcase_add_test(tc, sprintf_s4);
  tcase_add_test(tc, sprintf_s5);
  tcase_add_test(tc, sprintf_s6);

  tcase_add_test(tc, sprintf_g0);
  tcase_add_test(tc, sprintf_g1);
  tcase_add_test(tc, sprintf_g2);
  tcase_add_test(tc, sprintf_g3);
  tcase_add_test(tc, sprintf_g4);
  tcase_add_test(tc, sprintf_g5);
  tcase_add_test(tc, sprintf_g6);
  tcase_add_test(tc, sprintf_g7);
  tcase_add_test(tc, sprintf_g8);
  tcase_add_test(tc, sprintf_g9);
  tcase_add_test(tc, sprintf_g10);
  tcase_add_test(tc, sprintf_g11);
  tcase_add_test(tc, sprintf_g12);
  tcase_add_test(tc, sprintf_g13);

  tcase_add_test(tc, sprintf_e0);
  tcase_add_test(tc, sprintf_e1);
  tcase_add_test(tc, sprintf_e2);
  tcase_add_test(tc, sprintf_e3);
  tcase_add_test(tc, sprintf_e4);
  tcase_add_test(tc, sprintf_e5);
  tcase_add_test(tc, sprintf_e6);
  tcase_add_test(tc, sprintf_e7);
  tcase_add_test(tc, sprintf_e8);
  tcase_add_test(tc, sprintf_e9);
  tcase_add_test(tc, sprintf_e10);
  tcase_add_test(tc, sprintf_e11);
  tcase_add_test(tc, sprintf_e12);
  tcase_add_test(tc, sprintf_e13);

  tcase_add_test(tc, sprintf_o0);
  tcase_add_test(tc, sprintf_o1);
  tcase_add_test(tc, sprintf_o2);
  tcase_add_test(tc, sprintf_o3);
  tcase_add_test(tc, sprintf_o4);
  tcase_add_test(tc, sprintf_o5);
  tcase_add_test(tc, sprintf_o6);
  tcase_add_test(tc, sprintf_o7);
  tcase_add_test(tc, sprintf_o8);

  tcase_add_test(tc, sprintf_h0);
  tcase_add_test(tc, sprintf_h1);
  tcase_add_test(tc, sprintf_h2);
  tcase_add_test(tc, sprintf_h3);
  tcase_add_test(tc, sprintf_h4);
  tcase_add_test(tc, sprintf_h5);
  tcase_add_test(tc, sprintf_h6);
  tcase_add_test(tc, sprintf_h7);
  tcase_add_test(tc, sprintf_h8);
  tcase_add_test(tc, sprintf_h9);
  tcase_add_test(tc, sprintf_h10);
  tcase_add_test(tc, sprintf_h11);
  tcase_add_test(tc, sprintf_h12);
  tcase_add_test(tc, sprintf_h13);
  tcase_add_test(tc, sprintf_h14);
  tcase_add_test(tc, sprintf_h15);
  tcase_add_test(tc, sprintf_h16);

  tcase_add_test(tc, sprintf_p0);
  tcase_add_test(tc, sprintf_p1);
  tcase_add_test(tc, sprintf_p2);
  tcase_add_test(tc, sprintf_p3);

  tcase_add_test(tc, sprintf_case_eof);

  suite_add_tcase(s, tc);
  return s;
}