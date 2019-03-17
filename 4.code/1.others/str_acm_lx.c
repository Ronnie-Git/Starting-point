/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月01日 星期六 10时33分19秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char *str) {
    char temp[100] = {0};
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        temp[i] = str[len - i - 1];
    }
    return strcmp(str, temp) == 0;
}

int main() {
    char str[100] = {0};
    scanf("%[^\n]s", str);
    printf("%s\n", check(str) ? "YES" : "NO");
    return 0;
}
