#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "logger.h"

#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_LENGTH 1024

char filename[MAX_FILENAME_LENGTH] = "";

int read_and_display_file(const char *filename);
int append_text_to_file(const char *filename);
int encrypt_file(const char *filename, int shift);
int clean_file(const char *filename);

int main() {
    int choice, shift;

    do {
        scanf("%d", &choice);

        switch (choice) {
            case -1:
                break;
            case 1:
                scanf("%s", filename);
                read_and_display_file(filename);
                break;
            case 2:
                append_text_to_file(filename);
                break;
            case 3:
                scanf("%s", filename);
                scanf("%d", &shift);
                encrypt_file(filename, shift);
                clean_file(filename);
                break;
            default:
                printf("n/a");
                printf("\n");
                break;
        }
    } while (choice != -1);

    FILE *log_file = fopen("log.txt", "a+");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    log_init(log_file);
    logcat(log_file, "Файл «aaa.c» открыт", info);
    logcat(log_file, "В файл «bbb.h» записана строка", info);
    log_close(log_file);

    return 0;
}

int read_and_display_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("n/a\n");
        return 0;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    printf("\n");
    fclose(file);
    return 0;
}

int append_text_to_file(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        printf("n/a\n");
        return 0;
    }

    char text_to_append[MAX_TEXT_LENGTH];
    fflush(stdin);
    fgets(text_to_append, MAX_TEXT_LENGTH, stdin);

    fputs(text_to_append, file);

    fclose(file);

    file = freopen(filename, "r", file);
    if (!file) {
        printf("n/a\n");
        return 0;
    }
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    printf("\n");
    fclose(file);
    return 0;
}

int encrypt_file(const char *filename, int shift) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("n/a\n");
        return 0;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = (ch - 'A' + shift) % 26 + 'A';
            } else {
                ch = (ch - 'a' + shift) % 26 + 'a';
            }
        }
        putchar(ch);
    }

    fclose(file);
    return 0;
}

int clean_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("n/a\n");
        return 0;
    }

    fclose(file);
    return 0;
}
