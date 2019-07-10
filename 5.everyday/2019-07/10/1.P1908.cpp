/*************************************************************************
	> File Name: 1.P1908.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月10日 星期三 19时12分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int LEN = 500010;

int arr[LEN] = {0}, temp[LEN] = {0};
LL ans = 0;

// 快速读入
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return x * f;
}

// 归并排序
void merge_sort(int l, int r) {
    if (r - l < 2) return ;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid, r);
    int i = l, j = mid, k = 0;
    while (i < mid || j < r) {
        if (j >= r || (i < mid && arr[i] <= arr[j])) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // 此时左侧没有放入 temp 数组中的元素都大于 arr[j]
            // 所以逆序对的总数加上这些元素的个数
            ans = ans + (mid - i);
        }
    }
    for (i = l; i < r; ++i) arr[i] = temp[i - l];
    return ;
}

int main() {
    int n = read();
    for (int i = 0; i < n; ++i) arr[i] = read();
    merge_sort(0, n);
    printf("%lld\n", ans);
    return 0;
}
