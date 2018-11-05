/*************************************************************************
	> File Name: search_two.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月05日 星期一 21时07分18秒
 ************************************************************************/

#include <stdio.h>

int search(int *data, int length, int value) {
    int l = 0, r = length - 1, n = 0;
    while (l <= r) {
        n++;
        int mid = (l + r) >> 1;
        if (data[mid] == value) {
            printf("%d success\n", n);
            return mid;
        }
        if (data[mid] < value) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d failed\n", n);
    return -1;
}

int main() {
    int n, m, x;
    int num[200] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        search(num, n, x);
    }
    return 0;
}
