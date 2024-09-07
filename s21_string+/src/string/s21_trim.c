#include "s21_string.h"

int find_start(const char *src, const char *trim_chars, int start);
int find_end(const char *src, const char *trim_chars, int end);

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      int start = 0, end = s21_strlen(src);
      result = calloc(end + 1, sizeof(char));
      while (find_start(src, trim_chars, start)) start++;
      if (start != end) {
        while (find_end(src, trim_chars, end)) end--;
      } else {
        result[0] = '\0';
      }
      for (int i = 0; start < end; i++) {
        result[i] = src[start++];
      }
    } else {
      result = s21_trim(src, "\t\n ");
    }
  }
  return result;
}

int find_start(const char *src, const char *trim_chars, int start) {
  int match = 0;
  for (s21_size_t i = 0; i < s21_strlen(trim_chars); i++) {
    if (src[start] == trim_chars[i]) match = 1;
  }
  return match;
}

int find_end(const char *src, const char *trim_chars, int end) {
  int match = 0;
  end--;
  for (s21_size_t i = 0; i < s21_strlen(trim_chars); i++) {
    if (src[end] == trim_chars[i]) match = 1;
  }
  return match;
}