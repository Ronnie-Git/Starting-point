/*************************************************************************
	> File Name: 6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 18时02分05秒
 ************************************************************************/

#include<stdio.h>
/*
int main() {
    int sum1 = 0, sum2 = 0, n = 100;
    do {
        sum1 += n;
        sum2 += n * n;
    } while (--n);
    printf("%d\n", sum1 * sum1 - sum2);
    return 0;
}*/

int main() {
    int sum1 = 5050, sum2 = 100 * (100 + 1) * (200 + 1) / 6; // 1 ^ 2 + ... + n ^ 2 = n * (n + 1) * (2 * n + 1) / 6;
    printf("%d\n", sum1 * sum1 - sum2);
}
