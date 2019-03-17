/*************************************************************************
	> File Name: 3.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月16日 星期六 14时48分45秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <inttypes.h>
using namespace std;

int vis[32] = {0};

// 输出下标和二进制末尾0的个数
void ouput1(int *num) {
    printf("下标 -> 二进制末尾0的个数\n");
    for (int i = 0; i < 32; i++) {
        printf("%d -> %d\n", i , num[i]);
    }
    return ;
}

// 以数组格式输出方便之后使用
void ouput2(int *num, uint32_t x) {
    printf("int arr[32] = {\n");
    for (int i = 0; i < 32; i++) {
        printf("%d", num[i]);
        if (i != 31) printf(", ");
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("};\n");
}

// 判断 x 是否是满足条件的常量
int check(uint32_t x) {
    int num[32] = {0};
    for (int i = 0; i < 32; i++) {
        num[(x << i) >> 27] += 1;
        if(num[(x << i) >> 27] == 2) return 0;
    }
    for(int i = 0; i < 32; i++) {
        num[(x << i) >> 27] = i;
    }
    //ouput1(num);
    //ouput2(num, x);
    return 1;
}

uint32_t find(uint32_t x, int k) {
    if (k == 0) {
        if (check(x)) {
            printf("0x%08X\n", x);
            return x;
        }
        return -1;
    }
    int ans = 0;
    int val = x & 0xf;
    if (vis[(val << 1) | 1] == 0) {
        vis[val << 1 | 1] = 1;
        ans = find(x << 1 | 1, k - 1);
        // 如果想输出多组请注释掉下行代码
        if (ans) return ans;
        vis[val << 1 | 1] = 0;
    }
    if (vis[val << 1] == 0) {
        vis[val << 1] = 1;
        ans = find(x << 1, k - 1);
        // 如果想输出多组请注释掉下行代码
        if (ans) return ans;
        vis[val << 1] = 0;
    }
    return 0;
}

int main() {
    uint32_t x;
    for (int i = 0; i < 31; i++) {
        vis[i] = 1;
        x = find(i, 27);
        vis[i] = 0;
    }
    return 0;
}
