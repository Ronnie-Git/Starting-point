/*************************************************************************
	> File Name: 3.hash_2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 15时54分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define MAX_N 500

struct Data {
    int val, pos;
};

vector<Data> arr;

bool cmp(Data &a, Data &b) {
    return a.val < b.val;
}

int main() {
    int n, len, val;
    map<int, int> h;
    cin >> n;
    len = n;
    while (n--) cin >> val, arr.push_back({val, len - n});
    cin >> val;
    for (auto x : arr) {
        if (h.find(val - x.val) == h.end()) {
            h[x.val] = x.pos;
            continue;
        }
        cout << x.val << " " << val - x.val << endl;
        break ;
    }
    return 0;
}
