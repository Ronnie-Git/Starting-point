/*************************************************************************
	> File Name: 100.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 19时16分54秒
 ************************************************************************/

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL || p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
