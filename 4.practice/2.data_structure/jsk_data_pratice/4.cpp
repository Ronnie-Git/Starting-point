/*************************************************************************
	> File Name: 4.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 18时08分16秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, val;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> val;
        val = (val < 0 || val > n ? 0 : val);
        arr.push_back(val);
    }
    for (int i = 0; i < n; i++) {
        while (arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    return 0;
}
