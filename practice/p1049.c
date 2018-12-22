/*************************************************************************
	> File Name: p1049.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 15时45分04秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int V, n, v[40] = {0};
    int num[20005] = {0};
    num[0] = 1;
    scanf("%d", &V);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = V; j >= v[i]; j--) {
            if (num[j - v[i]] == 1) num[j] = 1;
        }
    }

    for (int i = V; i >= 0; i--) {
        if (num[i]) {
            printf("%d\n", V - i);
            break;
        }
    }
    return 0;
}
