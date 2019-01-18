/*************************************************************************
	> File Name: 44.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时53分43秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t pentagonal(int64_t n) { // 计算五角形数
    return n * (3 * n - 1) / 2;
}

int64_t is_pentagonal(int64_t x) { // 查找五角形数
    int64_t head = 1, tail = 500000000, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (pentagonal(mid) == x) return 1;
        if (pentagonal(mid) > x) tail = mid - 1;
        else head = mid + 1;
    }
    return 0;
}

int main() {
    int64_t i = 1, j = 1, ans = INT64_MAX;
    while (pentagonal(j + 1) - pentagonal(j) < ans) {
        j++;
        i = j - 1;
        do {
            if (is_pentagonal(pentagonal(i) + pentagonal(j))) { // 判断五角形数和是否是五角形数
                if(is_pentagonal(pentagonal(j) - pentagonal(i))) { // 判断五角形数差是否是五角形数
                    if (pentagonal(j) - pentagonal(i) < ans) {
                        ans = pentagonal(j) - pentagonal(i);
                    }   
                } 
            }
            i--;
        } while (i >= 1 && pentagonal(j) - pentagonal(i) < ans);
    }
    printf("%"PRId64"\n", ans);
    return 0;
}
