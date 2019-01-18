/*************************************************************************
	> File Name: 39_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月03日 星期五 13时22分31秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 1000

int num[MAX_N + 5] = {0};

int gcd(int a, int b) { // 求最大公约数
    return b ? gcd(b, a % b) : a;
}

void AddMany(int a, int b, int c) { // 计算周长固定时三角形数个数
    int p = a + b + c;
    for (int i = p; i <= MAX_N; i += p) num[i]++;
}

int main() {
    int a, b, c, p;
    for (int i = 2; i * i <= MAX_N; i++) {
        for (int j = 1; j < i; j++) { // 求互质三角形数
            if (gcd(i, j) != 1) continue;
            a = i * i - j * j;
            b = 2 * i * j;
            c = i * i + j * j;
            if (a + b + c > MAX_N) continue;
            AddMany(a, b, c);
        }
    }
    int max_num = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (num[max_num] < num[i]) max_num = i;
    }
    printf("%d\n", max_num);
    return 0;
}
