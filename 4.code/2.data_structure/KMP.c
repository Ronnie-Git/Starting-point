/*************************************************************************
	> File Name: KMP.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月04日 星期五 20时37分15秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100010

void get_next(char *pattern, int *next) {
    next[0] = -1;
    for (int i = 1, match = -1; pattern[i]; i++) {
        while (match >= 0 && pattern[match + 1] != pattern[i]) {
            match = next[match];
        }
        if (pattern[match + 1] == pattern[i]) {
            match += 1;
        }
        next[i] = match;
    }
    return ;
}

int find(char *buffer, char *pattern, int *next) {
    for (int i = 0, match = -1; i < strlen(buffer); i++) {
        while (match >= 0 && pattern[match + 1] != buffer[i]) {
            match = next[match];
        }
        if (pattern[match + 1] == buffer[i]) {
            match += 1;
        }
        if (match == strlen(pattern) - 1) {
            return i - match;
        }
    }
    return -1;
}

int main() {
    char buffer[MAX_LEN] = {0};
    char pattern[MAX_LEN] = {0};
    int next[MAX_LEN] = {0};
    scanf("%s", buffer);
    scanf("%s", pattern);
    get_next(pattern, next);
    int ans = find(buffer, pattern, next);
    if (ans != -1) {
        printf("Yes\n%d\n", ans);
    } else {
        printf("No\n");
    }
    return 0;
}
