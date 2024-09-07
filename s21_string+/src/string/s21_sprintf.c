#include "s21_string.h"

typedef struct template {
  int flags[3];
  int width;
  int quantity;
  char lenght;

  va_list *argv;

  char flag;

  int str_i, for_i;
}
template;

int setflag(const char *str, int *step, template *item);
void setwidth(const char *str, int *step, template *item);
void setquantity(const char *str, int *step, template *item);
int setlenght(const char *str, int *step, template *item);
int set_specifiers(const char *str, int *step, template *item, char *buffer);

long long int_length(template *item, int type);
int convert_str_to_int(const char *str, int *step);
void get_params(template *item);
long long pow_int(int value, int y);
long long int get_length_value(int base, long long int value);
int type_sing(long long int value, template *item);

void d_u_flags(char *boof, template *item, int type);
void c_flag(char *boof, template *item);
void x_o_flags(char *boof, template *item, int base, int to_up,
               long long int *inform_value);
void p_flags(char *boof, template *item, int base, int to_up);
void g_flags(char *boof, template *item, int to_up, long double value);
void e_o_flags(char *boof, template *item, int to_up, long double number);

void float_to_str(template *item, char *str, char flag);
long double get_float(template *item);
void print_float(long double number, template *item, char *str);
void print_nan_inf(char *str, int *ind, int condition);
void nan_inf_addition(char *str, int *ind, char *word);
char sign_rule(long double number, template *item);
int set_degree(long long number);
void sign_print(int sign_flag, char sign, char *str, int *ind);
void dot_print(char dot, char *str, int *ind);
void convert_number(long long number, int degree, char *str, int *i);
void convert_fraction(long double fraction, int precision, char *str, int *ind);
void helper_print(int nan_inf, int sign_flag, char sign, char dot,
                  long long number, int degree, long double fraction,
                  int precision, char *str, int *ind);

void float_to_str(template *item, char *str, char flag) {
  long double number = get_float(item);
  if (flag == 'f' || flag == 'F') {
    item->flag = flag;
    print_float(number, item, str);
  } else if (flag == 'g' || flag == 'G') {
    int condition = flag == 'g' ? 1 : 0;
    g_flags(str, item, condition, number);
  } else if (flag == 'e' || flag == 'E') {
    int condition = flag == 'e' ? 1 : 0;
    e_o_flags(str, item, condition, number);
  }
}

long double get_float(template *item) {
  long double number = 0;
  if (item->lenght == 'L') {
    number = va_arg(*(item->argv), long double);
  } else {
    number = va_arg(*(item->argv), double);
  }
  if (item->quantity == -1) {
    item->quantity = 6;
  }
  return number;
}

void print_float(long double number, template *item, char *str) {
  int precision = item->quantity, width = item->width;
  int nan_inf = isnan(number) == 0 ? 0 : 1 + ((item->flag == 'F') * 2);
  nan_inf = isinf(number) == 0 ? nan_inf : 2 + ((item->flag == 'F') * 2);
  precision = nan_inf > 0 ? 0 : precision;
  char dot = precision == 0 ? '\0' : '.';
  char sign = sign_rule(number, item);
  int sign_flag = sign == '\0' ? 0 : 1;
  long double copy_num = number > 0 ? number : -number;
  long double integer = 0, fraction = modfl(copy_num, &integer);
  long long copy_int =
      precision == 0 ? (long long)roundl(copy_num) : (long long)integer;
  int degree_int = nan_inf > 0 ? 3 : set_degree(copy_int);
  degree_int = degree_int == 0 ? 1 : degree_int;

  int precis = (precision + degree_int + sign_flag + (dot == '.'));
  int len = width > precis ? width : precis;
  int dif = width - precis;
  dif = dif > 0 ? dif : -dif;
  int ind = 0;
  char sym = ' ';
  if (width > precis) {
    if (item->flags[1] == 2) {
      helper_print(nan_inf, sign_flag, sign, dot, copy_int, degree_int,
                   fraction, precision, str, &ind);
      for (; ind < len; ind++) {
        str[ind] = sym;
      }
    } else if (item->flags[1] == 0 || item->flags[1] == 1) {
      if (item->flags[1] == 1 && !nan_inf) {
        sym = '0';
        sign_print(sign_flag, sign, str, &ind);
        dif = sign_flag == 0 ? dif : dif + 1;
        sign_flag = 0;
      }
      for (; ind < dif; ind++) {
        str[ind] = sym;
      }
      helper_print(nan_inf, sign_flag, sign, dot, copy_int, degree_int,
                   fraction, precision, str, &ind);
    }
  } else {
    helper_print(nan_inf, sign_flag, sign, dot, copy_int, degree_int, fraction,
                 precision, str, &ind);
  }
  item->str_i += len - 1;
}

