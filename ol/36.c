/*************************************************************************
	> File Name: 36.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 22时51分34秒
 ************************************************************************/

#include<stdio.h>

int is_palindromic(int x, int n) { // 判断是否是某进制回文数
    int temp = x, num = 0;
    while (x) {
        num = num * n + x % n;
        x /= n;
    }
    return temp == num;
}

int main() {
    int ans = 0;
    for (int i = 0; i <= 1000000; ++i) {
        if (!is_palindromic(i, 2)) continue; // 判断是否是二进制回文数
        if (!is_palindromic(i, 10)) continue; // 判断是否是十进制回文数
        ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
