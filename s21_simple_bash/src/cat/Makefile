CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: clean s21_cat test

s21_cat : s21_cat.o
	$(CC) s21_cat.o -o s21_cat

s21_cat.o : s21_cat.c s21_cat.h
	$(CC) $(CFLAGS) s21_cat.c

test: s21_cat
	./test.sh

clean :
	rm -rf *.o
	rm -rf s21_cat

clang-check:
	cp ../../materials/linters/.clang-format .
	clang-format -n *.c *.h
	rm .clang-format

clang-fix:
	cp ../../materials/linters/.clang-format .
	clang-format -i *.c *.h
	rm .clang-format