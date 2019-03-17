/*************************************************************************
	> File Name: 110_1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 20时11分58秒
 ************************************************************************/

int getHeight(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left), r = getHeight(root->right);
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (!root) return true;
    int l = getHeight(root->left), r = getHeight(root->right);
    if (abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
