/*************************************************************************
	> File Name: 160.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月14日 星期日 10时54分26秒
 ************************************************************************/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a = headA, *b;
    while (a != NULL) {
        b = headB;
        while (b != NULL) {
            if (b == a) return b;
            b = b->next;
        }
        a = a->next;
    }
    return NULL;
}
