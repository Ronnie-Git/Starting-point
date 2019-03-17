/*************************************************************************
	> File Name: 237.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月14日 星期日 11时36分18秒
 ************************************************************************/

void deleteNode(struct ListNode* node) {
    struct ListNode *q = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    free(q);
    return ; 
}