void helper_print(int nan_inf, int sign_flag, char sign, char dot,
                  long long number, int degree, long double fraction,
                  int precision, char *str, int *ind) {
  sign_print(sign_flag, sign, str, ind);
  if (nan_inf == 0) {
    convert_number(number, degree, str, ind);
    dot_print(dot, str, ind);
    convert_fraction(fraction, precision, str, ind);
  } else {
    print_nan_inf(str, ind, nan_inf);
  }
}

void convert_fraction(long double fraction, int precision, char *str,
                      int *ind) {
  long double copy_frac = fraction;
  char sym = '\0';
  for (int i = 0; i < precision; i++) {
    copy_frac *= 10;
    sym = i == precision - 1 ? (long long)roundl(copy_frac) % 10 + 48
                             : (long long)(copy_frac + 0.05) % 10 + 48;
    str[*ind] = sym;
    *ind += 1;
  }
}

void nan_inf_addition(char *str, int *ind, char *word) {
  for (s21_size_t i = 0; i < s21_strlen(word); i++) {
    str[*ind] = word[i];
    *ind += 1;
  }
}

void print_nan_inf(char *str, int *ind, int condition) {
  char nan_low[] = "nan";
  char inf_low[] = "inf";
  if (condition == -1) nan_inf_addition(str, ind, "(nil)");
  if (condition == 1) nan_inf_addition(str, ind, nan_low);
  if (condition == 2) nan_inf_addition(str, ind, inf_low);
  if (condition == 3) nan_inf_addition(str, ind, "NAN");
  if (condition == 4) nan_inf_addition(str, ind, "INF");
}

char sign_rule(long double number, template *item) {
  char sign = '\0';
  sign = item->flags[0] == 1 ? ' ' : sign;
  sign = item->flags[0] == 2 ? '+' : sign;
  sign = number < 0 ? '-' : sign;
  return sign;
}

int set_degree(long long number) {
  int degree = 0;
  while (number > 0) {
    number /= 10;
    degree++;
  }
  return degree;
}

void sign_print(int sign_flag, char sign, char *str, int *ind) {
  if (sign_flag) {
    str[*ind] = sign;
    *ind += 1;
  }
}

void dot_print(char dot, char *str, int *ind) {
  if (dot == '.') {
    str[*ind] = dot;
    *ind += 1;
  }
}

void convert_number(long long number, int degree, char *str, int *i) {
  char sym = '\0';
  while (degree > 0) {
    sym = number / pow_int(10, degree - 1);
    number %= pow_int(10, degree - 1);
    sym = sym + 48;
    degree -= 1;
    str[*i] = sym;
    *i += 1;
  }
}

long long int get_length_value(int base, long long int value) {
  long long int pow_v = 0;

  while (value > 0) {
    value /= base;
    pow_v += 1;
  }

  return pow_v;
}

int type_sing(long long int value, template *item) {
  int sing = 0;

  if (value < 0) {
    item->flags[0] = '-';
    sing = 1;
  } else if (item->flags[0] > 0) {
    item->flags[0] = item->flags[0] == 2 ? '+' : ' ';
    sing = 1;
  } else {
    item->flags[0] = -1;
  }

  return sing;
}

long long int_length(template *item, int type) {
  if (item->lenght == 'l') {
    if (type == 1) {
      return (signed long)va_arg(*(item->argv), long int);
    } else {
      return (unsigned long)va_arg(*(item->argv), unsigned long int);
    }
  } else if (item->lenght == 'h') {
    if (type == 1) {
      return (signed short)va_arg(*(item->argv), int);
    } else {
      return (unsigned short)va_arg(*(item->argv), int);
    }
  } else {
    if (type == 1) {
      return (signed)va_arg(*(item->argv), int);
    } else {
      return (unsigned)va_arg(*(item->argv), unsigned int);
    }
  }
}

void get_params(template *item) {
  if (item->width == -1) {
    item->width = va_arg(*item->argv, int);
  } else if (item->quantity == -2) {
    item->quantity = va_arg(*item->argv, int);
  }
}

