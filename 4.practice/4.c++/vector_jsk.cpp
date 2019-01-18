/*************************************************************************
	> File Name: vector_jsk.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月09日 星期三 19时02分35秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    vector<int>v;
    int temp = 0, cnt = 0;
    while (scanf("%d", &temp) != EOF) {
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << v.size() << endl;
    return 0;
}
