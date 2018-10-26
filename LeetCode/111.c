/*************************************************************************
	> File Name: 111.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月26日 星期五 16时43分34秒
 ************************************************************************/

int minDepth(struct TreeNode* root) {
    if (!root) return 0;
    int x = 1 + minDepth(root->left), y = 1 + minDepth(root->right);
    if (x == 1) return y;
    if (y == 1) return x;
    return  (x > y ? y : x);
}
