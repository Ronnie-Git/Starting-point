/*************************************************************************
	> File Name: p1012.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月30日 星期五 17时48分29秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_str(char *a, char *b) {
    char *ret = (char *)malloc(sizeof(char) * 50);
    strcpy(ret, a);
    strncpy(ret + strlen(a), b, strlen(b));
    return ret;
}

void b_sort(char num[][20], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            char *a = get_str(num[j], num[j + 1]);
            char *b = get_str(num[j + 1], num[j]);
            if (strcmp(a, b) > 0) {
                free(a);
                free(b);
                continue;
            }
            char t[20] = {0};
            strcpy(t, num[j]);
            strcpy(num[j], num[j + 1]);
            strcpy(num[j + 1], t);
            flag = 1;
            free(a);
            free(b);
        }
        if (!flag) break;
    }
    return ;
}

int main() {
    int n;
    char num[25][20] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", num[i]);
    }
    b_sort(num, n);
    for (int i = 0; i < n; i++) {
        printf("%s", num[i]);
    }
    printf("\n");
    return 0;
}
