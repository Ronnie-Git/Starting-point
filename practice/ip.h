/*************************************************************************
	> File Name: a.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月30日 星期日 10时55分11秒
 ************************************************************************/

#include <string.h>

int get_IP(char *filename, int cnt, char *v) {
    FILE *fd = fopen(filename, "r");
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    int i = 0;
    while ((read = getline(&line, &len, fd)) != -1) {
        if (i == cnt) {
            strncpy(v, line, strlen(line) - 1);
        }
        i++;
    }
    free(line);
    fclose(fd);
    return 0;
}
