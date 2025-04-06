FLAGS=gcc -std=c11 -Wall -Wextra -Werror
NAME=s21_grep
CC=gcc

all: s21_grep

s21_grep: s21_grep.c
	$(FLAGS) s21_grep.c -o $(NAME)

rebuild: clean s21_grep

clean:
	rm $(NAME)