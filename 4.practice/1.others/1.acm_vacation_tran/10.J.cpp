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

// 大数减法将每一位相减 如果该数组最高位为负数则将每一位变为它的相反数（用flag记录该大数的正负）
// 再将数组中的每个负数 + 10, 它的下一位 - 1
// flag 代表正负号 根据ans[ans[0]](即最高位)判断正负
// 无论正负 新传入的ans数组每一位都是非负数
void func(int *ans, char *str, int *flag) {
    int len = strlen(str);
    if (ans[0] < len) ans[0] = len;
    for (int i = 1; i <= len; i++) {
        ans[i] -= (str[len - i] - '0');
    }
    while (ans[0] && ans[ans[0]] == 0) ans[0]--;
    if (ans[ans[0]] < 0) (*flag) = -1 * (*flag);
    if (ans[ans[0]] < 0) {
        for (int i = 1; i <= ans[0]; i++) ans[i] = -1 * ans[i];
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] >= 0) continue;
        ans[i + 1]--;
        ans[i] = 10 + ans[i];
        if (ans[ans[0]] == 0) ans[0]--;
    }
    return ;
}

void output(int *ans) {
    for (int i = ans[0]; i > 0; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return ;
}
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        char a[1005] = {0}, b[1005] = {0};
        int ans[1050] = {0}, flag = 1;
        scanf("%s %s", a, b);
        if (a[0]) {
            switch (a[0]) {
                case '+' : add(ans, a + 1); break;
                case '-' : func(ans, a + 1, &flag); break;
                default : add(ans, a); break;
            }
        }

        if (b[0]) {
            if ((b[0] == '+' && flag == 1) || (b[0] == '-' && flag == -1)) add(ans, b + 1);
            else if ((b[0] == '-' && flag == 1) || (b[0] == '+' && flag == -1)) func(ans, b + 1, &flag);
            else if ((b[0] >= '0' && b[0] <= '9' && flag == 1)) add(ans, b);
            else if ((b[0] >= '0' && b[0] <= '9' && flag == -1)) func(ans, b, &flag);
        }
        if (flag == -1) printf("-");
        output(ans);
    }
    return 0;
}
