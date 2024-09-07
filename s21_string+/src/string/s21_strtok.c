#include "s21_string.h"

bool is_eos(char c) {
  bool res = false;
  if (c == '\0') res = true;
  return res;
}

bool is_delim(char c, const char* delim) {
  const char* pos = delim;
  bool res = false;
  while (*pos != '\0') {
    if (*pos == c) {
      res = true;
      break;
    }
    pos++;
  }
  return res;
}

char* s21_strtok(char* str, const char* delim) {
  static char* token = NULL;
  static char* next_token = NULL;

  if (str != NULL) {
    token = str;
  } else {
    if (next_token == NULL) {
      return NULL;
    }
    token = next_token;
  }

  while (!is_eos(*token) && is_delim(*token, delim)) {
    token++;
  }

  if (*token == '\0') {
    next_token = NULL;
    return NULL;
  }

  char* start = token;

  while (!is_eos(*token) && !is_delim(*token, delim)) {
    token++;
  }

  if (!is_eos(*token)) {
    *token = '\0';
    next_token = token + 1;
  } else {
    next_token = NULL;
  }

  return start;
}