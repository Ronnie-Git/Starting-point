/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月08日 星期二 09时20分25秒
 ************************************************************************/

#include <stdio.h>

int main() {
    char arr[10000] = {0}, ans[50] = {0};
    char c;
    int len = 1, ind = 1, cnt = 0;
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') break;
        if (c == ' ') continue;
        arr[len++] = c;
    }
    while (ind < len) {
        for (int i = ind; i < ind << 1; i++) {
            if (arr[i] >= '0' && arr[i] <= '9') {
                ans[cnt++] = arr[i];
                break;
            }
        }
        ind <<= 1;
    }
    for (int i = 0; i < cnt; i++) {
        if (i != 0) printf(" ");
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}
