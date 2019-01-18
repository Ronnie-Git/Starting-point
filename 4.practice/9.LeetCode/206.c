/*************************************************************************
	> File Name: 206.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月14日 星期日 11时28分44秒
 ************************************************************************/

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode ret, *p = head, *q;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
