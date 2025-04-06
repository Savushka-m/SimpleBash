#include "s21_grep.h"

int main(int argc, char *argv[]) {
  struct flags my_flags = {0};
  int rez;
  while ((rez = getopt_long(argc, argv, "e:ivcln", long_options, 0)) != -1) {
    enabling_flags(&rez, &my_flags);
  }
  if (my_flags.e == 0) {
    strncpy(my_flags.patterns[my_flags.index], argv[optind], 1000);
    my_flags.index += 1;
    optind += 1;
  }
  for (int i = optind; i < argc; i++) {
    char *file_name = argv[i];
    print_file(file_name, &my_flags);
  }
  return 0;
}

void enabling_flags(int *rez, struct flags *my_flags) {
  switch (*rez) {
    case 'e':
      my_flags->e = 1;
      strncpy(my_flags->patterns[my_flags->index], optarg, 1000);
      my_flags->index += 1;
      break;
    case 'i':
      my_flags->i = 1;
      break;
    case 'v':
      my_flags->v = 1;
      break;
    case 'c':
      my_flags->c = 1;
      break;
    case 'l':
      my_flags->l = 1;
      break;
    case 'n':
      my_flags->n = 1;
      break;
    case '?':
      printf("%s", "Wrong flag\n");
      return;
      break;
  }
}

void print_file(char *file_name, struct flags *my_flags) {
  int line_number = 0;
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Wrong file name");
    return;
  }
  char buffer[4000];
  int l_flag = 0;
  while (fgets(buffer, 4000, file) != NULL) {
    int is_match = check_match(buffer, my_flags);
    if (use_flags(is_match, my_flags, &line_number)) {
      if (my_flags->l) {
        l_flag = 1;
      } else {
        if (!(my_flags->c)) {
          printf("%s", buffer);
          if (strchr(buffer, '\n') == NULL) {
            printf("%c", '\n');
          }
        }
      }
    }
  }
  if (my_flags->l && l_flag == 1) {
    printf("%s\n", file_name);
  } else if (my_flags->c) {
    printf("%d\n", line_number);
  }
}

int check_match(char *buffer, struct flags *my_flags) {
  int cflags = REG_EXTENDED;
  int flag = 0;
  if (my_flags->i) {
    cflags = REG_ICASE;
  }
  for (int i = 0; i < my_flags->index; i++) {
    regex_t reg;
    regcomp(&reg, my_flags->patterns[i], cflags);
    if (regexec(&reg, buffer, 0, NULL, 0) == 0) {
      flag = 1;
    }
    regfree(&reg);
  }
  return flag;
}

int use_flags(int is_match, struct flags *my_flags, int *line_number) {
  if (my_flags->c) {
    if (is_match ^ my_flags->v) {
      *line_number += 1;
    }
    return 1;
  }
  if (my_flags->n) {
    *line_number += 1;
  }
  if (is_match) {
    if (my_flags->v) {
      return 0;
    }
    if (my_flags->n && !(my_flags->l)) {
      printf("%d:", *line_number);
    }
    return 1;
  } else {
    if (my_flags->v) {
      if (my_flags->n && !(my_flags->l)) {
        printf("%d:", *line_number);
      }
      return 1;
    }
    return 0;
  }
}