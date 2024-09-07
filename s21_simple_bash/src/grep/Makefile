CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all : clean s21_grep test

s21_grep : s21_grep.o
	$(CC) s21_grep.o -o s21_grep

s21_grep.o : s21_grep.c s21_grep.h
	$(CC) $(CFLAGS) s21_grep.c

test: s21_grep
	./test.sh

clean :
	rm -rf *.o
	rm -rf s21_grep

clang-check:
	cp ../../materials/linters/.clang-format .
	clang-format -n *.c *.h
	rm .clang-format

clang-fix:
	cp ../../materials/linters/.clang-format .
	clang-format -i *.c *.h
	rm .clang-format