#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>

#include "log_levels.h"

void log_init(FILE *log_file);
void logcat(FILE *log_file, char *message, enum log_level level);
void log_close(FILE *log_file);

#endif
