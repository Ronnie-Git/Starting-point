/*************************************************************************
	> File Name: lx3.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月21日 星期二 10时20分54秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int c, d;
        while (b != 0) { // 位运算加法进位
            c = a ^ b;
            d = (a & b) << 1;
            a = c;
            b = d;
        }
        printf("%d\n", a);
    } 
    return 0;
}
