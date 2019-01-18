/*************************************************************************
	> File Name: p2708.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月27日 星期四 17时04分21秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char num[10000];
    scanf("%s", num);
    int len = strlen(num) + 1, sum = 0;
    if (num[0] == '0') sum++;
    while (--len) {
        if (num[len] == '0' && num[len - 1] == '1') sum += 2;
    }
    printf("%d\n", sum);
    return 0;
}
