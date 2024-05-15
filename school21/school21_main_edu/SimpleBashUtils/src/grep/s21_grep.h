#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#define BUFFER_SIZE 5000
#define _GNU_SOURCE

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct grep_flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
};

void parseFlags(int argc, char **argv, struct grep_flags *flags,
                char *patternBuffer);
void searchFiles(struct grep_flags *flags, int argc, char **argv,
                 char *patternBuffer);
int processFilePattern(char *pattern, char *tempPattern);
void searchFile(struct grep_flags *flags, char *pattern, char *filename);
void processFileContent(struct grep_flags *flags, FILE *file, regex_t regex,
                        char *filename);

#endif  // SRC_GREP_S21_GREP_H_

