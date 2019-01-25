/*************************************************************************
	> File Name: 6.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月25日 星期五 09时11分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int KMP(int *str, int *pattern, int n, int m) {
    int *next = (int *)malloc(sizeof(int) * m);
    next[0] = -1;
    for (int i = 1; i < m; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while (i < n) {
        while (j != -1 && str[i] != pattern[j + 1]) j = next[j];
        if (str[i] == pattern[j + 1]) {
            j += 1;
        }
        i += 1;
        if (j + 1 == m) return i - m + 1;
    }
    return -1;
}

#define MAX_N 1000000
int num1[MAX_N + 5] = {0};
int num2[MAX_N + 5] = {0};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", &num1[i]);
        for (int i = 0; i < m; i++) scanf("%d", &num2[i]);
        printf("%d\n", KMP(num1, num2, n, m));
    }
    return 0;
}
