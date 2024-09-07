#include "s21_string.h"

typedef struct template {
  int width;
  char lenght;
  va_list *argv;
  int str_index;
  int count;
}
template;

void set_width(const char *str, int *step, template *item);
void set_lenght(const char *str, int *step, template *item);
void get_parametrs(template *item);
int convertation_str_to_int(char *str, int *step);
int work_with_str(char *boof, template *item, int length_item);

char *specific(char *boof, char *val, template *item) {
  switch (*val) {
    case 'c':
      get_parametrs(item);
      item->width = -2;
      boof += work_with_str(boof, item, 1);
      break;
    case 's':
      get_parametrs(item);
      boof += work_with_str(boof, item, 0);
      break;
    case '%':
      get_parametrs(item);
      item->width = -2;
      boof += work_with_str(boof, item, 1);
      break;

    default:
      break;
  }

  return boof;
}

int convertation_str_to_int(char *str, int *step) {
  int result = 0;
  int num = *(str + *step) - 48;

  while (num >= 0 && num < 10) {
    result = result * 10 + num;
    *step += 1;
    num = *(str + *step) - 48;
  }

  return result;
}

void set_width(const char *str, int *step, template *item) {
  int width = 0;

  if (*(str + *step) == '*') {
    item->width = -1;
    *step += 1;
  } else {
    width = convertation_str_to_int((char *)str, step);
    item->width = width == 0 ? -2 : width;
  }
}

void set_lenght(const char *str, int *step, template *item) {
  if (s21_strrchr("hlL", *(str + *step)) != NULL) {
    item->lenght = *(str + *step);
    *step += 1;
  }
}

void get_parametrs(template *item) {
  if (item->width == -1) {
    item->width = va_arg(*item->argv, int);
  }
}

int work_with_str(char *boof, template *item, int length_item) {
  char *main_str = va_arg(*item->argv, char *);

  item->width = item->width < (int)s21_strlen(boof) && item->width != -2
                    ? item->width
                    : (int)s21_strlen(boof);

  int i = 0;
  do {
    main_str[i] = boof[i];
    i++;
    if (length_item) {
      break;
    } else if (i == item->width || s21_strrchr(" \0\t", boof[i]) != NULL) {
      main_str[i] = '\0';
      break;
    }
  } while (s21_strrchr(" \0\t", boof[i]) == NULL);
  item->count = 1;
  i += *(boof + i) == ' ' ? 1 : 0;

  item->str_index = i;
  return i;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list param;
  va_start(param, format);

  int len_for = s21_strlen(format);
  int index_str = 0;
  int result = 0;

  for (int i = 0; i < len_for; i++) {
    if (format[i] == '%') {
      int step = i + 1;
      template item = {-2, 0, &param, 0, 0};
      set_width(format, &step, &item);
      set_lenght(format, &step, &item);
      specific((char *)str + index_str, (char *)format + step, &item);
      result += item.count;

      if (index_str + item.str_index > (int)s21_strlen(str + index_str)) {
        break;
      }
      index_str += item.str_index;
    }
  }
  va_end(param);
  return result;
}
