/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月10日 星期四 15时16分42秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, ans = 0, num = 0, flag = 0, temp = 0, m;
    int arr[1005] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        temp += arr[i];
        if (temp <= 0) temp = 0;
        if (temp > ans) ans = temp;

        if (flag) continue;
        if (arr[i] > 0) flag = 1;
        if (i == 0 || arr[i] > m) m = arr[i];
    }
    printf("%d\n", flag ? ans : m);
    return 0;
}
