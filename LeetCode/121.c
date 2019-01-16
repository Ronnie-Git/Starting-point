/*************************************************************************
	> File Name: 121.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月16日 星期三 15时09分47秒
 ************************************************************************/

// 模拟单调队列

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {   
    int ans = 0, min = prices[0], max = prices[0];
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min) min = prices[i], max = prices[i];
        if (prices[i] > max) max = prices[i];
        if (max - min > ans) ans = max - min;
    }
    return ans;
}

int main() {
    int n, num[100] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    printf("%d\n", maxProfit(num, n));
    return 0;
}
