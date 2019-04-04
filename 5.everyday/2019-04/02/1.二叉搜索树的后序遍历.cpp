/*************************************************************************
	> File Name: 1.二叉搜索树的后序遍历.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月02日 星期二 20时46分38秒
 ************************************************************************/

class Solution {
public:
    bool check(vector<int> &v, int l, int r) {
        if (r - l + 1 < 3) return true;
        int ind = l, key = v[r];
        while (v[ind] < key) ++ind;
        for (int i = ind; i < r - 1; i++) {
            if (v[i] < key) return false;
        }
        return (check(v, l, ind - 1) && check(v, ind, r - 1));
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) return false;
        return (check(sequence, 0, sequence.size() - 1));
    }
};
