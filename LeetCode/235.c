/*************************************************************************
	> File Name: 235.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 20时49分16秒
 ************************************************************************/

int g(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, struct TreeNode **result) {
    if (root == NULL) return 0;
    int ret = (root == p || root == q);
    ret += g(root->left, p, q, result);
    if (ret == 2 && *result == NULL) *result = root;
    ret += g(root->right, p, q, result);
    if (ret == 2 && *result == NULL) *result = root;
    return ret;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *result = NULL;
    g(root, p, q, &result);
    return result;
}
