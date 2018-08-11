/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 17时14分36秒
 ************************************************************************/

#include<stdio.h>

int is_palindromic(int x) {
    int temp = x, num = 0;
    while (x) {
        num = num * 10 + x % 10;
        x /= 10;
        return temp == num;
    }
}

int main() {
    int ans;
    for (int i = 101; i <= 999; ++i) {
        for (int j = i; j <= 999; ++j) {
            if (i * j < ans) continue;
            if (!is_palindromic(i * j)) continue;
            ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
