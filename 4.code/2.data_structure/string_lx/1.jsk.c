/*************************************************************************
	> File Name: 1.jsk.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月15日 星期二 15时16分21秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 1000000
#define MAX_M 1000 

int KMP(char *str1, char *str2, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    for (int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }

    int i = 0, j = -1;
    while (str1[i] && str2[i]) {
        while (j != -1 && (str1[i] != pattern[j + 1] || str2[i] != pattern[j + 1])) j = next[j];
        if (str1[i] == pattern[j + 1] && str2[i] == pattern[j + 1]) {
            j += 1;
        }
        i += 1;
        if (pattern[j + 1] == 0) return i - strlen(pattern) + 1;
    }
    return 0;
}

int main() {
    char str1[MAX_N + 5] = {0}, str2[MAX_N + 5] = {0}, pattern[MAX_M + 5] = {0};
    scanf("%[^\n]s", str1);
    getchar();
    scanf("%[^\n]s", str2);
    getchar();
    scanf("%[^\n]s", pattern);
    getchar();
    printf("%d\n", KMP(str1, str2, pattern));
    return 0;
}
