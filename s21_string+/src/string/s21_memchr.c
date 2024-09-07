#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *success = S21_NULL;
  unsigned char *ptr = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (*ptr == (unsigned char)c) {
      success = ptr;
      break;
    }
    ptr++;
  }
  return success;
}