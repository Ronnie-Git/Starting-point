/*************************************************************************
	> File Name: 3.合并两个排序的链表.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月28日 星期四 18时51分55秒
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr || pHead2 == nullptr) return (pHead1 == nullptr ? pHead2 : pHead1);
        ListNode *ret = new ListNode(0);
        ListNode *p = ret;
        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1->val <= pHead2->val) {
                p->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        if (pHead1 == nullptr) p->next = pHead2;
        if (pHead2 == nullptr) p->next = pHead1;
        return ret->next;
    }
};
