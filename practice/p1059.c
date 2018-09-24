/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月24日 星期一 13时27分56秒
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) { \
    __typeof(a) temp = a; \
    a = b; b = temp; \
}

void quick_sort(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, k = arr[(l + r) >> 1];
        do {
            while (arr[x] < k) ++x;
            while (arr[y] > k) --y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        }while (x <= y);
        quick_sort(arr, x, r);
        r = y;
    }
    return ;
}

int main() {
    int n, m = 1, arr[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            arr[i - 1] = -1;
        } else {
            m++;
        }
    }
    printf("%d\n", m);
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) printf("%d ", arr[i]);
    }
    return 0;
}
