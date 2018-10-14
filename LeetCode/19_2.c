/*************************************************************************
	> File Name: 19_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月14日 星期日 09时35分17秒
 ************************************************************************/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode ret, *p = &ret, *q = head;
    ret.next = head;
    while (n--) {
        q = q->next;
    }
    while (q != NULL) {
        p = p->next;
        q = q->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;
}
