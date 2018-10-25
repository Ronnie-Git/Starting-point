/*************************************************************************
	> File Name: 110_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 20时16分40秒
 ************************************************************************/

int getHeight(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left);
    if (l < 0) return -2;
    int r = getHeight(root->right);
    if (abs(l - r) > 1) return -2;
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (!root) return true;
    return getHeight(root) > 0;
}
