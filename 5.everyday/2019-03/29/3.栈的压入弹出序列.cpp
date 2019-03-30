/*************************************************************************
	> File Name: 3.栈的压入弹出序列.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月30日 星期六 17时07分21秒
 ************************************************************************/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size()) return false;
        stack<int> s;
        int j = 0;
        for (int i = 0; i < pushV.size(); i++) {
            s.push(pushV[i]);
            while (!s.empty() && s.top() == popV[j]) {
                s.pop();
                j++;
            }
        }
        return (j == popV.size());
    }
};
