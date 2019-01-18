/*************************************************************************
	> File Name: 100_my.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 16时20分45秒
 ************************************************************************/

bool per(struct TreeNode* p, struct TreeNode* q) {
    bool f = false;
    if (p->left && q->left && q->left->val == p->left->val) {
        if (per(p->left, q->left)) {
            f = true;
        } else {
            return false;
        }
    } else {
        if (p->left == NULL && q->left == NULL) f = true;
        else return false;
    }
    
    if (p->right && q->right && q->right->val == p->right->val) {
        if (per(p->right, q->right)) {
            if (f) return true;
            else return false;
        } else {
            return false;
        }
    } else {
        if (p->right == NULL && q->right == NULL) return true;
        return false;
    }
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL || p->val != q->val) return false;
    if (per(p, q)) return true;
    return false;
}
