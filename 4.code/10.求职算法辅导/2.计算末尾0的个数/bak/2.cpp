/*************************************************************************
	> File Name: 2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月16日 星期六 18时12分37秒
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
unsigned int v;  // find the number of trailing zeros in 32-bit v
int r;           // result goes here
int arr[32] = {
    31,0,1,5,2,10,6,15,3,13,11,20,7,22,16,25,
    30,4,9,14,12,19,21,24,29,8,18,23,28,17,27,26
};
int main() {
    int v, r;
    while (~scanf("%d", &v)) {
        r = arr[((uint32_t)((v & -v) * 0x08CA75BE)) >> 27];
        printf("%d\n", r);
    }
    return 0;
}

