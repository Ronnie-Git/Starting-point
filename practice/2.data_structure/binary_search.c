/*************************************************************************
	> File Name: binary_search.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月06日 星期二 19时27分10秒
 ************************************************************************/

#include <stdio.h>

#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

// 1 2 3 4 5
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

// 111111000000
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

// 0000001111111
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    int num[20] = {0}, n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &m);
    switch(m) {
        case 1: {
            int x;
            scanf("%d", &x);
            P(binary_search1(num, n, x));
        } break;
        case 2: P(binary_search2(num, n)); break;
        case 3: P(binary_search3(num, n)); break;
    }
    return 0;
}
