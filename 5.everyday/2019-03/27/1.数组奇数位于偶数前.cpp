/*************************************************************************
	> File Name: 1.数组奇数位于偶数前.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月27日 星期三 19时37分52秒
 ************************************************************************/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int cnt = 0;
        vector<int> v;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] & 1) ++cnt;
            else v.push_back(array[i]);
        }
        for (int i = 0, j = 0; i < array.size() && j < cnt; i++) {
            if (array[i] & 1) {
                array[j] = array[i];
                ++j;
            }
        }
        for (int i = cnt, j = 0; i < array.size() && j < v.size(); i++, j++) {
            array[i] = v[j];
        }
    }
};
