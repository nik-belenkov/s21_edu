#include "s21_cat.h"

int main(int argc, char *argv[]) {
  int condition = 0;
  struct flags flg;
  flg.b = flg.e = flg.n = flg.s = flg.t = flg.v = 0;
  if (argc > 1) {
    condition = parser(argc, argv, &flg);
    if (!condition) {
      condition = read_file(argc, argv, flg);
    }
  }
  if (condition) errors(condition);
  return condition;
}

int parser(int argc, char *argv[], struct flags *flg) {
  int ret_val = 0;
  for (int i = 1; i < argc; i++) {
    for (int sym = 0; sym < (int)strlen(argv[i]); sym++) {
      if (argv[i][0] == '-' && (int)strlen(argv[i]) == 2) {
        sym += 1;
        ret_val = helper_parser(i, sym, argv, flg);
        if (ret_val != 0) break;
        memset(argv[i], '\0', strlen(argv[i]));
      } else if (argv[i][0] == '-' && (int)strlen(argv[i]) > 2 &&
                 argv[i][1] != '-') {
        for (int j = 1; j < (int)strlen(argv[i]); j++) {
          ret_val = helper_parser(i, j, argv, flg);
          if (ret_val != 0) break;
        }
        memset(argv[i], '\0', strlen(argv[i]));
      } else if (argv[i][0] == '-' && argv[i][1] == '-') {
        if (strcmp(argv[i], "--number-nonblank") == 0)
          flg->b = 1;
        else if (strcmp(argv[i], "--number") == 0)
          flg->n = 1;
        else if (strcmp(argv[i], "--squeeze-blank") == 0)
          flg->s = 1;
        else {
          ret_val = ERR1;
          break;
        }
        memset(argv[i], '\0', strlen(argv[i]));
      }
    }
  }
  if (flg->b == 1) {
    flg->n = 0;
  }
  return ret_val;
}

int helper_parser(int i, int sym, char *argv[], struct flags *flg) {
  int ret_val = 0;
  if (argv[i][sym] == 'b')
    flg->b = 1;
  else if (argv[i][sym] == 'e') {
    flg->e = flg->v = 1;
  } else if (argv[i][sym] == 'E')
    flg->e = 1;
  else if (argv[i][sym] == 'n')
    flg->n = 1;
  else if (argv[i][sym] == 's')
    flg->s = 1;
  else if (argv[i][sym] == 't') {
    flg->t = flg->v = 1;
  } else if (argv[i][sym] == 'T')
    flg->t = 1;
  else if (argv[i][sym] == 'v') {
    flg->v = 1;
  } else {
    ret_val = ERR1;
  }
  return ret_val;
}

int read_file(int argc, char *argv[], struct flags flg) {
  FILE *f;
  int ret_val = 0;
  int num_file = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '\0') {
      f = fopen(argv[i], "r");
      if (f != NULL) {
        num_file++;
        output(f, flg, num_file);
        fclose(f);
      } else {
        ret_val = ERR2;
      }
    }
  }
  return ret_val;
}

void output(FILE *f, struct flags flg, int num_file) {
  int empty = 1;
  int current = fgetc(f);
  int next;
  int str_num = 1;
  if (current != EOF && (flg.n == 1 || (flg.b == 1 && current != '\n')) &&
      num_file >= 1) {
    printf("%6d\t", str_num++);
  }
  while ((next = fgetc(f)) != EOF) {
    if (flg.s == 1 && current == '\n' && next == '\n') {
      empty++;
      if (empty > 1) {
        continue;
      }
    } else {
      empty = 0;
    }
    if (flg.t == 1 && current == '\t') {
      putchar('^');
      current = 'I';
    }
    if (flg.v == 1 && ((current >= 0 && current < 9) ||
                       (current >= 11 && current < 32) || current == 127)) {
      putchar('^');
      if (current == 127) {
        current = 63;
      } else
        current += 64;
    }
    if (flg.e == 1 && current == '\n') {
      putchar('$');
    }
    printf("%c", current);
    if ((flg.n == 1 || (flg.b == 1 && next != '\n')) && current == '\n') {
      printf("%6d\t", str_num++);
    }
    current = next;
  }
  if (current != EOF) last_sym(flg, current);
}

void last_sym(struct flags flg, int current) {
  if (flg.e == 1 && current == '\n') {
    printf("$%c", current);
  } else if (flg.t == 1 && current == '\t') {
    printf("^%c", current + 64);
  } else if (flg.v == 1 &&
             ((current >= 0 && current < 9) ||
              (current >= 11 && current < 32) || current == 127)) {
    if (current == 127) {
      current = 63;
      printf("^%c", current);
    } else
      printf("^%c", current + 64);
  } else {
    putchar(current);
  }
}

void errors(int condition) {
  if (condition == 1)
    printf(MSG1);
  else if (condition == 2)
    printf(MSG2);
}