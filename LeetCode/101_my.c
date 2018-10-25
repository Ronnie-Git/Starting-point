/*************************************************************************
	> File Name: 101_my.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 17时07分34秒
 ************************************************************************/

bool per(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val == q->val) {
        if (per(p->left, q->right) && per(p->right, q->left)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    if (per(root->left, root->right)) return true;
    else return false;
}
