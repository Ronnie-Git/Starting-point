/*************************************************************************
	> File Name: 1981.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月21日 星期日 16时49分59秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_N 1300000
#define N 10000

char str[MAX_N] = {0};

int calc(char *str) {
    int len = strlen(str);
    for (int i = 0; str[i]; i++) {
        str[i] = (str[i] == '+' ? 0 : str[i]);
    }
    int total = 0;
    for (int j = 0; j < len; j += strlen(str + j) + 1) {
        int num = 0, p = 1;
        for (int i = j; str[i]; i++) {
            switch (str[i]) {
                case '*': p = p * num % N; num = 0; break;
                default : num = num * 10 + str[i] - '0';
            }
        }
        p = p * num % N;
        total = (total + p) % N;
    }
    return total;
}

int main() {
    scanf("%s", str);
    printf("%d\n", calc(str));
    return 0;
}
