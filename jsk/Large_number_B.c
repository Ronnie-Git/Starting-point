/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月10日 星期四 16时04分21秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void func(char *temp, int *ans) {
    int len = strlen(temp);
    if (len > ans[0]) ans[0] = len;
    for (int i = 1; i <= len; i++) {
        ans[i] += temp[len - i] - '0';
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] = ans[i] % 10;
        ans[0] += (i == ans[0]);
    }
    return ;
}

void output(int *ans) {
    int flag = 0;
    for (int i = ans[0]; i > 0; i--) {
        if (!flag && ans[i] == 0) continue;
        flag = 1;
        printf("%d", ans[i]);
    }
    if (!flag) printf("0");
    return ;
}

int main() {
    char temp[505] = {0};
    int ans[505] = {0};
    for (int i = 0; i < 2; i++) {
        scanf("%s", temp);
        func(temp, ans);
    }
    output(ans);
    return 0;
}
