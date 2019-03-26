/*************************************************************************
	> File Name: 3.从尾到头打印链表.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月26日 星期二 18时33分41秒
 ************************************************************************/

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        ListNode *p = head;
        while (p) {
            ret.push_back(p->val);
            p = p->next;
        }
        for (int i = 0, j = ret.size() - 1; i < j; i++, j--) {
            swap(ret[i], ret[j]);
        }
        return ret;
    }
};
