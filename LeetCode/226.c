/*************************************************************************
	> File Name: 226.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 20时34分25秒
 ************************************************************************/

struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root) return root;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