int convert_str_to_int(const char *str, int *step) {
  int result = 0;
  int num = *(str + *step) - 48;

  while (num >= 0 && num < 10) {
    result = result * 10 + num;
    *step += 1;
    num = *(str + *step) - 48;
  }

  return result;
}

long long pow_int(int value, int y) {
  long long int value_final = 1;

  while (y > 0) {
    value_final *= value;
    y -= 1;
  }
  return value_final;
}

void c_flag(char *boof, template *item) {
  char c = va_arg(*(item->argv), int);

  int width = 1 > item->width ? 1 : item->width;

  int step = item->flags[1] == 2 ? 1 : -1;
  int start = step > -1 ? 0 : width - 1;
  for (int i = 0; i < width; i++, start += step) {
    *(boof + start) = i == 0 ? c : ' ';
  }

  item->str_i += width - 1;
}

void s_flag(char *boof, template *item) {
  char *s = va_arg(*(item->argv), char *);
  int length = item->quantity != -1 ? item->quantity : (int)s21_strlen(s);
  int space = item->width - length;
  length = space > 0 ? space + length : length;
  int len_str = (int)s21_strlen(s) > item->quantity && item->quantity != -1
                    ? item->quantity
                    : (int)s21_strlen(s);

  if (item->flags[1] == 2) {
    for (int i = 0; i < length; i++) {
      if (i < len_str) {
        *boof = *s;
        s++;
      } else {
        *boof = ' ';
      }
      boof++;
    }
  } else {
    for (int i = 0; i < length; i++) {
      if (i < length - len_str) {
        *boof = ' ';
      } else {
        *boof = *s;
        s++;
      }
      boof++;
    }
  }
  item->str_i += length - 1;
}

void d_u_flags(char *boof, template *item, int type) {
  long long value = int_length(item, type);

  int sing = type_sing(value, item);

  value = value > 0 ? value : value * -1;

  long long int pow_v = get_length_value(10, value);
  pow_v =
      pow_v == 0 && (item->quantity > 0 || item->quantity == -1) ? 1 : pow_v;
  item->quantity = item->quantity > pow_v ? item->quantity : pow_v;
  item->width =
      item->width > item->quantity + sing ? item->width : item->quantity + sing;

  int widht_dif = item->width - item->quantity - sing;

  char main_key = item->flags[1] == 1 ? '0' : ' ';

  for (int i = 0; i < item->width; i++) {
    char key = main_key;
    if (item->flags[1] != 2 && widht_dif > 0) {
      widht_dif -= 1;
    }

    else if (item->flags[0] != -1) {
      key = item->flags[0];
      item->flags[0] = -1;
    }

    else if (item->quantity - pow_v > 0) {
      key = '0';
      item->quantity -= 1;
    } else if (pow_v > 0) {
      item->quantity = -1;
      key = value / pow_int(10, pow_v - 1);
      value %= pow_int(10, pow_v - 1);
      key = key + 48;
      pow_v -= 1;
    }
    *(boof + i) = key;
  }
  item->str_i += item->width - 1;
}

void x_o_flags(char *boof, template *item, int base, int to_up,
               long long int *inform_value) {
  long long int value;
  if (inform_value != NULL) {
    value = *inform_value;
  } else {
    value = int_length(item, 0);
  }

  int sing = type_sing(value, item);

  long long int pow_v = get_length_value(base, value);

  item->quantity = item->quantity > pow_v ? item->quantity : pow_v;

  if (item->flags[2] == 1 && base == 8 && value > 0) {
    item->quantity += 1;
  } else if (item->flags[2] == 1 && base == 16 && value > 0) {
    item->quantity += 2;
  } else if (value == 0) {
    item->quantity += 1;
  }

  item->width =
      item->width > item->quantity ? item->width : item->quantity + sing;
  int widht_dif = item->width - item->quantity - sing;

  char main_key = item->flags[1] == 1 ? '0' : ' ';

  for (int i = 0; i < item->width; i++) {
    char key = main_key;

    if (item->flags[1] != 2 && widht_dif > 0) {
      widht_dif -= 1;
    }

    else if (item->flags[0] != -1) {
      key = item->flags[0];
      item->flags[0] = -1;
    }

    else if (item->flags[2] >= 0) {
      if (base == 8) {
        item->flags[2] = -1;
        key = '0';
      }
      if (base == 16) {
        key = item->flags[2] == 1 ? '0' : 'X';
        item->flags[2] -= 1;
      }
      item->quantity -= 1;
    }

    else if (item->quantity - pow_v > 0) {
      key = '0';
      item->quantity -= 1;
    } else if (pow_v > 0) {
      key = value / (pow_int(base, pow_v - 1)) % base;

      key = key < 10 ? key + 48 : key + 55;

      item->quantity = -1;
      pow_v -= 1;
    }

    if (key != ' ' && (key < 48 || key > 57) && to_up) {
      key += 32;
    }

    *(boof + i) = key;
  }

  item->str_i += item->width - 1;
}

