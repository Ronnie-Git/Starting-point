/*************************************************************************
	> File Name: P1024.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Dec 2019 07:03:14 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

double a, b, c, d;
double func(double x) { return a*x*x*x + b*x*x + c*x + d; }

int main() {
    cin >> a >> b >> c >> d;
    int flag = 0;
    for (double i = -100; i <= 100; i++) {
        double l = i, r = i + 1, mid;
        double x = func(i);
        while (r - l > 0.001) {
            mid = (l + r) / 2;
            if (func(mid) * x > 0) l = mid;
            else r = mid;
        }
        if (func(r) * x > 0) continue;
        if (flag) printf(" ");
        flag = 1;
        printf("%.2f", r);
        i = r;
    }
    printf("\n");
    return 0;
}
