/*************************************************************************
	> File Name: pihealthlog.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月03日 星期三 15时54分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int write_pi_log(char *PiHealthLog, const char *format, ...) {
    int done;
    FILE *fp = fopen(PiHealthLog, "a+");
    va_list arg;

    va_start(arg, format);

    time_t time_log = time(NULL);
    struct tm* tm_log = localtime(&time_log);
    fprintf(fp, "%04d-%02d-%02d %02d:%02d:%02d ", tm_log->tm_year + 1900, tm_log->tm_mon + 1, tm_log->tm_mday, tm_log->tm_hour, tm_log->tm_min, tm_log->tm_sec);

    done = vfprintf(fp, format, arg);
    va_end(arg);

    fflush(fp);
    fclose(fp);
    return done;
}

int main() {
    write_pi_log("b", "Connection to %s success\n", "192.168.2.174");
    return 0;
}
