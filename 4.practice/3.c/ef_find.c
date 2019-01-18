/*************************************************************************
	> File Name: ef_find.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月08日 星期一 18时51分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double func(double x) {
    double l = -1000, r = 1000, mid;
    while (r - l > 1e-7) {
        mid = (r + l) / 2;
        if (mid * mid < x) l = mid;
        else r = mid;
    }
    return mid;
}

int main() {
    srand(time(0));
    for (int i = 0; i < 30; i++) {
        double x = 1.0 * (rand() % 100000) / 100000 * 10000;
        printf("%lf\n", func(x));
    }
    return 0;
}
