/*************************************************************************
	> File Name: newton.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月08日 星期一 18时42分27秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double newton(double n) {
    double x = 1.0;
    while (fabs(x * x - n) > 1e-7) {
        x -= (x * x - n) / (2 * x);
    }
    return x;
}


int main() {
    srand(time(0));
    for (int i = 0; i < 30; i++) {
        double n = 1.0 * (rand() % 100000) / 100000 * 1000;
        printf("%lf\n", newton(n));
    } 
    return 0;
}
