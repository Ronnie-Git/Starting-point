/*************************************************************************
	> File Name: 45.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 09时34分05秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t Triangle(int64_t n) { // 三角形数
    return n * (n + 1) / 2;
}

int64_t Pentagonal(int64_t n) { // 五边形数
    return n * (3 * n - 1) / 2;
}

int64_t Hexagonal(int64_t n) { // 六边形数 六边形数一定是三角形数
    return n * (2 * n - 1);
}

int64_t binary_search(int64_t (*num)(int64_t), int64_t n, int64_t x) { // 传函数 进行二分
    int64_t head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num(mid) == x) return mid;
        if (num(mid) > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

int main() {
    int64_t n = 144;
    while (binary_search(Pentagonal, 2 * n, Hexagonal(n)) == -1) ++n;
    printf("%"  PRId64 "\n", Hexagonal(n));
    return 0;
}
