/*************************************************************************
	> File Name: 203.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月14日 星期日 11时23分46秒
 ************************************************************************/

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode ret, *p = &ret, *q;
    ret.next = head;
    while (p->next) {
        if (p->next->val == val) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return ret.next;
}
