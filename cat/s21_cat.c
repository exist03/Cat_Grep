#include "s21_cat.h"

int main(int argc, char **argv) {
  parse_flags(argc, argv, &options);
  while (optind < argc) {
    if (!print_file(argv[optind]))
      printf("%s: file doesn`t exist\n", argv[optind]);
    optind++;
  }
  return 0;
}

int print_file(char *filename) {
  int result;
  FILE *stream;
  stream = fopen(filename, "r");
  !stream ? (result = 0) : (result = 1);
  char ch;
  int n_count = 1;
  while (result && (ch = fgetc(stream)) != EOF) {
    if (ch == '\n' && options.s && n_count >= 2) continue;
    if (n_count && (options.n || (options.b && ch != '\n')))
      printf("%6d\t", ++string_number);
    if (ch == '\n' && options.e) printf("$");
    if (ch == '\t' && options.t)
      printf("^I");
    else {
      ch != '\n' ? n_count = 0 : n_count++;
      (options.v) ? printless(ch) : printf("%c", ch);
    }
  }
  if (result) fclose(stream);
  return result;
}

void parse_flags(int argc, char **argv, flags *options) {
  int rez = 0;
  const char *short_options = "beEnstTv";
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};
  int option_index;
  while ((rez = getopt_long(argc, argv, short_options, long_options,
                            &option_index)) != -1) {
    switch (rez) {
      case 'b':
        options->b = 1;
        break;
      case 'e':
        options->e = 1;
        options->v = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'E':
        options->e = 1;
        break;
      case 'T':
        options->t = 1;
        break;
      case '?':
        printf("Error found !\n");
        break;
    }
  }
  if (options->b) {
    options->n = 0;
  }
}

void printless(char c) {
  if (c < -96)
    printf("M-^%c", c + 192);
  else if (c < 0)
    printf("M-%c", c + 128);
  else if (c == 9 || c == 10)
    printf("%c", c);
  else if (c < 32)
    printf("^%c", c + 64);
  else if (c < 127)
    printf("%c", c);
  else
    printf("^?");
}