void e_o_flags(char *boof, template *item, int to_up, long double number) {
  if (isnan(number) || isinf(number)) {
    item->flag = to_up == 0 ? 'F' : 'f';
    print_float(number, item, boof);
  } else {
    int count = 0;
    item->flags[0] = number < 0 ? 3 : item->flags[0];
    int sign = item->flags[0] == 3 ? -1 : 1;
    if (number < 0) {
      number *= -1;
    }
    if (number >= (double)10) {
      while (number >= (double)10) {
        number /= (double)10;
        count++;
      }
    } else if (number < (double)1) {
      while (number < (double)1) {
        number *= (double)10;
        count--;
      }
    }
    item->quantity = item->quantity == -1 ? 6 : item->quantity;
    if (item->width > 0 && item->flags[1] != 2) {
      item->width -= 4;
    }
    print_float(number * sign, item, boof);
    if (item->width != 0) {
      boof += item->width > 0 && item->flags[1] == 2
                  ? 1 + (item->quantity != 0) + item->quantity +
                        (item->flags[0] > 0)
                  : item->width;
    } else {
      boof += 1 + (item->quantity != 0) + item->quantity + (item->flags[0] > 0);
    }
    *boof = to_up == 0 ? 'E' : 'e';
    boof++;
    *boof = count >= 0 ? '+' : '-';
    boof++;
    int t = 0;
    if (count < 0) {
      count *= -1;
    }
    for (int i = 1; i >= 0; i--) {
      t = count % 10;
      count /= 10;
      *(boof + i) = t + 48;
    }
    if (item->flags[1] != 2) item->str_i += 4;
  }
}

void g_flags(char *boof, template *item, int to_up, long double value) {
  int precision = item->quantity == -1 ? 0 : item->quantity;

  if (isnan(value) || isinf(value)) {
    item->flag = to_up == 0 ? 'F' : 'f';
    print_float(value, item, boof);
  } else {
    if (item->quantity == -1) {
      precision = 6;
    }

    else if (item->quantity == 0) {
      precision = 1;
    }

    else {
      precision = item->quantity;
    }

    long double value_copy = value;
    long double x1 = log10(fabsl(value));
    int x = x1 > 0.0 ? x1 : x1 - 1;

    if (x < -4 || x >= precision) {
      e_o_flags(boof, item, to_up, value);
    } else {
      long double integer = 0, fraction = modfl(value_copy, &integer);
      item->quantity = precision - (x + 1);

      fraction *= pow_int(10, item->quantity);
      fraction = roundl(fraction);

      if (item->flags[2] != 1) {
        if ((int)fraction == 0) {
          item->quantity = 0;
          fraction /= pow_int(10, item->quantity);
        } else {
          while ((int)fraction % 10 == 0) {
            fraction /= 10;
            precision -= 1;
          }

          item->quantity = precision - x - 1;
        }
      } else {
        item->quantity = precision - x - 1;
      }

      fraction /= pow_int(10, item->quantity);

      value_copy = integer + fraction;
      print_float(value_copy, item, boof);
    }
  }
}

void p_flags(char *boof, template *item, int base, int to_up) {
  long long int value = int_length(item, 0);

  if (value != 0)
    x_o_flags(boof, item, base, to_up, &value);

  else {
    item->width = item->width > 5 ? item->width : 5;
    item->quantity = 0;
    int width_dif = item->width - 5;

    int show_inf = 1;

    for (int i = 0; i < item->width; i++) {
      char key = ' ';

      if (item->flags[1] != 2 && width_dif > 0) {
        width_dif -= 1;
      }

      else if (show_inf) {
        print_nan_inf(boof, &i, -1);
        show_inf = 0;
      }
      *(boof + i) = key;
    }
    item->str_i += item->width - 1;
  }
  return;
}

