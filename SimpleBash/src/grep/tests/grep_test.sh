#!/bin/bash
gcc -Wall -Wextra -Werror -std=c11 ../s21_grep.c -o s21_grep

PROGRAMM="./s21_grep"

run_test() {
    local flag=$1
    local pattern=$2
    local file=$3
    local s21grep_output="s21grep_output.txt"
    local grep_output="grep_output.txt"

    $PROGRAMM $flag $pattern $file > $s21grep_output 2>&1

    grep $flag $pattern $file > $grep_output 2>&1

    if diff -q $s21grep_output $grep_output > /dev/null; then
        echo "+\tТест с флагом '$flag' и файлом '$file' пройден"
    else
        echo "-\tТест с флагом '$flag' и файлом '$file' не пройден"
        echo "Различия:"
        diff $s21grep_output $grep_output
    fi
}

run_test_2e() {
    local flag1=$1
    local flag2=$3
    local flag3=$5
    local pattern1=$2
    local pattern2=$4
    local file=$6
    local s21grep_output="s21grep_output.txt"
    local grep_output="grep_output.txt"

    $PROGRAMM $flag1 $pattern1 $flag2 $pattern2 $flag3 $file > $s21grep_output 2>&1

    grep $flag1 $pattern1 $flag2 $pattern2 $flag3 $file > $grep_output 2>&1

    if diff -q $s21grep_output $grep_output > /dev/null; then
        echo "+\tТест с флагами '$flag1' '$flag2' '$flag3' и файлом '$file' пройден"
    else
        echo "-\tТест с флагами '$flag1' '$flag2' '$flag3' и файлом '$file' не пройден"
        echo "Различия:"
        diff $s21grep_output $grep_output
    fi
}

run_test -e wh test1.txt
run_test -i wh test1.txt
run_test -v wh test1.txt
run_test -c wh test1.txt
run_test -l wh test1.txt
run_test -n wh test1.txt

run_test -e wh test2.txt
run_test -i wh test2.txt
run_test -v wh test2.txt
run_test -c wh test2.txt
run_test -l wh test2.txt
run_test -n wh test2.txt

run_test -e wh test3.txt
run_test -i wh test3.txt
run_test -v wh test3.txt
run_test -c wh test3.txt
run_test -l wh test3.txt
run_test -n wh test3.txt

run_test -iv wh test1.txt
run_test -in wh test1.txt
run_test -il wh test1.txt
run_test -ic wh test1.txt
run_test -vn wh test1.txt
run_test -vl wh test1.txt
run_test -vc wh test1.txt
run_test -nl wh test1.txt
run_test -nc wh test1.txt
run_test -lc wh test1.txt

run_test -iv wh test2.txt
run_test -in wh test2.txt
run_test -il wh test2.txt
run_test -ic wh test2.txt
run_test -vn wh test2.txt
run_test -vl wh test2.txt
run_test -vc wh test2.txt
run_test -nl wh test2.txt
run_test -nc wh test2.txt
run_test -lc wh test2.txt

run_test -iv wh test3.txt
run_test -in wh test3.txt
run_test -il wh test3.txt
run_test -ic wh test3.txt
run_test -vn wh test3.txt
run_test -vl wh test3.txt
run_test -vc wh test3.txt
run_test -nl wh test3.txt
run_test -nc wh test3.txt
run_test -lc wh test3.txt

run_test_2e -e wh -e of -i test1.txt
run_test_2e -e wh -e of -v test1.txt
run_test_2e -e wh -e of -c test1.txt
run_test_2e -e wh -e of -l test1.txt
run_test_2e -e wh -e of -n test1.txt
run_test_2e -e wh -e of -iv test1.txt
run_test_2e -e wh -e of -ic test1.txt
run_test_2e -e wh -e of -il test1.txt
run_test_2e -e wh -e of -in test1.txt
run_test_2e -e wh -e of -vc test1.txt
run_test_2e -e wh -e of -vl test1.txt
run_test_2e -e wh -e of -vn test1.txt
run_test_2e -e wh -e of -cl test1.txt
run_test_2e -e wh -e of -cn test1.txt
run_test_2e -e wh -e of -ln test1.txt

run_test_2e -e wh -e of -i test2.txt
run_test_2e -e wh -e of -v test2.txt
run_test_2e -e wh -e of -c test2.txt
run_test_2e -e wh -e of -l test2.txt
run_test_2e -e wh -e of -n test2.txt
run_test_2e -e wh -e of -iv test2.txt
run_test_2e -e wh -e of -ic test2.txt
run_test_2e -e wh -e of -il test2.txt
run_test_2e -e wh -e of -in test2.txt
run_test_2e -e wh -e of -vc test2.txt
run_test_2e -e wh -e of -vl test2.txt
run_test_2e -e wh -e of -vn test2.txt
run_test_2e -e wh -e of -cl test2.txt
run_test_2e -e wh -e of -cn test2.txt
run_test_2e -e wh -e of -ln test2.txt

run_test_2e -e wh -e of -i test3.txt
run_test_2e -e wh -e of -v test3.txt
run_test_2e -e wh -e of -c test3.txt
run_test_2e -e wh -e of -l test3.txt
run_test_2e -e wh -e of -n test3.txt
run_test_2e -e wh -e of -iv test3.txt
run_test_2e -e wh -e of -ic test3.txt
run_test_2e -e wh -e of -il test3.txt
run_test_2e -e wh -e of -in test3.txt
run_test_2e -e wh -e of -vc test3.txt
run_test_2e -e wh -e of -vl test3.txt
run_test_2e -e wh -e of -vn test3.txt
run_test_2e -e wh -e of -cl test3.txt
run_test_2e -e wh -e of -cn test3.txt
run_test_2e -e wh -e of -ln test3.txt

rm -f s21grep_output.txt grep_output.txt