/*************************************************************************
	> File Name: 44_lx.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 09时45分16秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t check(int64_t x) {
    int64_t left = -100000, right = 100000, mid;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (mid * mid * mid == x) return 1;
        if (mid * mid * mid > x) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int main() {
    int64_t n;
    scanf("%"PRId64"", &n);
    printf("%s\n", check(n) ? "YES" : "NO");
    return 0;
}
