/*************************************************************************
	> File Name: 110_my.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 17时34分55秒
 ************************************************************************/

int max(struct TreeNode* root) {
    if (!root) return 0;
    int x = max(root->left), y = max(root->right);
    if (x == -1 || y == -1) return -1;
    if (y > x) {
        int t = x;
        x = y;
        y = t;
    }
    if (x - y > 1) return -1;
    return 1 + x;
}

bool isBalanced(struct TreeNode* root) {
    if (!root) return true;
    if (max(root) != -1) return true;
    else return false;
}
