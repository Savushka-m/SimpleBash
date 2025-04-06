FLAGS=gcc -std=c11 -Wall -Wextra -Werror
NAME=s21_cat
CC=gcc

all: s21_cat

s21_cat: s21_cat.c
	$(FLAGS) s21_cat.c -o $(NAME)

rebuild: clean s21_cat

clean:
	rm $(NAME)