/*************************************************************************
	> File Name: p1031.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 19时45分26秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int num[105] = {0}, n, x = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        x += num[i];
    }
    x /= n;
    for (int i = 0; i < n - 1; i++) {
        if (num[i] < x) {
            ans++;
            num[i + 1] -= (x - num[i]);
        }
        if (num[i] > x) {
            ans++;
            num[i + 1] += (num[i] - x);
        }
    }
    printf("%d\n", ans);
    return 0;
}
