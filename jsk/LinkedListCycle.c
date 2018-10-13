/*************************************************************************
	> File Name: LinkedListCycle.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月13日 星期六 19时19分10秒
 ************************************************************************/

bool hasCycle(struct ListNode *head) {
    struct ListNode *c = head, *n = head;
    if (head == NULL) return false;
    while (c != NULL && n->next != NULL) {
        c = c->next;
        n = n->next->next;
        if (n == NULL) return false;
        if (c == n) return true;
    }
    return false;
}
