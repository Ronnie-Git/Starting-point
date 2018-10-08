/*************************************************************************
	> File Name: quick_pow.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 22时08分38秒
 ************************************************************************/

#include <stdio.h>

int quick_pow(int a, int b){
    int ans = 1, base = a;
    while (b != 0){
        if (b & 1) ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}
