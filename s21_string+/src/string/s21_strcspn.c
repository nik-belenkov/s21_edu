#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t length = 0;
  unsigned short isEqual = 0;
  for (const char *s1 = str1; *s1; s1++) {
    for (const char *s2 = str2; *s2; s2++) {
      if (*s1 == *s2) {
        isEqual = 1;
        break;
      }
    }
    if (isEqual) {
      break;
    }
    length++;
  }
  return length;
}