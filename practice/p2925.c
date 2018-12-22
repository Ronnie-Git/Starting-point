/*************************************************************************
	> File Name: p2925.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 14时23分58秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, m, num[5005] = {0}, ans[50000] = {0};
    ans[0] = 1;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= num[i]; j--) {
            if (ans[j - num[i]] == 1) ans[j] = 1;
        }
    }
    for (int i = m; i >= 0; i--) {
        if (ans[i]) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
