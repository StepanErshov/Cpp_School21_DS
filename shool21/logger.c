#include "logger.h"

#include <stdlib.h>

#include "log_levels.h"

void log_init(FILE *log_file) {
    time_t now = time(NULL);
    struct tm *time_info = localtime(&now);
    char time_buffer[20];
    strftime(time_buffer, 20, "%Y-%m-%d %H:%M:%S", time_info);

    log_file = fopen("log.txt", "w");
    if (log_file == NULL) {
        printf("Не удалось открыть файл лога\n");
        exit(1);
    }

    fprintf(log_file, "%s\n", time_buffer);
}

void logcat(FILE *log_file, char *message, enum log_level level) {
    time_t now = time(NULL);
    struct tm *time_info = localtime(&now);
    char time_buffer[20];
    strftime(time_buffer, 20, "%Y-%m-%d %H:%M:%S", time_info);

    switch (level) {
        case debug:
            fprintf(log_file, "%s [DEBUG] %s\n", time_buffer, message);
            break;
        case info:
            fprintf(log_file, "%s [INFO] %s\n", time_buffer, message);
            break;
        case warning:
            fprintf(log_file, "%s [WARNING] %s\n", time_buffer, message);
            break;
        case error:
            fprintf(log_file, "%s [ERROR] %s\n", time_buffer, message);
            break;
        case trace:
            fprintf(log_file, "%s [TRACE] %s\n", time_buffer, message);
            break;
        default:
            fprintf(log_file, "%s %s\n", time_buffer, message);
            break;
    }
    fprintf(log_file, "%s %s\n", time_buffer, message);
}

void log_close(FILE *log_file) { fclose(log_file); }

