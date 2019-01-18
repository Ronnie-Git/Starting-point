/*************************************************************************
	> File Name: 12.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 10时49分47秒
 ************************************************************************/
// 重点
#include <stdio.h>

#define MAX_N 100000

int dnum[MAX_N + 5] = {0}; // 因子数量
int mnum[MAX_N + 5] = {0}; //存最小素因子幂数
int prime[MAX_N + 5] = {0}; //线性筛

void init() {
    for (int i = 2; i * 2 <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2; // 素数只有两个约数
            mnum[i] = 1; // 最小因子幂数
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1; // 因数prime[j]又多了一个 
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2); // x = 最可能大的数
                // 计算一个合数的因子个数（一个合数由一个最可能大的数和一个最小质数标记掉） dnum[x * prime[j]] = dnum[x] / (mnum[x] + 1) * (mnum[x] + 2)
                break;
            } else {
                mnum[i * prime[j]] = 1; // 最小幂次为1
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]]; // i 和 prime[j] 互质
            }
        }
    }
}

int factor_nums(int n) { // f(n) = n * (n - 1) / 2
    if (n & 1) {
        return dnum[n] * dnum[(n + 1) / 2]; // n + 1为偶数 F[f(n)] = F(n) * F((n + 1) / 2)  
    }
    return dnum[n / 2] * dnum[n + 1]; // n为偶数 F(n / 2) * F(n + 1)
}

int main() {
    init();
    int n = 1;
    while (factor_nums(n) < 500) ++n;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