int set_specifiers(const char *str, int *step, template *item, char *buffer) {
  int result = 1;
  switch (*(str + *step)) {
    case 'c':
      get_params(item);
      c_flag(buffer, item);
      break;
    case 'd':
      get_params(item);
      d_u_flags(buffer, item, 1);
      break;
    case 'f':
      get_params(item);
      float_to_str(item, buffer, 'f');
      break;
    case 'F':
      get_params(item);
      float_to_str(item, buffer, 'F');
      break;
    case 's':
      get_params(item);
      s_flag(buffer, item);
      break;
    case 'u':
      get_params(item);
      item->flags[0] = 0;
      d_u_flags(buffer, item, 0);
      break;
    case '%':
      get_params(item);
      *(buffer) = '%';
      break;
    case 'x':
      get_params(item);
      x_o_flags(buffer, item, 16, 1, NULL);
      break;
    case 'X':
      get_params(item);
      x_o_flags(buffer, item, 16, 0, NULL);
      break;
    case 'e':
      get_params(item);
      float_to_str(item, buffer, 'e');
      break;
    case 'E':
      get_params(item);
      float_to_str(item, buffer, 'E');
      break;
    case 'o':
      get_params(item);
      x_o_flags(buffer, item, 8, 1, NULL);
      break;
    case 'p':
      item->lenght = 'l';
      item->flags[2] = 1;
      get_params(item);
      p_flags(buffer, item, 16, 1);
      break;
    case 'g':
      get_params(item);
      float_to_str(item, buffer, 'g');
      break;
    case 'G':
      get_params(item);
      float_to_str(item, buffer, 'G');
      break;
    case '\0':
      result = item->flag == 1 ? 1 : 0;
      break;
    default:
      item->flag = 0;
      result = 0;
      break;
  }
  return result;
}

int setlenght(const char *str, int *step, template *item) {
  if (s21_strrchr("hlL", *(str + *step)) != NULL) {
    item->lenght = *(str + *step);
    *step += 1;
  }
  return 0;
}

void setquantity(const char *str, int *step, template *item) {
  if (*(str + *step) == '.') {
    *step += 1;
    int quantity = *(str + *step) - 48;
    if (*(str + *step) == '*') {
      *step += 1;
      item->quantity = -2;
    } else if (quantity < 10 && quantity >= 0) {
      item->quantity = convert_str_to_int(str, step);
    } else {
      item->quantity = 0;
    }
  }
}

void setwidth(const char *str, int *step, template *item) {
  if (*(str + *step) == '*') {
    item->width = -1;
    *step += 1;
  } else {
    item->width = convert_str_to_int(str, step);
  }
}

int setflag(const char *str, int *step, template *item) {
  int res = 1;

  while (res == 1) {
    switch (*(str + *step)) {
      case '+':
        item->flags[0] = 2;
        break;
      case '-':
        item->flags[1] = 2;
        break;
      case ' ':
        if (item->flags[0] == 0) {
          item->flags[0] = 1;
        }
        break;
      case '0':
        if (item->flags[1] == 0) {
          item->flags[1] = 1;
        }
        break;
      case '#':
        item->flags[2] = 1;
        break;

      default:
        res = 0;
        *step -= 1;
        break;
    }

    *step += 1;
  }
  return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list param;
  va_start(param, format);

  int str_i = 0, for_i = 0;
  int flag = 1;
  for (; *(format + for_i) != '\0'; for_i++, str_i++) {
    int res_pars = 0;
    if (*(format + for_i) == '%' && *(format + for_i + 1) != '%') {
      int step = for_i + 1;

      template template_example = {{0, 0, -1}, 0, -1,    '0',
                                   &param,     1, str_i, for_i + 1};
      template_example.flag = flag;

      setflag(format, &step, &template_example);
      setwidth(format, &step, &template_example);
      setquantity(format, &step, &template_example);
      setlenght(format, &step, &template_example);
      res_pars =
          set_specifiers(format, &step, &template_example, (str + str_i));

      if (res_pars == 0) {
        flag = 0;
        s21_strncat(str + str_i, format + for_i, step - for_i);
        str_i += step - for_i - 1;
        for_i = step - 1;
      }

      else if (res_pars && *(format + step) != '\0') {
        str_i = template_example.str_i;
        for_i = step;
      }

      else if (res_pars && *(format + step) == '\0') {
        for_i = step - 1;
        str_i -= 1;
      }

    }

    else {
      *(str + str_i) = *(format + for_i);
    }
  }
  *(str + str_i) = '\0';
  va_end(param);
  return str_i;
}