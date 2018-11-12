/*************************************************************************
	> File Name: 219_1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月12日 星期一 19时53分26秒
 ************************************************************************/

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int l = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize && j <= i + k; j++) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}
