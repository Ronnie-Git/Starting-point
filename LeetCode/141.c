/*************************************************************************
	> File Name: 141.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月14日 星期日 10时54分05秒
 ************************************************************************/

bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;
    struct ListNode *c = head, *n = head->next;
    while (n != NULL && n->next != NULL) {
        c = c->next;
        n = n->next->next;
        if (c == n) return true;
    }
    return false;
}
