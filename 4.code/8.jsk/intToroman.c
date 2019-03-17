/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月10日 星期四 15时03分57秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int inum[15] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char rnum[15][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 13;) {
        if (n >= inum[i]) {
            n -= inum[i];
            printf("%s", rnum[i]);
        } else {
            i++;
        }
    }
    printf("\n");
    return 0;
}
