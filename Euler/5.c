/*************************************************************************
	> File Name: 5.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 23时26分00秒
 ************************************************************************/
#include<stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int ans = 1;
    for (int i = 1; i < 21; i++) {
        if (ans % i == 0) continue;
        ans = i * ans / gcd(ans, i);
    }
    printf("%d\n", ans);
    return 0;
}
