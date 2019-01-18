/*************************************************************************
	> File Name: sort_stable.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月03日 星期六 23时05分12秒
 ************************************************************************/

#include <stdio.h>

#define swap(a, b) { \
    __typeof(a) temp = a; \
    a = b; b = temp; \
}

void merge_sort(int *data, int l, int r) {
	if (l == r) return ;
    int mid = (l + r) / 2;
    merge_sort(data, l, mid);
    merge_sort(data, mid + 1, r);
    int temp[r - l + 1], x = l, y = mid + 1, cnt = 0;
    while (x <= mid || y <= r) {
    	if (x <= mid && (y > r || data[x] <= data[y])) temp[cnt++] = data[x++];
        else temp[cnt++] = data[y++];
    }
    for (int i = l; i <= r; i++) {
        data[i] = temp[i - l];
    }
    return ;
}

void bubble_sort(int *data, int length) {
	for (int i = 0; i < length - 1; i++) {
        int flag = 0;
        for (int j = 0; j < length - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                printf("%d %d\n", j, j + 1);
                flag = 1;
            }
        }
        if (!flag) break;
    }
    return ;
}

void insert_sort(int *data, int length) {
	for (int i = 0; i < length; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (data[j] <= data[j + 1]) break;
            swap(data[j], data[j + 1]);
            printf("%d %d\n", j, j + 1);
        }
    }
    return ;
}

void print(int *data, int length) {
    for (int i = 0; i < length; ++i) {
        i && printf(" ");
        printf("%d", data[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int m, n;
    scanf("%d", &n);
    int a[n], x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a[i] = x;
    }
    scanf("%d", &m);
    switch(m) {
        case 1: insert_sort(a, n); break;
        case 2: bubble_sort(a, n); break;
        case 3: merge_sort(a, 0, n - 1); break;
    }
    print(a, n);
    return 0;
}
