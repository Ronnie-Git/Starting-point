/*************************************************************************
	> File Name: 3.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月16日 星期六 18时13分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int cnt(int x) {
    x = ((x & 0xAAAAAAAA) >> 1) + (x & 0x55555555);
    x = ((x & 0xCCCCCCCC) >> 2) + (x & 0x33333333);
    x = ((x & 0xF0F0F0F0) >> 4) + (x & 0x0F0F0F0F);
    x = ((x & 0xFF00FF00) >> 8) + (x & 0x00FF00FF);
    x = ((x & 0xFFFF0000) >> 16) + (x & 0x0000FFFF);
    return x;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", cnt(n));
    }
    return 0;
}
