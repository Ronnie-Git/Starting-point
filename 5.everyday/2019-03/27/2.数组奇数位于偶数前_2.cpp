/*************************************************************************
	> File Name: h.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月27日 星期三 22时12分09秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int j = 0;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 0) continue;
            int temp = array[i];
            int k = i;
            while (k > j) {
                array[k] = array[k - 1];
                --k;
            }
            array[j] = temp;
            j++;
        }
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    s.reOrderArray(v);
    cout << "cdsc" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "  ";
    }
    cout << endl;
    return 0;
}
