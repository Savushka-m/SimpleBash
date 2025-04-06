#!/bin/bash
gcc -Wall -Wextra -Werror -std=c11 ../s21_cat.c -o s21_cat

PROGRAMM="./s21_cat"

run_test() {
    local flag=$1
    local file=$2
    local s21cat_output="s21cat_output.txt"
    local cat_output="cat_output.txt"

    $PROGRAMM $flag $file > $s21cat_output 2>&1

    cat $flag $file > $cat_output 2>&1

    if diff -q $s21cat_output $cat_output > /dev/null; then
        echo "+\tТест с флагом '$flag' и файлом '$file' пройден"
    else
        echo "-\tТест с флагом '$flag' и файлом '$file' не пройден"
        echo "Различия:"
        diff $s21cat_output $cat_output
    fi
}

run_test -b test1.txt
run_test -e test1.txt
run_test -E test1.txt
run_test -n test1.txt
run_test -s test1.txt
run_test -t test1.txt
run_test -T test1.txt
run_test -v test1.txt

run_test -b test2.txt
run_test -e test2.txt
run_test -E test2.txt
run_test -n test2.txt
run_test -s test2.txt
run_test -t test2.txt
run_test -T test2.txt
run_test -v test2.txt

run_test -b test3.txt
run_test -e test3.txt
run_test -E test3.txt
run_test -n test3.txt
run_test -s test3.txt
run_test -t test3.txt
run_test -T test3.txt
run_test -v test3.txt

run_test -b test4.txt
run_test -e test4.txt
run_test -E test4.txt
run_test -n test4.txt
run_test -s test4.txt
run_test -t test4.txt
run_test -T test4.txt
run_test -v test4.txt

run_test -b test5.txt
run_test -e test5.txt
run_test -E test5.txt
run_test -n test5.txt
run_test -s test5.txt
run_test -t test5.txt
run_test -T test5.txt
run_test -v test5.txt

rm -f s21cat_output.txt cat_output.txt