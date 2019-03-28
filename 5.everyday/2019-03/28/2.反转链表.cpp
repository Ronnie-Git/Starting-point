/*************************************************************************
	> File Name: 2.反转链表.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月28日 星期四 18时50分33秒
 ************************************************************************/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr) return nullptr;
        ListNode *p = nullptr, *q = pHead;
        while (pHead != nullptr) {
            pHead = pHead->next;
            q->next = p;
            p = q;
            q = pHead;
        }
        return p;
    }
};
