#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#define _GNU_SOURCE

#include <getopt.h>
#include <stdio.h>

#define OPTION_LINE (1 << 0)
#define OPTION_END_OF_LINE (1 << 1)
#define OPTION_NONBLANK (1 << 2)
#define OPTION_SQUEEZE_BLANK (1 << 3)
#define OPTION_TAB (1 << 4)
#define OPTION_VERBOSE (1 << 5)
#define IS_OPTION_LINE(option) (option & OPTION_LINE)
#define IS_OPTION_END_OF_LINE(option) (option & OPTION_END_OF_LINE)
#define IS_OPTION_NONBLANK(option) (option & OPTION_NONBLANK)
#define IS_OPTION_SQUEEZE_BLANK(option) (option & OPTION_SQUEEZE_BLANK)
#define IS_OPTION_TAB(option) (option & OPTION_TAB)
#define IS_OPTION_VERBOSE(option) (option & OPTION_VERBOSE)
#define TRUE 1
#define FALSE 0

#define IS_SPECIAL_CHAR(ch) (((ch) >= 0 && (ch) <= 8) || ((ch) >= 11 && (ch) <= 31) || ((ch) >= 127 && (ch) <= 159))
#define IS_TAB_CHAR(ch) (((ch) == '\t'))
#define IS_NEW_LINE(ch) (((ch) == '\n'))

enum { OK, FLAG_ERROR, FILE_ERROR };

int parse_options(int argc, char **args, unsigned int *options);
int process_option(unsigned int *options, int getopt_result);
int process_file(char *filename, unsigned int options);
void print_arg_error();
void print_file_error(char *filename);

#endif  // SRC_CAT_S21_CAT_H_
