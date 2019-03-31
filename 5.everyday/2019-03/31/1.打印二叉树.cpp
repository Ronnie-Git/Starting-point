/*************************************************************************
	> File Name: 1.打印二叉树.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月31日 星期日 09时47分38秒
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
    void printNode() {
        while (!q.empty()) {
            if (q.front()->left) {
                ret.push_back(q.front()->left->val);
                q.push(q.front()->left);
            }
            if (q.front()->right) {
                ret.push_back(q.front()->right->val);
                q.push(q.front()->right);
            }
            q.pop();
        }
        return ;
    }
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root == nullptr) return ret; 
        q.push(root);
        ret.push_back(root->val);
        printNode();
        return ret;
    }
private:
    queue<TreeNode *> q;
    vector<int> ret;
};
