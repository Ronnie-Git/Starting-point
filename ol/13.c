/*************************************************************************
	> File Name: 13.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 00时33分19秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>

char num[55];//大整数
int ans[55] = {1, 0};

int main() {
    for (int i = 0; i < 100; ++i) {//通用的大数框架
        scanf("%s", num);
        int len = strlen(num);
        if (ans[0] < len) ans[0] = len;
        for (int j = 0; j < len; ++j) {
            ans[len - j] += (num[j] - '0');
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);//记位数
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
