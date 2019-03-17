/*************************************************************************
	> File Name: 14.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 23时25分17秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

#define MAX_N 1000000
#define KEEP_RANGE 2000000 

int keep_ans[KEEP_RANGE + 5] = {0}; // 记忆化数组 每个数字到 1 的长度 

int get_length(int64_t x) {
    if (x == 1) return 1;
    if (x <= KEEP_RANGE && keep_ans[x]) return keep_ans[x]; // 如果记录过直接返回长度
    int temp_ans;
    if (x & 1) temp_ans = get_length(x * 3 + 1) + 1; // x 为奇数
    else temp_ans = get_length(x >> 1) + 1; // x 为偶数
    if (x <= KEEP_RANGE) keep_ans[x] = temp_ans; // 在数组空间范围内 记录长度
    return temp_ans;
}

int main() {
    int ans = 0, ans_length = 0;
    for (int i = 1; i < MAX_N; i++) {
        int temp_length = get_length(i);
        if (temp_length > ans_length) {
            ans = i;
            ans_length = temp_length;
        }
    }
    printf("%d(%d)\n", ans, ans_length);
    return 0;
}
