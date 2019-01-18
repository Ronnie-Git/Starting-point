/*************************************************************************
	> File Name: 49.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 10时36分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX_N 200000

using namespace std;

int is_prime[MAX_N + 5] = {0}; // 标记素数
int prime[MAX_N + 5] = {0}; // 存素数
int k = 0; // 记录初始位置

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        if (!k && prime[prime[0]] > 1000) k = prime[0]; 
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int check(int i, int n) { // 判断是否成分一样
    int num1[5] = {0}, num2[5] = {0}, num3[5] = {0}, m = 0;
    int a = prime[i], b = prime[i] + n, c = prime[i] + n + n;
    while (m++ < 4) { // 按位储存到数组
        num1[m] = a % 10;
        num2[m] = b % 10;
        num3[m] = c % 10;
        a /= 10, b /= 10, c /= 10;
    }
    sort(num1, num1 + 5);
    sort(num2, num2 + 5);
    sort(num3, num3 + 5);
    while (--m >= 1) { // 判断是否成分一样
        if (num1[m] != num2[m] || num2[m] != num3[m] || num1[m] != num3[m]) return 0;
    }
    return 1;
}

int main() {
    init();
    for (int i = k; prime[i] < 10000; i++) {
        for (int n = 1; prime[i] + n + n < 10000; n++) {
            if (is_prime[prime[i] + n] || is_prime[prime[i] + n + n]) continue; // 判断是否是素数
            if (check(i, n)) printf("%d%d%d\n", prime[i], prime[i] + n, prime[i] + n + n);
        }
    }
    return 0;
}
