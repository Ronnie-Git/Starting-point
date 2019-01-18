/*************************************************************************
	> File Name: 112.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 20时27分08秒
 ************************************************************************/

bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root) return false;
    if (root->left == NULL && root->right == NULL) return root->val == sum;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val); 
}
