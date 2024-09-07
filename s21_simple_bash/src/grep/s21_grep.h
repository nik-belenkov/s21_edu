#ifndef S21_GREP_H
#define S21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 4096
#define MEMORY 10
#define ERR_MSG "No such file or directory\n"

typedef struct {
  regex_t* expression;
  int length;
  int size;
} regular_arr;

/**
 * grep_flags - The struct contains flags.
 * @param i - Ignore uppercase vs. lowercase.
 * @param v - Invert match.
 * @param c - Output count of matching lines only.
 * @param l - Output matching files only.
 * @param n - Precede each matching line with a line number.
 * @param h - Output matching lines without preceding them by file names.
 * @param s - Suppress error messages about nonexistent or unreadable files.
 * @param o - Output the matched parts of a matching line.
 */

typedef struct {
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int o;
} grep_flags;

regular_arr create_regular_arr();
void regular_arr_add(regular_arr* result, char* pattern, int settings);
void remove_array(regular_arr* result);

char flag_i_parsing(int argc, char* argv[], grep_flags* g_flags);
char parse_args(int argc, char* argv[], int* arg_i, regular_arr* patterns,
                grep_flags* g_flags);
int process_file(char* filename, int file_count, char flags,
                 regular_arr patterns, grep_flags* g_flags);

#endif