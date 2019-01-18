/*************************************************************************
	> File Name: newton.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 16时29分03秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

double newton(double n) { // 牛顿迭代
    double x = 1.0;
    #define EPS 1e-7
    while (fabs(x * x - n) > EPS) {
        x -= (x * x - n) / (2 * x); // 更新x使函数值无限接近0
    }
    #undef EPS
    return x;
}
