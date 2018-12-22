/*************************************************************************
	> File Name: p2925.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 14时23分58秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, m, num[5005] = {0}, ans[50000] = {0};
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= num[i]; j--) {
            ans[j] = max(ans[j], ans[j - num[i]] + num[i]);
        }
    }
    printf("%d\n", ans[m]);
    return 0;
}
