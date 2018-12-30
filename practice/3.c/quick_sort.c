/*************************************************************************
	> File Name: quick_sort.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月12日 星期三 18时27分01秒
 ************************************************************************/

#include <stdio.h>

#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b; b = temp;\
}
#define MAX_N 100000

void quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while(num[x] < z) ++x;
            while(num[y] > z) --y;
            if (x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        }while (x <= y);
        quick_sort(num, x, r);
        r = y;
    }
    return ;
}

int main() {
    int num[MAX_N + 5] = {0}, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", num + i);
    quick_sort(num, 0, n - 1);
    printf("%d", num[0]);
    for (int i = 1; i < n; i++)
	printf(" %d", num[i]);
    printf("\n");
    return 0;
}
