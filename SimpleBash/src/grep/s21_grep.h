#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flags {
  int e;  //+ шаблон
  int i;  //+ игнорирует различие регистра
  int v;  //+ инвертирует смысл поиска
  int c;  //+ выводит только количество совпадающих строк
  int l;  //+ выводит только совпадающие файлы
  int n;  //+ предваряет каждую строку вывода номером строки из файла вывода
  char patterns[1000][1000];  //+ храним паттерны
  int index;  //+ количество записанных паттернов
};

const struct option long_options[] = {
    {0, 0, 0, 'e'}, {0, 0, 0, 'i'}, {0, 0, 0, 'v'}, {0, 0, 0, 'c'},
    {0, 0, 0, 'l'}, {0, 0, 0, 'n'}, {0, 0, 0, 0}};

void enabling_flags(int *rez, struct flags *my_flags);
void print_file(char *file_name, struct flags *my_flags);
int use_flags(int is_match, struct flags *my_flags, int *line_number);
int check_match(char *buffer, struct flags *my_flags);