/*************************************************************************
	> File Name: sqrt.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月13日 星期四 20时04分06秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>

#define TEST_TIME(funs) ({ \
    int begin = clock(); \
    double ret = funs; \
    int end = clock(); \
    printf("%lfms\n", (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000);\
    ret; \
})


double _sqrt1(double x) { // 二分求平方根
    double head = -100, tail = 100, mid;
    #define EPS 1e-7
    while (tail - head > EPS) {
        mid = (head + tail) / 2.0;
        if (mid * mid < x) head = mid;
        else tail = mid;
    }
    #undef EPS
    return head;
}

double f1(double x, double n) {
    return x * x - n; // 函数y = x * x - n
}

double f1_prime(double x) {
    return 2 * x; // 导数
}

double newton(double n, double (*f)(double, double), double (*f_prime)(double)) { // 牛顿迭代
    double x = 1.0;
    //int cut = 0;
    //x -= f(x, n) / f_prime(x); // 雷神之锤三思路
    //x -= f(x, n) / f_prime(x);
    //x -= f(x, n) / f_prime(x);
    //x -= f(x, n) / f_prime(x);
    #define EPS 1e-7
    while (fabs(f(x, n)) > EPS) {
        x -= f(x, n) / f_prime(x); // 更新x使函数值无限接近0
    }
    #undef EPF
    return x;
}


int main() {
    double n;
    while (scanf("%lf", &n) != EOF){
        printf("%lf\n", TEST_TIME(_sqrt1(n)));
        printf("%lf\n", TEST_TIME(newton(n, f1, f1_prime)));
    }

    return 0;
}
