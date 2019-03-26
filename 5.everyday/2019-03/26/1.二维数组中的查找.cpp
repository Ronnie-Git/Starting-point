/*************************************************************************
	> File Name: 1.二维数组中的查找.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月26日 星期二 18时30分44秒
 ************************************************************************/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        const int n = array.size(), m = array[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0 && array[i][j] != target) {
            if (array[i][j] > target) j -= 1;
            else i += 1;
        }
        return (i < n && j >= 0);
    }
};
