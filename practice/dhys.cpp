/*************************************************************************
	> File Name: lx3.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月21日 星期二 10时59分00秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

void init() {
    printf("hello\n");
    return ;
}

int main() {
    int a;
    scanf("%d", &a);
    a && (init(), 1); // ,运算
    return 0;
}
