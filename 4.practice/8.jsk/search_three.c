/*************************************************************************
	> File Name: search_three.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月05日 星期一 18时52分45秒
 ************************************************************************/

#include <stdio.h>

int find_max(int *data, int length) {
    int l = 0, r = length - 1, k = 0;
    while (r - l >= 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l + 2) / 3;
        if (data[m1] <= data[m2]) r = m2;
        else l = m1 + 1;
        k++;
    }
    if (data[l] < data[r]) printf("%d %d\n", k, l);
    else printf("%d %d\n", k, r);
    return 1;
}

int main() {
    int n;
    int num[200] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    find_max(num, n);
    return 0;
}
