/*************************************************************************
	> File Name: main_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月04日 星期四 16时41分01秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char *error_msg = NULL;

int app_name_valid(int argc, char *argv[]) {
    int i = strlen(argv[0]);
    while (i > 0 && argv[0][i - 1] != '/') --i;
    int ret = strcmp(argv[0] + i, "haizeix") == 0;
    error_msg = (char *)(ret ? NULL : "wrong app-name");
    return ret;
}

int user_name_valid(char **env) {
    int ret = 0;
    for (char ** p = env; p[0] != NULL; p++) {
        ret = ret || strcmp(p[0], "USER=x") == 0;
    }
    error_msg = (char *)(ret ? NULL : "wrong user-name");
    return ret;
}

int main(int argc, char *argv[], char **env) {
    if (app_name_valid(argc, argv) == 0) {
        fprintf(stderr, "%s\n", error_msg);
    }
    if (user_name_valid(env) == 0) {
        fprintf(stderr, "%s\n", error_msg);
    }
    printf("hello world\n");
    return 0;
}
