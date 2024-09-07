#!/bin/bash

echo "Test group for s21_grep quest"

./s21_grep a testgrep.txt >> s21_grep.txt
grep a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -e a testgrep.txt >> s21_grep.txt
grep -e a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -i a testgrep.txt >> s21_grep.txt
grep -i a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -v a testgrep.txt >> s21_grep.txt
grep -v a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -c a testgrep.txt >> s21_grep.txt
grep -c a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -l a testgrep.txt >> s21_grep.txt
grep -l a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -n a testgrep.txt >> s21_grep.txt
grep -n a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep a testgrep.txt testgrep.txt >> s21_grep.txt
grep a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -e a testgrep.txt testgrep.txt >> s21_grep.txt
grep -e a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -i a testgrep.txt testgrep.txt >> s21_grep.txt
grep -i a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -v a testgrep.txt testgrep.txt >> s21_grep.txt
grep -v a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -c a testgrep.txt testgrep.txt >> s21_grep.txt
grep -c a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -l a testgrep.txt testgrep.txt >> s21_grep.txt
grep -l a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -n a testgrep.txt testgrep.txt >> s21_grep.txt
grep -n a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "Test group for bonus quest 1"

./s21_grep -h a testgrep.txt testgrep.txt >> s21_grep.txt
grep -h a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -f pattern.txt testgrep.txt >> s21_grep.txt
grep -f pattern.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -s a testgrepabc.txt >> s21_grep.txt
grep -s a testgrepabc.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

# CORRECT WORK ON MAC

# ./s21_grep -o a testgrep.txt >> s21_grep.txt
# grep -o a testgrep.txt >> grep.txt
# diff -s s21_grep.txt grep.txt
# rm s21_grep.txt grep.txt

./s21_grep -f pattern.txt testgrep.txt testgrep.txt >> s21_grep.txt
grep -f pattern.txt testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo "Test group for bonus quest 2"

./s21_grep -iv a testgrep.txt >> s21_grep.txt
grep -iv a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ic a testgrep.txt >> s21_grep.txt
grep -ic a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -il a testgrep.txt >> s21_grep.txt
grep -il a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -in a testgrep.txt >> s21_grep.txt
grep -in a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ih a testgrep.txt testgrep.txt >> s21_grep.txt
grep -ih a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -is a testgrepa.txt >> s21_grep.txt
grep -is a testgrepa.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ie a testgrep.txt >> s21_grep.txt
grep -ie a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -if pattern.txt testgrep.txt >> s21_grep.txt
grep -if pattern.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -vc a testgrep.txt >> s21_grep.txt
grep -vc a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -vl a testgrep.txt >> s21_grep.txt
grep -vl a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -vn a testgrep.txt >> s21_grep.txt
grep -vn a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -vh a testgrep.txt testgrep.txt >> s21_grep.txt
grep -vh a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -vs a testgrepa.txt >> s21_grep.txt
grep -vs a testgrepa.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ve a testgrep.txt >> s21_grep.txt
grep -ve a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -cn a testgrep.txt >> s21_grep.txt
grep -cn a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ch a testgrep.txt testgrep.txt >> s21_grep.txt
grep -ch a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -cs a testgrepa.txt >> s21_grep.txt
grep -cs a testgrepa.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ce a testgrep.txt >> s21_grep.txt
grep -ce a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -cf pattern.txt testgrep.txt >> s21_grep.txt
grep -cf pattern.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ln a testgrep.txt >> s21_grep.txt
grep -ln a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -lh a testgrep.txt testgrep.txt >> s21_grep.txt
grep -lh a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ls a testgrepa.txt >> s21_grep.txt
grep -ls a testgrepa.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -le a testgrep.txt >> s21_grep.txt
grep -le a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -lf pattern.txt testgrep.txt >> s21_grep.txt
grep -lf pattern.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -nh a testgrep.txt testgrep.txt >> s21_grep.txt
grep -nh a testgrep.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ns a testgrepa.txt >> s21_grep.txt
grep -ns a testgrepa.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -ne a testgrep.txt >> s21_grep.txt
grep -ne a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -nf pattern.txt testgrep.txt >> s21_grep.txt
grep -nf pattern.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -hs a testgrepa.txt >> s21_grep.txt
grep -hs a testgrepa.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -he a testgrep.txt >> s21_grep.txt
grep -he a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -hf pattern.txt testgrep.txt >> s21_grep.txt
grep -hf pattern.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -se a testgrep.txt >> s21_grep.txt
grep -se a testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -sf pattern.txt testgrep.txt >> s21_grep.txt
grep -sf pattern.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -e k -f pattern.txt testgrep.txt >> s21_grep.txt
grep -e k -f pattern.txt testgrep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt