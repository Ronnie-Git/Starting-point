/*************************************************************************
	> File Name: 46.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 11时55分29秒
 ************************************************************************/

#include <stdio.h>


int is_prime(int x) { // 判断素数
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int main() {
    for (int i = 33; i; i += 2) {
        if (is_prime(i)) continue;
        int flag = 1;
        for (int j = 1; j * j * 2 <= i && flag; j++) { // 判断 （ i = 素数 + 2 * j * j ）是否正确
            if (is_prime(i - j * j * 2)) flag = 0;
        }
        if (flag) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
