#include "s21_grep.h"

int main(int argc, char* argv[]) {
  grep_flags g_flags = {0};

  regular_arr patterns = create_regular_arr();
  int arg_num = 1;

  char flags = parse_args(argc, argv, &arg_num, &patterns, &g_flags);
  if (patterns.length == 0) {
    char* pattern = argv[arg_num];
    regular_arr_add(&patterns, pattern, (flags & g_flags.i) ? REG_ICASE : 0);
    arg_num++;
  }

  int file_count = argc - arg_num;
  for (; arg_num < argc; arg_num++) {
    if (process_file(argv[arg_num], file_count, flags, patterns, &g_flags)) {
      fprintf(stderr, "grep: %s: %s", argv[arg_num], ERR_MSG);
    }
  }
  remove_array(&patterns);
  return 0;
}

regular_arr create_regular_arr() {
  regular_arr result;
  result.expression = malloc(MEMORY * sizeof(regex_t));
  result.length = 0;
  result.size = MEMORY;
  return result;
}

void regular_arr_add(regular_arr* result, char* pattern, int settings) {
  if (result->length + 1 == result->size) {
    result->expression =
        realloc(result->expression,
                sizeof(regex_t) * (result->size = result->size * 3 / 2));
  }
  regcomp(&result->expression[result->length++], pattern, settings);
}

void remove_array(regular_arr* result) {
  for (int i = 0; i < result->length; i++) {
    regfree(&result->expression[i]);
  }
  free(result->expression);
}

int regex_check(regex_t regex_c, char* str, char invert) {
  if (invert) {
    return regexec(&regex_c, str, 0, NULL, 0);
  } else {
    return !regexec(&regex_c, str, 0, NULL, 0);
  }
}

char flag_i_parsing(int argc, char* argv[], grep_flags* g_flags) {
  char result = 0;
  char next_pattern = 0;
  char next_file = 0;
  for (int arg_i = 1; arg_i < argc; arg_i++) {
    if (next_pattern) {
      next_pattern = 0;
      continue;
    }
    if (next_file) {
      next_file = 0;
      continue;
    }
    if (argv[arg_i][0] == '-') {
      for (size_t i = 1; i < strlen(argv[arg_i]); i++) {
        if (argv[arg_i][i] == 'i') {
          g_flags->i = 1;
          result |= g_flags->i;
        }
        if (argv[arg_i][i] == 'e') {
          next_pattern = 1;
        }
        if (argv[arg_i][i] == 'f') {
          next_file = 1;
        }
      }
    } else {
      break;
    }
  }
  return result;
}

char parse_args(int argc, char* argv[], int* arg_i, regular_arr* patterns,
                grep_flags* g_flags) {
  char result = flag_i_parsing(argc, argv, g_flags);
  char next_pattern = 0;
  char next_file = 0;
  for (; *arg_i < argc; (*arg_i)++) {
    if (next_pattern) {
      regular_arr_add(patterns, argv[*arg_i],
                      (result & g_flags->i) ? REG_ICASE : 0);
      next_pattern = 0;
      continue;
    }
    if (next_file) {
      FILE* fp = fopen(argv[*arg_i], "r");
      if (!fp) {
        fprintf(stderr, "grep: %s: %s", argv[*arg_i], ERR_MSG);
        next_file = 0;
        continue;
      }
      char buff[BUFFSIZE];
      while (fgets(buff, BUFFSIZE, fp)) {
        if (buff[strlen(buff) - 1] == '\n') {
          buff[strlen(buff) - 1] = '\0';
        }
        regular_arr_add(patterns, buff, (result & g_flags->i) ? REG_ICASE : 0);
      }
      fclose(fp);
      next_file = 0;
      continue;
    }
    if (argv[*arg_i][0] == '-') {
      for (size_t i = 1; i < strlen(argv[*arg_i]); i++) {
        if (argv[*arg_i][i] == 'v') {
          g_flags->v = 1;
          result |= g_flags->v;
        }
        if (argv[*arg_i][i] == 'c') {
          g_flags->c = 1;
          result |= g_flags->c;
        }
        if (argv[*arg_i][i] == 'l') {
          g_flags->l = 1;
          result |= g_flags->l;
        }
        if (argv[*arg_i][i] == 'n') {
          g_flags->n = 1;
          result |= g_flags->n;
        }
        if (argv[*arg_i][i] == 'h') {
          g_flags->h = 1;
          result |= g_flags->h;
        }
        if (argv[*arg_i][i] == 's') {
          g_flags->s = 1;
          result |= g_flags->s;
        }
        if (argv[*arg_i][i] == 'o') {
          g_flags->o = 1;
          result |= g_flags->o;
        }
        if (argv[*arg_i][i] == 'e') {
          next_pattern = 1;
        }
        if (argv[*arg_i][i] == 'f') {
          next_file = 1;
        }
      }
    } else
      break;
  }
  return result;
}

int process_file(char* filename, int file_count, char flags,
                 regular_arr patterns, grep_flags* g_flags) {
  FILE* fp = fopen(filename, "r");
  int match_lines = 0;
  int number_string = 1;
  if (!fp) {
    return !(flags & g_flags->s);
  }
  char buff[BUFFSIZE];
  char exit_file_flag = 0;
  while (fgets(buff, BUFFSIZE, fp)) {
    if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
    for (int patterns_count = 0; patterns_count < patterns.length;
         patterns_count++) {
      if (regex_check(patterns.expression[patterns_count], buff,
                      flags & g_flags->v)) {
        if (flags & g_flags->l) {
          if (flags & g_flags->c) {
            match_lines++;
          }
          exit_file_flag = 1;
          break;
        }
        if (flags & g_flags->c) {
          match_lines++;
          break;
        }
        if ((file_count > 1) && !(flags & g_flags->h)) {
          printf("%s:", filename);
        }
        if (flags & g_flags->n) {
          printf("%d:", number_string);
        }
        if (flags & g_flags->o) {
          regmatch_t match;
          regexec(&(patterns.expression[patterns_count]), buff, 1, &match, 0);
          printf("%.*s\n", (int)(match.rm_eo - match.rm_so),
                 &buff[match.rm_so]);
        } else {
          puts(buff);
        }
        break;
      }
    }
    if (flags & g_flags->l & exit_file_flag) {
      break;
    }
    number_string++;
  }
  if (flags & g_flags->c) {
    if ((file_count > 1) && !(flags & g_flags->h)) {
      printf("%s:", filename);
    }
    printf("%d\n", match_lines);
  }
  if (exit_file_flag) {
    printf("%s\n", filename);
  }
  fclose(fp);
  return 0;
}