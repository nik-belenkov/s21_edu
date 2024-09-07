#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;
  int result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    result = *s1 - *s2;
    if (result != 0) break;
    s1++;
    s2++;
  }
  return result;
}