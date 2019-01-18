/*************************************************************************
	> File Name: 40.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 09时44分32秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int get_num(int d) {
    if (d < 10) return d;
    int digit = 1, base = 10; // digit 位数 base 限定范围最大边界值(eg: base = 100; base - base / 10 = 90)
    while (d > digit * (base - base / 10)) { // 求出第 i 位数在哪个范围中
        d -= digit * (base - base / 10);
        digit += 1;
        base *= 10;
    }
    d--;
    int num = base / 10 + d / digit; // 求出这个数
    d = floor(log10(num)) + 1 - d % digit; // 求出第 i 位数在这个数中的倒数第几位
    int ret = 0;
    while (d--) {
        ret = num % 10;
        num /= 10;
    }
    return ret;
}

int main() {
    int ans = 1;
    for (int i = 1; i <= 1000000; i *= 10) {
        printf("%d ", get_num(i));
        ans *= get_num(i);
    }
    printf("\n%d\n", ans);
    return 0;
}
