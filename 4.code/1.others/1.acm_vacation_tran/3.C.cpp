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

void func(int *ans, char *str) {
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

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        if (i > 1) printf("\n");
        char a[1005] = {0}, b[1005] = {0};
        int ans[1050] = {0};
        scanf("%s %s", a, b);
        func(ans, a);
        func(ans, b);
        printf("Case %d:\n", i);
        printf("%s + %s = ", a, b);
        for (int i = ans[0]; i > 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
