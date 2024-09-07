#ifndef S21_CAT_H
#define S21_CAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR1 1
#define ERR2 2
#define MSG1 "illegal option"
#define MSG2 "No such file or directory"

struct flags {
  int b, e, n, s, t, v;
};

int parser(int argc, char *argv[], struct flags *flg);
int helper_parser(int i, int sym, char *argv[], struct flags *flg);
int read_file(int argc, char *argv[], struct flags flg);
void output(FILE *f, struct flags flg, int num_file);
void last_sym(struct flags flg, int current);
void errors(int condition);

#endif