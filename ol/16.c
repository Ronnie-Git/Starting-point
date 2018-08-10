/*************************************************************************
	> File Name: 16.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 00时42分32秒
 ************************************************************************/

#include<stdio.h>

int ans[350] = {4, 4, 2, 0, 1};//倒序

int main() {
    int sum = 0;
    for (int i = 1; i < 100; ++i) {
        for (int j = 1; j <= ans[0]; ++j) {
            ans[j] *= 1024;//按位乘1024
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);//记位数
        }
    }
    for (int i = 1; i <= ans[0]; i++) {
        sum += ans[i];//位数求和
    }
    printf("%d\n", sum);
    return 0;
}
