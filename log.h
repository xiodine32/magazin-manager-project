//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_LOG_H
#define POO_2_LOG_H

//#define LOG_HIDE

#ifndef LOG_HIDE
#define d(a...) log_nomacro("DEBUG", __FUNCTION__, __LINE__, a)
#define w(a...) log_nomacro("WARNING", __FUNCTION__, __LINE__, a)
#define e(a...) log_nomacro("ERROR", __FUNCTION__, __LINE__, a)
#else
#define d(a...) ;
#define w(a...) ;
#define e(a...) ;

#endif

void log_nomacro(const char *type, const char *function, int line, const char *a, ...);

extern bool LOG_TOGGLE;

#endif //POO_2_LOG_H
