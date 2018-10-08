/*************************************************************************
	> File Name: sqrt.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 16时33分14秒
 ************************************************************************/

#include <stdio.h>

double sqrt1(double x) { // 二分求平方根
    double head = -1000, tail = 1000, mid;
    #define EPS 1e-7
    while (tail - head > EPS) {
        mid = (head + tail) / 2.0;
        if (mid * mid < x) head = mid;
        else tail = mid;
    }
    #undef EPS
    return head;
}
