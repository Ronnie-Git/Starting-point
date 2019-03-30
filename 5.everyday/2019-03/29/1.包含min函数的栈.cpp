/*************************************************************************
	> File Name: 1.包含min函数的栈.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月30日 星期六 10时16分48秒
 ************************************************************************/

class Solution {
public:
    void push(int value) {
        s1.push(value);
        if (s2.empty() || value <= s2.top()) s2.push(value);
        return ;
    }
    void pop() {
        if (s1.top() == s2.top()) s2.pop();
        s1.pop();
        return ;
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};
