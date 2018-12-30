/*************************************************************************
	> File Name: p1042.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 18时31分51秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1[6260][2] = {0}, num2[6260][2] = {0};
    char c;
    int i = 0, j = 0;
    while (scanf("%c", &c)) {
        if (c == 'E') break;
        if (c == '\n') continue;
        if (c == 'W') {
            num1[i][0]++;
            num2[j][0]++;
        }
        if (c == 'L') {
            num1[i][1]++;
            num2[j][1]++;
        }
        if ((num1[i][0] >= 11 || num1[i][1] >= 11) && abs(num1[i][0] - num1[i][1]) >= 2) {
            i++;
        }
        if ((num2[j][0] >= 21 || num2[j][1] >= 21) && abs(num2[j][0] - num2[j][1]) >= 2)  {
            j++;
        }
    }
    for (int l = 0; l <= i; l++) {
        printf("%d:%d\n", num1[l][0], num1[l][1]);
    }
    printf("\n");
    for (int l = 0; l <= j; l++) {
        printf("%d:%d\n", num2[l][0], num2[l][1]);
    }
    return 0;
}
