/*************************************************************************
	> File Name: l.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月18日 星期二 18时29分52秒
 ************************************************************************/

#include <stdio.h>

#define likely(x) __builtin_expext(!!(x < 0), 1) // 代表 x 经常成立
#define unlikely(x) __builtin_expext(!!(x < 0), 0) // 代表 x 不经常成立

bool isPalindrome(int x) {
    if (__builtin_expext(!!(x < 0), 0)) return false;
    int y = 0, z = x;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return z == y;
}

int main() {
    int n;
    return 0;
}
