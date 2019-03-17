/*************************************************************************
	> File Name: 4_1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月08日 星期四 19时58分30秒
 ************************************************************************/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int k = (nums1Size + nums2Size + 1) / 2, p = (nums1Size + nums2Size) & 1, i = 0, j = 0, cnt = 0, temp = 0;
    double ans = 0;
    while ((i < nums1Size || j < nums2Size) && cnt <= k + 1) {
        cnt++;
        if (j >= nums2Size || (i < nums1Size && nums1[i] <= nums2[j])) temp = nums1[i++];
        else temp = nums2[j++];
        if (cnt == k) ans = temp;
        if (!p && cnt == k + 1) ans = (ans + temp) / 2.0;
    }
    return ans;
}
