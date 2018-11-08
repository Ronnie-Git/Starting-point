/*************************************************************************
	> File Name: 1_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月08日 星期四 18时24分32秒
 ************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define swap(a, b) { \
    __typeof(a) _temp = a; a= b; b = _temp; \
}

void quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (num[x] < z) ++x;
            while (num[y] > z) --y;
            if (x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort(num, x, r);
        r = y;
    }
    return ;
}

int* twoSum(int* nums, int numsSize, int target) {
    int *temp = (int *)malloc(sizeof(int) * (numsSize));
    memcpy(temp, nums, sizeof(int) * numsSize);
    quick_sort(nums, 0, numsSize - 1);
    int p = 0, q = numsSize - 1;
    while (nums[p] + nums[q] != target) {
        if (nums[p] + nums[q] < target) ++p;
        else --q;
    }
    int *ret = (int *)malloc(sizeof(int) * 2);
    int ans = 2;
    for (int i = 0; i < numsSize && ans; i++) {
        if (temp[i] == nums[p] || temp[i] == nums[q]) {
            ret[2 - ans] = i;
            ans--;
        }
    }
    free(temp);
    return ret;
}
