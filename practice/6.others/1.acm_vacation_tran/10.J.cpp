/*************************************************************************
	> File Name: 3.C.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月14日 星期一 09时07分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void add(int *ans, char *str) {
    int len = strlen(str);
    if (ans[0] < len) ans[0] = len;
    for (int i = 1; i <= len; i++) {
        ans[i] += (str[len - i] - '0');
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] = ans[i] % 10;
        ans[0] += (ans[0] == i);
    }
    return ;
}

void func(int *ans, char *str) {
    int len = strlen(str);
    if (ans[0] < len) ans[0] = len;
    for (int i = 1; i <= len; i++) {
        ans[i] -= (str[len - i] - '0');
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] <= 0) continue;
        if (i + 1 <= ans[0]) ans[i + 1]--;
        ans[i] = 10 - ans[i];
        if (ans[ans[0]] == 0) ans[0]--;
    }
    return ;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        if (i > 1) printf("\n");
        char a[1005] = {0}, b[1005] = {0};
        int ans[1050] = {0}, flag = 0;
        scanf("%s %s", a, b);
        if (a[0]) {
            switch (a[0]) {
                case '+' : add(ans, a + 1);
                case '-' : func(ans, a + 1);
                default : add(ans, a);
            }
        }
        if (b[0]) {
            switch (b[0]) {
                case '+' : add(ans, b + 1);
                case '-' : func(ans, b + 1);
                default : add(ans, b);
            }
        }
        for (int i = ans[0]; i > 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
