/*************************************************************************
	> File Name: 35.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 12时13分04秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX_N 1000000

int is_prime[MAX_N + 5] = {0};//标记素数
int prime[MAX_N + 5] = {0};//储存素数

void init() {//线性筛
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    int flag = 0, k = 0;//k 计数器 flag 标记是否是循环素数
    for (int i = 1; i <= prime[0]; i++) {
        int n = floor(log10(prime[i])), x = prime[i];// n 位数-1
        do {
            if (prime[i] < 10) break;//小于10的都是
            x = x / (int)pow(10, n) + x % (int)pow(10, n) * 10;
            if (is_prime[x]) {// 判断是否是循环素数
                flag = 1;
                break;
            }
        } while (x != prime[i]);
        if (!flag) k++;
        flag = 0;
    }
    printf("%d\n", k);
    return 0;
}
