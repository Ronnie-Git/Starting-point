/*************************************************************************
	> File Name: is_prime.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 11时38分11秒
 ************************************************************************/

#include <stdio.h>

int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

