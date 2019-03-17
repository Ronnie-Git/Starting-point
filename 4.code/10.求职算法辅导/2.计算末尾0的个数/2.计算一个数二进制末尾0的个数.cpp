/*************************************************************************
	> File Name: 2.计算一个数二进制末尾0的个数.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月16日 星期六 16时16分23秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <inttypes.h>

using namespace std;

const uint32_t NUM = 0x077CB531U;

int arr[32] = {
    0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8, 
    31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
};

int main() {
    uint32_t v, ans;
    while (scanf("%d", &v) != EOF) {
        if (v == 0) continue;
        printf("%d\n", arr[((uint32_t)((v & -v) * NUM)) >> 27]); 
    }
}
