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
            j = js + 1;
            while (cnt > 0 && j <= je) {
                ret.push_back(matrix[is][j]);
                j++;
                cnt--;
            }
            i = is + 1;
            while (cnt > 0 && i <= ie) {
                ret.push_back(matrix[i][je]);
                i++;
                cnt--;
            }
            j = je - 1;
            while (cnt > 0 && j >= js) {
                ret.push_back(matrix[ie][j]);
                j--;
                cnt--;
            }
            i = ie - 1;
            while (cnt > 0 && i > is) {
                ret.push_back(matrix[i][js]);
                i--;
                cnt--;
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
