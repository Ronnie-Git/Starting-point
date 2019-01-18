/*************************************************************************
	> File Name: 101.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 19时47分53秒
 ************************************************************************/

bool per(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return per(p->left, q->right) && per(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return per(root->left, root->right);
}
