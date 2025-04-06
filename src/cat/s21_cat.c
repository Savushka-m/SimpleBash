#include "s21_cat.h"

int main(int argc, char *argv[]) {
  struct flags my_flags = {0};
  int rez;
  while ((rez = getopt_long(argc, argv, "vbeEnstT", long_options, 0)) != -1) {
    enabling_flags(&rez, &my_flags);
  }
  for (int i = optind; i < argc; i++) {
    print_file(argv[i], my_flags);
  }
  return 0;
}

void enabling_flags(int *rez, struct flags *my_flags) {
  switch (*rez) {
    case 'b':
      my_flags->b = 1;
      break;
    case 'e':
      my_flags->E = 1;
      my_flags->v = 1;
      break;
    case 'E':
      my_flags->E = 1;
      break;
    case 'n':
      my_flags->n = 1;
      break;
    case 's':
      my_flags->s = 1;
      break;
    case 't':
      my_flags->T = 1;
      my_flags->v = 1;
      break;
    case 'T':
      my_flags->T = 1;
      break;
    case 'v':
      my_flags->v = 1;
      break;
    case '?':
      printf("%s", "Wrong flag");
      return;
      break;
  }
}

void print_file(char *file_name, struct flags my_flags) {
  int line_number = 1;
  int count_line_break = 0;
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Wrong file name");
    return;
  }
  char letter = fgetc(file);
  char prev_letter = '\n';
  while (letter != EOF) {
    use_flags(count_line_break, &letter, &prev_letter, &line_number, my_flags);
    if (my_flags.s) {
      if (prev_letter == '\n' && letter == '\n') {
        count_line_break += 1;
      } else {
        count_line_break = 0;
      }
    }
    if (!(letter == '\n' && count_line_break >= 2)) {
      if (!(my_flags.T && letter == '\t')) {
        printf("%c", letter);
      }
    }
    prev_letter = letter;
    letter = fgetc(file);
  }
  fclose(file);
}

void use_flags(int count_line_break, char *letter, char *prev_letter,
               int *line_number, struct flags my_flags) {
  if (my_flags.b) {
    if (*prev_letter == '\n' && *letter != '\n') {
      printf("%6d\t", *line_number);
      (*line_number)++;
    }
  } else if (my_flags.n) {
    if (*prev_letter == '\n' && count_line_break < 2) {
      printf("%6d\t", *line_number);
      (*line_number)++;
    }
  }
  if (my_flags.E) {
    if (*letter == '\n') {
      printf("%c", '$');
    }
  }
  if (my_flags.T) {
    if (*letter == '\t') {
      printf("%s", "^I");
    }
  }
  if (my_flags.v) {
    if (*letter >= 0 && *letter < 32 && *letter != '\n' && *letter != '\t') {
      printf("%c", '^');
      printf("%c", (*letter) + 64);
    }
    if (*letter == 127) {
      printf("%c", '?');
    }
  }
}