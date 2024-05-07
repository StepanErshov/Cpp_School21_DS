#include "s21_cat.h"

int main(int argc, char **args) {
  unsigned int options = 0;
  int status;
  status = parse_options(argc, args, &options);
  if (status == OK) {
    for (int i = optind; i < argc; i++) {
      char *filename = args[i];
      if (process_file(filename, options) == FILE_ERROR) {
        print_file_error(filename);
      }
    }
  }
  if (status == FLAG_ERROR) {
    print_arg_error();
  }
  return status;
}

int process_file(char *filename, unsigned int options) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("s21_cat: ");
    return FILE_ERROR;
  }
  int character;
  unsigned int new_line_indicator = TRUE;
  unsigned int line_number = 1;
  unsigned int new_line_count = 0;
  while ((character = fgetc(file))!= EOF) {
    if (!IS_NEW_LINE(character) && new_line_indicator == TRUE &&
        (IS_OPTION_LINE(options) || IS_OPTION_NONBLANK(options))) {
      printf("%6u\t", line_number++);
    }
    if (IS_NEW_LINE(character) && new_line_indicator == TRUE && IS_OPTION_NONBLANK(options)) {
      printf("%6u\t", line_number++);
      new_line_indicator = FALSE;
    }
    if ((IS_SPECIAL_CHAR(character) && IS_OPTION_VERBOSE(options)) ||
        (IS_TAB_CHAR(character) && IS_OPTION_TAB(options))) {
      new_line_indicator = FALSE;
      new_line_count = 0;
      if (character > 127) printf("^%c", character >= 32? character - '@' : character + '@');
      else printf("^%c", character >= 32? character - '@' : character + '@');
    } else if (IS_NEW_LINE(character)) {
      if (new_line_count < 2) {
        new_line_indicator = TRUE;
        if (IS_OPTION_END_OF_LINE(options)) {
          printf("$\n");
        } else {
          printf("\n");
        }
      }
      if (IS_OPTION_SQUEEZE_BLANK(options)) new_line_count++;
    } else {
      new_line_count = 0;
      new_line_indicator = FALSE;
      printf("%c", character);
    }
  }
  fclose(file);
  return OK;
}

int parse_options(int argc, char **args, unsigned int *options) {
  int getopt_result = 0;
  int status = OK;
  struct option long_options[] = {{"number", 0, 0, 'n'},
                                  {"squeeze-blank", 0, 0, 's'},
                                  {"number-nonblank", 0, 0, 'b'},
                                  {0, 0, 0, 0}};
  while (getopt_result > -1 && status == OK) {
    int option_index = 0;
    getopt_result = getopt_long(argc, args, "+beEnstTv", long_options, &option_index);
    status = process_option(options, getopt_result);
  }
  return status;
}

int process_option(unsigned int *options, int getopt_result) {
  int status = OK;
  if (getopt_result == 'b') {
    *options |= OPTION_LINE;
    if (IS_OPTION_NONBLANK(*options)) {
      *options &= ~OPTION_NONBLANK;
    }
  } else if (getopt_result == 'e') {
    *options |= OPTION_VERBOSE;
    *options |= OPTION_END_OF_LINE;
  } else if (getopt_result == 'E') {
    *options |= OPTION_END_OF_LINE;
  } else if (getopt_result == 'n') {
    if (!(IS_OPTION_LINE(*options))) {
      *options |= OPTION_NONBLANK;
    }
  } else if (getopt_result == 's') {
    *options |= OPTION_SQUEEZE_BLANK;
  } else if (getopt_result == 't') {
    *options |= OPTION_VERBOSE;
    *options |= OPTION_TAB;
  } else if (getopt_result == 'T') {
    *options |= OPTION_TAB;
  } else if (getopt_result == 'v') {
    *options |= OPTION_VERBOSE;
  } else if (getopt_result == '?') {
    status = FLAG_ERROR;
  }
  return status;
}

void print_arg_error() {
  fprintf(stderr, "usage: s21_cat [-beEnstTv] [file...]\n");
}

void print_file_error(char *filename) {
  fprintf(stderr, "s21_cat: %s: No such file or directory\n", filename);
}
