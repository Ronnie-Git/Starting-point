/*************************************************************************
	> File Name: p1781.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月25日 星期二 11时26分19秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int n, ans = 1;
    char str[30][110];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (strlen(str[i]) > strlen(str[ans])) {
            ans = i;
        }
        if (strlen(str[i]) == strlen(str[ans]) && strcmp(str[i], str[ans]) > 0) {
            ans = i;
        }
    }
    printf("%d\n%s\n", ans, str[ans]);
    return 0;
}
