/*************************************************************************
	> File Name: 30.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 18时58分13秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>

int is_equal(int x) { // 对比幂数和是否和本身相等
    int temp = x, sum = 0;
    while (x) {
        sum += (int)pow(x % 10, 5);
        x /= 10;
    }
    return sum == temp;
}

int main() {
    int sum = 0;
    for (int i = 11; i < 354294; ++i) {
        if (!is_equal(i)) continue;
        sum += i; // 求和
    }
    printf("%d\n", sum);
    return 0;
}
