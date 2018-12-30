/*************************************************************************
	> File Name: l.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月18日 星期二 20时02分47秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, x = 0;
    scanf("%d", &n);
    int k = n;
    x = n == 0;
    while (n) {
        n /= 10;
        x++;
    }
    printf("%d\n", x);
    int sum = 0;
    do {
        n /= 10;
        sum++;
    } while (n);
    printf("%d\n", sum);
    return 0;
}
