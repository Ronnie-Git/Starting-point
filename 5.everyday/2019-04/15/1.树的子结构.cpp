/*************************************************************************
	> File Name: 1.树的子结构.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月15日 星期一 21时57分35秒
 ************************************************************************/

class Solution {
public:
    bool check(TreeNode *p, TreeNode *q) {
        if (q == nullptr) return true;
        if (p == nullptr) return false;
        if (p->val != q->val) return false;
        return (check(p->left, q->left) && check(p->right, q->right));
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
        if (check(pRoot1, pRoot2) == true) return true;
        return (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
    }
};
