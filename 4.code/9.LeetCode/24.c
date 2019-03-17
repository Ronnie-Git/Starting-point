/*************************************************************************
	> File Name: 24_1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月14日 星期日 09时45分01秒
 ************************************************************************/

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode ret, *p, *q;
    ret.next = head;
    if (head == NULL || head->next == NULL) return head;
    p = &ret, q = head->next;
    while (q != NULL) {
        p->next->next = q->next;
        q->next = p->next;
        p->next = q;
        p = p->next->next;
        if (q->next->next == NULL) break;
        q = q->next->next->next;
    }
    return ret.next;
}
