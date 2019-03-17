/*************************************************************************
	> File Name: p1603.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月30日 星期五 17时28分23秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

char num[30][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"};
int mod_num[30] = {0,1,4,9,16,25,36,49,64,81,0,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};

int main() {
    char t[100] = {0};
    int ans[1000] = {0}, l = 0, flag = 0;
    while (scanf("%s", t) != EOF) {
        if (t[0] == '.') break;
        for (int i = 0; i < 27; i++) {
            if (strcmp(t, num[i]) == 0) {
                ans[l++] = mod_num[i];
                break;
            }
        }
    }
    sort(ans, ans + l);
    for (int i = 0; i < l; i++) {
        if (!flag && !ans[i]) continue;
        if (flag && ans[i] < 10) printf("0");
        printf("%d", ans[i]);
        flag = 1;
    }
    if (!flag) printf("0");
    printf("\n");
    return 0;
}
