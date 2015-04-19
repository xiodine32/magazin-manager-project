//
// Created by xiodine on 4/15/15.
//

#include "log.h"
#include <stdio.h>
#include <stdarg.h>

bool LOG_TOGGLE = false;

void log_nomacro(const char *type, const char *function, int line, const char *a, ...) {
    FILE *f = stdout;
    if (LOG_TOGGLE)
        f = fopen("log.log", "a");
    #ifndef DEBUG
        if (!LOG_TOGGLE) {
            f = fopen("log.log", "a");
        }
    #endif
    va_list lst;
    va_start(lst, a);
    fprintf(f, "[%s - %s : %d]: ", type, function, line);
    vfprintf(f, a, lst);
    fprintf(f, "\n");
    fflush(f);
    if (LOG_TOGGLE) {
        fclose(f);
    }
    #ifndef DEBUG
        if (!LOG_TOGGLE) {
            fclose(f);
        }
    #endif
}