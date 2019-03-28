/*************************************************************************
	> File Name: 1.链表中倒数第k个结点.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月28日 星期四 18时37分57秒
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        unsigned int cnt = 0;
        ListNode *head = pListHead;
        while (pListHead != nullptr) {
            if (cnt != k) {
                cnt += 1;
            } else {
                head = head->next;
            }
            pListHead = pListHead->next;
        }
        return (k > cnt ? nullptr : head);
    }
};
