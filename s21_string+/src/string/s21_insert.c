#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = S21_NULL;

  if (src && str && start_index <= s21_strlen(src)) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_str = s21_strlen(str);

    new_str = malloc(sizeof(char) * (len_str + len_src + 1));

    for (s21_size_t i = 0, index_src = 0; i < len_str + len_src + 1; i++) {
      if (i == start_index) {
        for (s21_size_t j = 0; j < len_str; j++) {
          new_str[i] = str[j];
          i += 1;
        }
        i -= 1;
      }

      else {
        new_str[i] = src[index_src];
        index_src += 1;
      }
    }
  }

  return new_str;
}
