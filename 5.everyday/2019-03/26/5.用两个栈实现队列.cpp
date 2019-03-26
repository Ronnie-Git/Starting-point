/*************************************************************************
	> File Name: 5.用两个栈实现队列.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月26日 星期二 19时05分27秒
 ************************************************************************/

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
