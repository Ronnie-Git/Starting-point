/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月20日 星期二 19时04分27秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100] = {0}, k[100] = {0};
    scanf("%s", str);
    scanf("%s", k);
    char *temp = strtok(str, k);
    while (temp) {
        printf("%s", temp);
        temp = strtok(NULL, k);
    }
    return 0;
}
