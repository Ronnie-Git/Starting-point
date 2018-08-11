/*************************************************************************
	> File Name: xxs.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 18时18分49秒
 ************************************************************************/

#include<stdio.h>
#define MAN_N 1000000

int prime[MAN_N + 5] = {0};//1.标记 2.储存素数 3.prime[0]计数

int main() {
    for (int i = 2; i <= MAN_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;//储存素数
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAN_N; j++) {
            prime[i * prime[j]] = 1;//标记合数
            if (i % prime[j] == 0) break;//遍历到i的最小素数为止
        }
    }
    for (int i = 1; i <= prime[0]; i++) 
        printf("%d ", prime[i]);
    printf("\n");
    return 0;
}
