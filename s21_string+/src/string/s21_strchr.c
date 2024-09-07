#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (c == str[i]) {
      result = ((char *)str) + i;
      break;
    }
  }
  return result;
}