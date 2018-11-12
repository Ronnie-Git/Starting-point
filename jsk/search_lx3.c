/*************************************************************************
	> File Name: search_lx3.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月12日 星期一 17时24分53秒
 ************************************************************************/

#include <stdio.h>

#define swap(a, b) { \
    __typeof(a) _temp = a; a = b; b = _temp; \
}

void quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, k = num[(r - l) / 2 + l];
        do {
            while (num[x] < k) ++x;
            while (num[y] > k) --y;
            if (x > y) continue;
            swap(num[x], num[y]);
            ++x, --y;
        } while (x <= y);
        quick_sort(num, x, r);
        r = y;
    }
}

int search(int *num, int n, int k) {
    int l = -1, r = n - 1, mid;
    while (l < r) {
        mid = (r - l + 1) / 2 + l;
        if (num[mid] <= k) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    int n, m, k;
    int num[100005] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    quick_sort(num, 0, n - 1);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        if (i) printf(" ");
        int ans = search(num, n, k);
        if (ans == -1) printf("%d", num[0]);
        else printf("%d", num[ans]);
    }
    printf("\n");
    return 0;
}
