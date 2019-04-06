/*************************************************************************
	> File Name: 1.连续子数组的最大和.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月06日 星期六 20时59分33秒
 ************************************************************************/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ans = array[0], sum = 0;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] <= 0 && sum == 0) {
                if (array[i] > ans) ans = array[i];
                continue;
            }
            sum += array[i];
            if (sum > ans) ans = sum;
            if (sum <= 0) sum = 0;
        }
        return ans;
    }
};
