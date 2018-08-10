/*************************************************************************
	> File Name: 8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 19时12分39秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>
#include <string.h>
//#include "EP08.h"

int main() {
    int64_t p = 1, zero = 0, ans = 0;
    char t[1005];
    char num[1005];
    scanf("%s", t);
    strcpy(num, t);
    for (int i = 0; num[i]; i++) {
        if (num[i] == '0') {
            zero += 1;
        } else {
            p *= (num[i] - '0');
        }
        if (i >= 13) {
            if (num[i - 13] == '0') {
                zero -= 1;
            } else {
                p /= (num[i - 13] - '0');
            }
        }
        if (zero == 0 && p > ans) ans = p;
    }
    printf("%" PRId64 "\n", ans);//windows %i64d   linux %lld
    return 0;
}
