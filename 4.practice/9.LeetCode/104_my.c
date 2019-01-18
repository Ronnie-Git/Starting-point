/*************************************************************************
	> File Name: 104_my.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 17时19分56秒
 ************************************************************************/

int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    int x = maxDepth(root->left), y = maxDepth(root->right);
    int ans = ((x > y) ? x : y);
    return 1 + ans;
}
