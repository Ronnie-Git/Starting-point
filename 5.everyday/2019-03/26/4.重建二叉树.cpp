/*************************************************************************
	> File Name: 4.重建二叉树.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月26日 星期二 18时42分14秒
 ************************************************************************/

class Solution {
public:
    TreeNode *build(vector<int> &pre, vector<int> &vin, int i, int j, int k, int l) {
        if (j < i) return nullptr;
        TreeNode *root = new TreeNode(pre[i]);
        int di = i + 1, dj = i + 1, dk = k, dl = k;
        
        // 找到左子树的区间
        while (vin[dl] != pre[i]) dl += 1, dj += 1; 
        dl -= 1, dj -= 1;
        
        // 递归建立左子树
        root->left = build(pre, vin, di, dj, dk, dl); 
        
        // 递归建立右子树
        di = dj + 1; dj = j; dk = dl + 2; dl = l; // pre[i] 是根，所以 dj + 1 是根的右孩子；vin[dl + 1] 是根，所以 dl + 2 是根的右孩子
        root->right = build(pre, vin, di, dj, dk, dl); 
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return build(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }
};
