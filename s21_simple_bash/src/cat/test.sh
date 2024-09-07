#!/bin/bash

./s21_cat byte_test.txt >> s21_cat.txt
cat byte_test.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -b byte_test.txt >> s21_cat.txt
cat -b byte_test.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -n byte_test.txt >> s21_cat.txt
cat -n byte_test.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -s byte_test.txt >> s21_cat.txt
cat -s byte_test.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -t byte_test.txt >> s21_cat.txt
cat -t byte_test.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -e byte_test.txt >> s21_cat.txt
cat -e byte_test.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

# ./s21_cat -ebnst byte_test.txt byte_test.txt >> s21_cat.txt
# cat -ebnst byte_test.txt byte_test.txt >> cat.txt
# diff -s s21_cat.txt cat.txt
# rm s21_cat.txt cat.txt