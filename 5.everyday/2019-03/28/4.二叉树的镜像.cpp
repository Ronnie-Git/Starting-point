/*************************************************************************
	> File Name: 4.二叉树的镜像.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月28日 星期四 18时53分11秒
 ************************************************************************/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == nullptr) return ;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        return ;
    }
};
