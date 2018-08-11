/*************************************************************************
	> File Name: 34.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月23日 星期一 00时04分28秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 2540160

int num[15] = {1}; // 0的阶乘是1

void init() { // 求1～9的阶乘
    for (int i = 1; i < 10; ++i) num[i] = num[i - 1] * i;
}

int check(int x) { // 按位阶乘求和
    int temp = x, sum = 0;
    while (x) {
        sum += num[x % 10];
        x /= 10;
    }
    return temp == sum; // 比较与本身是否相等
}

int main() {
    int ans = 0;
    init();
    for (int i = 3; i < MAX_N; ++i) {
        if (!check(i)) continue;
        ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
