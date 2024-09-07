#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  int n = s21_strlen(str);
  char *p = S21_NULL;
  while (n >= 0) {
    if (*(str + n) == (char)c) {
      p = (char *)(str + n);
      break;
    }
    n--;
  }
  return p;
}