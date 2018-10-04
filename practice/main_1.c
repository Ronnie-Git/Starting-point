/*************************************************************************
	> File Name: main_lx.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月04日 星期四 15时42分54秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *env[]) {
    int flag = 0, m;
    char *n = argv[0];
    for (int i = 0; i < strlen(argv[0]); i++) {
        if (argv[0][i] == '/') m = i;
    }
    if (strcmp(n + m + 1, "haizeix")) return 0;
    for (char **p = env; p[0] != NULL; p++) {
        if (strcmp(p[0], "USER=x") == 0) flag = 1;
    }
    if(!flag) return 0;
    printf("hello world!\n");
    return 0;
}
