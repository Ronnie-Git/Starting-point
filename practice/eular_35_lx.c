/*************************************************************************
	> File Name: eular_35_lx.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月26日 星期一 17时49分45秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

const int  MAX_N =  10000000;
const int n =  9999999 + 1;

int b[n] = {0}, a[n] = {0};
int initPrime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!a[i]) b[++b[0]] = i;
        for (int j = 1; j <= b[0] && b[j] * i <= MAX_N; j++) {
            a[i * b[j]] = 1;
            if (i % b[j] == 0) break;
        }
    }
}
int check(int n) {
    if (a[n]) return 0;
    int x = n, h, j;
    h = (int)pow(10, floor(log10(n)));
    j = (int)floor(log10(n)) + 1;
    for (int i = 0; i < j; i++) {
        x = x / 10 + x % 10 * h;
        if (a[x]) return 0;
    }
    return 1;
}

int solve() {
    int many = 0;
    for (int i = 1; i <= b[0]; i++) {
        if (b[i] > n) break;
        if (check(b[i])) ++many;
    }
    return many;
}

int main() {
    initPrime();
    printf("%d\n", solve());
}
