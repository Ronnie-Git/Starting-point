/*************************************************************************
	> File Name: p1192.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月24日 星期一 13时41分09秒
 ************************************************************************/

#include <stdio.h>

int a[100005] = {0};

int init(int n, int k) {
    a[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            a[i + j] = (a[i + j] + a[i]) % 100003;
        }
    }
    return a[n];
}

int main() {
    int n, k, ans;
    scanf("%d %d", &n, &k);
    ans = init(n, k);
    printf("%d\n", ans);
    return 0;
}
