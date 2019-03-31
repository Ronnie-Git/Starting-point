/*************************************************************************
	> File Name: 2.顺时针打印矩阵.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月30日 星期六 10时21分21秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        int cnt = matrix.size() * matrix[0].size();
        int is = 0, js = 0, ie = matrix.size() - 1, je = matrix[0].size() - 1;
        while (cnt > 0) {
            int i = is, j = js;
            ret.push_back(matrix[i][j]);
            cnt--;
            for (j = js + 1; cnt > 0 && j <= je; j++, cnt--) {
                ret.push_back(matrix[is][j]);
            }
            for (i = is + 1; cnt > 0 && i <= ie; i++, cnt--) {
                ret.push_back(matrix[i][je]);
            }
            for (j = je - 1; cnt > 0 && j >= js; j--, cnt--) {
                ret.push_back(matrix[ie][j]);
            }
            for (i = ie - 1; cnt > 0 && i > is; i--, cnt--) {
                ret.push_back(matrix[i][js]);
            }
            is++, js++, ie--, je--;
        }
        return ret;
    }
};

int main() {
    vector<vector<int> >v;
    int n;
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    
    Solution s;
    vector<int> ret = s.printMatrix(v);
    
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}
