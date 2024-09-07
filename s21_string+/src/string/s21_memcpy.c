#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *destination = (unsigned char *)dest;
  unsigned char *source = (unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    destination[i] = source[i];
  }
  return destination;
}