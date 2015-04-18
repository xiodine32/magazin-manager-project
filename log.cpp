//
// Created by xiodine on 4/15/15.
//

#include "log.h"
#include <stdio.h>
#include <stdarg.h>

void log_nomacro(const char *type, const char *function, int line, const char *a, ...) {
    FILE *f = stdout;
    #ifndef DEBUG
        f = fopen("log.log", "a");
    #endif
    va_list lst;
    va_start(lst, a);
    fprintf(f, "[%s - %s : %d]: ", type, function, line);
    vfprintf(f, a, lst);
    fprintf(f, "\n");
    fflush(f);
    #ifndef DEBUG
        fclose(f);
    #endif
}