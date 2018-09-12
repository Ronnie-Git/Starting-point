/*************************************************************************
	> File Name: p.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月12日 星期三 14时43分18秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100000

int arr[MAX_N + 5] = {0};

void swap(int i, int j) { // 交换数组值
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quick_sort(int l, int r) {
	if (l >= r) return;  
	swap(l, rand() % (r - l + 1) + l); // 随机生成中轴数
	int k = arr[l], i = l + 1, j = r; // 中轴数放到最左边
	while (1) {
		while (i <= r && arr[i] < k) i++; // 查找不小于k的
		while (j >= l + 1 && arr[j] > k) j--; // 查找不大于k的
		if (i > j) break;
		swap(i++, j--); // 交换数组值 使之数组左侧都是小于k的 右侧大于k
	}
	swap(j, l); // 将中轴数放到分隔处
	quick_sort(l, j - 1);
	quick_sort(j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
	srand(time(NULL));
	quick_sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
} 
