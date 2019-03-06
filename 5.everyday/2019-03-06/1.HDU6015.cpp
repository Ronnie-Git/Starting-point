/*************************************************************************
	> File Name: 1.HDU6015.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月06日 星期三 20时26分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
    string str;
    int key;
} Node[105];

bool cmp(struct Node a, struct Node b) {
    return a.key > b.key;
}

int main() {
    int t, n;
    map<string, int> m; // 将map用作哈希
    cin >> t;
    while (t--) {
        m.clear();
        int sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
           cin >> Node[i].str >> Node[i].key;
        }
        sort(Node, Node + n, cmp);
        for (int i = 0; i < n; i++) {
            if (m[Node[i].str] == 2) continue;
            m[Node[i].str]++;
            sum += Node[i].key;
        }
        cout << sum << endl;
    }
    return 0;
}
