/*************************************************************************
	> File Name: 1.字符串的排列.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月04日 星期四 18时22分50秒
 ************************************************************************/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ret;
        if (str == "") return ret;
        sort(str.begin(), str.end());
        do {
            ret.push_back(str);
        } while (next_permutation(str.begin(), str.end()));
        return ret;
    }
};
