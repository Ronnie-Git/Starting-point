/*************************************************************************
	> File Name: 1.把数组拍成最小的数.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月16日 星期二 21时03分46秒
 ************************************************************************/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        string ret;
        do {
            string temp;
            for (int i = 0; i < numbers.size(); i++) {
                temp += to_string(numbers[i]);
            }
            if (ret == "") {
                ret = temp;
                continue;
            }
            if (temp < ret) ret = temp;
        } while (next_permutation(numbers.begin(), numbers.end()));
        return ret;
    }
};
