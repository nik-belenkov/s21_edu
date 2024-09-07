#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *new_str = S21_NULL;

  if (str != S21_NULL) {
    new_str = malloc(sizeof(char) * (s21_strlen(str) + 1));
    if (new_str) {
      for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
        if (*(str + i) >= 97 && *(str + i) <= 122) {
          new_str[i] = *(str + i) - 32;
        }

        else {
          new_str[i] = *(str + i);
        }
      }
    }
  }

  return new_str;
}