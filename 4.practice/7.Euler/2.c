/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月20日 星期五 23时00分21秒
 ************************************************************************/
/*
#include<stdio.h>

int main() {
    int a = 1, b = 2, sum = 0;
    while (b <= 4000000) {
        if (b % 2 == 0) sum += b;
        b = a + b, a = b - a;
    }
    printf("%d\n", sum);
    return 0;
}
*/
#include <stdio.h>

int main() {
    int f[3] = {1, 0, 0}, sum = 0, n = 1;
    while (f[(n + 2) % 3] + f[(n + 1) % 3] <= 4000000) {
        f[n % 3] = f[(n + 1) % 3] + f[(n + 2) % 3];
        if ((f[n % 3] & 1) == 0)  sum += f[n % 3];
        n += 1;
    }
    printf("%d\n", sum);
    return 0;
}

