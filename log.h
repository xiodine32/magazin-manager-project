//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_LOG_H
#define POO_2_LOG_H

#define d(a...) log_nomacro("DEBUG", __FUNCTION__, __LINE__, a)
#define w(a...) log_nomacro("WARNING", __FUNCTION__, __LINE__, a)
#define e(a...) log_nomacro("ERROR", __FUNCTION__, __LINE__, a)

void log_nomacro(const char *type, const char *function, int line, const char *a, ...);



#endif //POO_2_LOG_H
