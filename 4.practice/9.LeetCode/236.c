/*************************************************************************
	> File Name: 236.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月02日 星期五 18时06分37秒
 ************************************************************************/

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root || root == p || root == q) return root; // 遍历到此时root可能为NULL, p, q
    struct TreeNode *l = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *r = lowestCommonAncestor(root->right, p, q);
    if (l && r) return root; // 如果p, q分别在左右子树找到的，那么就返回当前节点
    return !l ? r : l; // 如果子树没找到就返回右子树，否则返回左子树
}
