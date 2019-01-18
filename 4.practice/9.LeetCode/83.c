/*************************************************************************
	> File Name: 83.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月14日 星期日 10时16分12秒
 ************************************************************************/

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *del, *c = head;
    while (c != NULL && c->next != NULL) {
        if (c->val == c->next->val) {
            del = c->next;
            c->next = del->next;
            free(del);
        } else {
            c = c->next;
        }
    }
    return head;
}
