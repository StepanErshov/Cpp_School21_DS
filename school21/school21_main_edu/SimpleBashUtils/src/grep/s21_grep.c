#include "s21_grep.h"

int main(int argc, char *argv[]) {
  struct grep_flags flags = {0};
  char patternBuffer[BUFFER_SIZE] = {0};
  parseFlags(argc, argv, &flags, patternBuffer);
  if (argc >= 3) searchFiles(&flags, argc, argv, patternBuffer);
  return 0;
}

void parseFlags(int argc, char **argv, struct grep_flags *flags,
                char *patternBuffer) {
  int optIndex = 0;
  const char *optionChars = "e:ivclnhsf:o";
  while ((optIndex = getopt(argc, argv, optionChars)) != -1) {
    switch (optIndex) {
      case 'e':
        flags->e = 1;
        snprintf(patternBuffer, BUFFER_SIZE, "%s", optarg);
        break;
      case 'i':
        flags->i = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      case 'c':
        flags->c = 1;
        break;
      case 'l':
        flags->l = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 'h':
        flags->h = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'f':
        flags->f = 1;
        snprintf(patternBuffer, BUFFER_SIZE, "%s", optarg);
        break;
      case 'o':
        flags->o = 1;
        break;
      default:
        printf("error\n");
        break;
    }
  }
}

void searchFiles(struct grep_flags *flags, int argc, char **argv,
                 char *patternBuffer) {
  char pattern[BUFFER_SIZE] = {0};
  int filePatternIndex = 0;
  if (!flags->f && !flags->e)
    snprintf(pattern, BUFFER_SIZE, "%s", argv[optind++]);
  if (flags->f) filePatternIndex = processFilePattern(pattern, patternBuffer);
  if (!flags->f && flags->e)
    snprintf(pattern, BUFFER_SIZE, "%s", patternBuffer);
  if (filePatternIndex != -1) {
    int fileCount = 0;
    if (argc - optind > 1) fileCount = 1;
    for (int i = optind; i < argc; i++) {
      if (fileCount && !flags->h && !flags->l) printf("%s:", argv[i]);
      searchFile(flags, pattern, argv[i]);
    }
  }
}

int processFilePattern(char *pattern, char *tempPattern) {
  FILE *file;
  int patternLength = 0;
  file = fopen(tempPattern, "r");
  if (file != NULL) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
      if (ch == 13 || ch == 10) pattern[patternLength++] = '|';
      if (ch != 13 && ch != 10) pattern[patternLength++] = ch;
    }
    fclose(file);
  } else {
    printf("error\n");
    patternLength = -1;
  }
  if (pattern[patternLength - 1] == '|') pattern[patternLength - 1] = '\0';
  return patternLength;
}

void searchFile(struct grep_flags *flags, char *pattern, char *filename) {
  int regexFlags = REG_EXTENDED;
  regex_t regex;
  FILE *file;
  file = fopen(filename, "r");
  if (flags->i || flags->e) regexFlags = REG_ICASE;
  if (file != NULL) {
    regcomp(&regex, pattern, regexFlags);
    processFileContent(flags, file, regex, filename);
    regfree(&regex);
    fclose(file);
  }
}

void processFileContent(struct grep_flags *flags, FILE *file, regex_t regex,
                        char *filename) {
  char fileContent[BUFFER_SIZE] = {0};
  regmatch_t match[1];
  int lineMatches = 0, lineNumber = 1;
  while (fgets(fileContent, BUFFER_SIZE - 1, file) != NULL) {
    int matchFound = 0;
    int regexResult = regexec(&regex, fileContent, 1, match, 0);
    if (strchr(fileContent, '\n') == NULL) strcat(fileContent, "\n");
    if (regexResult == 0 && !flags->v) matchFound = 1;
    if (regexResult == REG_NOMATCH && flags->v) matchFound = 1;
    if (matchFound && !flags->l && !flags->c && flags->n)
      printf("%d:", lineNumber);
    if (matchFound && !flags->l && !flags->c && !flags->o)
      printf("%s", fileContent);
    if (matchFound && flags->o) {
      for (int i = match[0].rm_so; i < match[0].rm_eo; i++) {
        printf("%c", fileContent[i]);
      }
      printf("\n");
    }
    lineMatches += matchFound;
    lineNumber++;
  }
  if (flags->l && lineMatches > 0) printf("%s\n", filename);
  if (flags->c && !flags->l) printf("%d\n", lineMatches);
}
