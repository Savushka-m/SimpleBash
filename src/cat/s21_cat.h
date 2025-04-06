#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flags {
  int b;  // нумерация непустых строк
  int E;  // отображает символы конца строки как $
  int n;  // нумерует все строки
  int s;  // сжимает несколько смежных пустых строк
  int T;  // отображает табы как ^I
  int v;  // показывает непечатаемые символы, кроме \t и \n
};

const struct option long_options[] = {
    {"number-nonblank", 0, 0, 'n'}, {"show-ends", 0, 0, 'e'},
    {"number", 0, 0, 'n'},          {"squeeze-blank", 0, 0, 's'},
    {"show-tabs", 0, 0, 't'},       {0, 0, 0, 0}};

void enabling_flags(int *rez, struct flags *my_flags);
void print_file(char *file_name, struct flags my_flags);
void use_flags(int count_line_break, char *letter, char *prev_letter,
               int *line_number, struct flags my_flags);
