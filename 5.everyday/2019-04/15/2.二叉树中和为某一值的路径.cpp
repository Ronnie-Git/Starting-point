/*************************************************************************
	> File Name: 2.二叉树中和为某一值的路径.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月15日 星期一 22时25分42秒
 ************************************************************************/

class Solution {
public:
    void getRet(TreeNode *root, int key, vector<vector<int> > &ret, vector<int> v, int sum) {
        if (root == nullptr) return ;
        sum += root->val;
        v.push_back(root->val);
        if (sum > key) {
            v.pop_back();
            return ;
        }
        if (sum == key && root->left == nullptr && root->right == nullptr) {
            ret.push_back(v);
            return ;
        }
        getRet(root->left, key, ret, v, sum);
        getRet(root->right, key, ret, v, sum);
        return ;
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > ret;
        vector<int> v;
        getRet(root, expectNumber, ret, v, 0);
        sort(ret.begin(), ret.end(), 
             [](vector<int> &a, vector<int> b) -> bool { return a.size() > b.size(); });
        return ret;
    }
};
