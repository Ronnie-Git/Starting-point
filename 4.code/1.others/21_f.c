/*************************************************************************
	> File Name: 21_f.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月17日 星期一 19时35分34秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX_N 100000

int prime[MAX_N + 5] = {0}; // 最小质因数
int min_num[MAX_N + 5] = {0}; // 最小质因数的幂次
int fnum[MAX_N + 5] = {0}; // 因数和

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            min_num[i] = 1;
            fnum[i] = i + 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                fnum[i * prime[j]] = fnum[i] / (pow(prime[j], min_num[i] + 1) - 1) * (pow(prime[j], min_num[i] + 2) - 1);
                min_num[i * prime[j]] = min_num[i] + 1;
                break;
            } else {
                fnum[i * prime[j]] = fnum[prime[j]] * fnum[i];
                min_num[i * prime[j]] = 1;
            }
        }
    }
    for (int i = 2; i <= MAX_N; i++) fnum[i] -= i;
    return ;
}

int main() {
    init();
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("fnum[%d] = %d, min_num[%d] = %d\n", n, fnum[n], n, min_num[n]);
    }
    return 0;
}
