/*************************************************************************
	> File Name: 1_1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月08日 星期四 18时24分15秒
 ************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int a, b, f = 0;
    int *p = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; !f && i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                p[0] = i;
                p[1] = j;
                f = 1;
                break;
            }
        }
    }
    return p;
}
