/*************************************************************************
	> File Name: 1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月14日 星期日 09时30分15秒
 ************************************************************************/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = 0;
    struct ListNode *p = head, ret, *q;
    ret.next = head;
    while (p) {
        p = p->next;
        len++;
    }
    p = &ret;
    len -= n;
    while (len--) {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;
}
