#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int b;
  int n;
  int s;
  int v;
  int t;
  int e;
} flags;

flags options = {0, 0, 0, 0, 0, 0};
void insert(int ind, char ins, char *text);
int print_file(char *filename);
void parse_flags(int argc, char **argv, flags *options);
void flag_e(FILE *stream);
void flag_n(FILE *stream);
void flag_T(FILE *stream);
void flag_b(FILE *stream);
char *flag_s(FILE *stream, char *buffer);
void printless(char c);
int string_number = 0;