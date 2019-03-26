/*************************************************************************
	> File Name: 6.旋转数组的最小数字.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月26日 星期二 19时20分39秒
 ************************************************************************/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        vector<int> &arr = rotateArray;
        int head = 0, tail = arr.size() - 1, mid;
        while (head < tail) {
            mid = (head + tail) >> 1;
            if (arr[mid] < arr[0]) tail = mid;
            else head = mid + 1;
        }
        return arr[head];
    }
};
