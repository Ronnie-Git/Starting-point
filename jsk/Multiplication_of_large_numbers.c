/*************************************************************************
	> File Name: test.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月11日 星期五 11时37分05秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void init(int *num, char *temp) {
    num[0] = strlen(temp);
    int len = num[0];
    for (int i = 1; i <= num[0]; i++) {
        num[i] = temp[len - i] - '0';
    }
    return ;
}

void func(int *ans, int *num, int *n) {
    for (int i = 1; i <= num[0]; i++) {
        for (int j = 1; j <= n[0]; j++) {
            ans[j + i - 1] += num[i] * n[j];
            ans[0] += (j + i - 1 > ans[0]);
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
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
    int ans[260000] = {0}, num[505] = {0}, n[505] = {0};
    scanf("%s", temp);
    init(num, temp);
    scanf("%s", temp);
    init(n, temp);
    func(ans, num, n);
    output(ans);
    return 0;
}
