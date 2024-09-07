#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  s21_size_t i = 0;
  while (i < n) {
    if (str1[i] == str2[i]) {
      i++;
    } else {
      res =
          (int)str1[i] -
          (int)str2[i];  //переводит чар в инт по таблице аски и выводит разницу
                         //если рез>0, то симв 1 стр больше, 0 они равны
      break;
    }
  }
  return res;
}