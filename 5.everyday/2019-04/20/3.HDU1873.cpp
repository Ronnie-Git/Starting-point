/*************************************************************************
	> File Name: 3.HDU1873.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月20日 星期六 10时49分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef struct Node {
    int key, num;
    bool operator< (const Node &b) const {
        if (key == b.key) return num > b.num;
        return key < b.key;
    }
} Node;

int main() {
    int t;
    while (cin >> t) {
        string cmd[2];
        cmd[0] = "IN";
        cmd[1] = "EMPTY";
        priority_queue<Node> q[4];
        Node temp;
        temp.num = 0;
        for (int i = 1; i <= t; i++) {
            string str;
            int A, B;
            cin >> str;
            if (str == cmd[0]) {
                cin >> A >> B;
                temp.num++, temp.key = B;
                q[A].push(temp);
            } else {
                cin >> A;
                if (q[A].empty()) {
                    cout << cmd[1] << endl;
                    continue;
                }
                cout << q[A].top().num << endl;
                q[A].pop();
            }
        }
    }
    return 0;
}
