/*************************************************************************
	> File Name: a.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月30日 星期日 10时55分11秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get(char *filename, char *name, char *v) {
    FILE *fd = fopen(filename, "r");
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    while ((read = getline(&line, &len, fd)) != -1) {
        char *str = strstr(line, name);
        if(str) {
            char *str1 = strstr(line, "=");
            if(!str1) {
                printf("csdcdsi\n");
                continue;
            }
            
            strncpy(v, line + strlen(name) + 1, strlen(line) - strlen(name) - 1);
            printf("%s", v);
            
            char *p = strstr(line, "\n");
            if(p) {
                v[strlen(v) - 1] = '\0';
            }
            printf("%s", v);
            fclose(fd);
            return 1;
        }
    }
    free(line);
    fclose(fd);
    return 0;
}

int main() {
    char port[100] = {0};
    char num[1000] = {0};
    char ip[1000] = {0};
    int k;
    k = get("common.conf", "port", port);
    k = get("common.conf", "ip", ip);
    k = get("common.conf", "num", num);
    printf("%s%s%s", port, ip, num);
    return 0;
}
