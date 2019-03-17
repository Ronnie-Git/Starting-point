/*************************************************************************
	> File Name: p1149.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月06日 星期六 09时43分13秒
 ************************************************************************/

#include <stdio.h>

int num[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int arr[1000] = {0};

void init() {
    arr[0] = 6;
    for (int i = 0; i < 1000; i++) {
        int x = i;
        while (x) {
            arr[i] += num[x % 10];
            x /= 10;
        }
    }
    return ;
}

int main() {
    init();
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000 && i + j < 1000; j++) {
            int sum = arr[i] + arr[j] + arr[i + j] + 4;
            if (sum == n) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
