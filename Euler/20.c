/*************************************************************************
	> File Name: 20.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 00时33分19秒
 ************************************************************************/

#include <stdio.h>

int num[300] = {1, 1};

int main() {
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= num[0]; j++) num[j] *= i; // 大数阶乘
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (j == num[0]);
        }
    }
    for (int i = num[0]; i > 0; i--) sum += num[i]; // 各位求和
    printf("%d\n", sum);
    return 0;
}
