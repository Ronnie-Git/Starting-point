/*************************************************************************
	> File Name: 1.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月17日 星期三 22时24分57秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 200005;

struct fish {
    int x;
    int y;
    fish() {}
    fish(int x, int y) : x(x), y(y) {}
    bool operator< (const struct fish &temp) const {
        if (x == temp.x) return y < temp.y;
        return x < temp.x;
    }
} num[MAX_N];

struct man {
    int x;
    int y;
    man() {}
    man(int x, int y) : x(x), y(y) {}
    bool operator< (const struct man &temp) const {
        return x < temp.x;
    }
} arr[MAX_N];

int ans[MAX_N];

int main() {
    int n, m, l;
    while (scanf("%d %d %d", &n, &m, &l) != EOF) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (b > l) continue;
            num[cnt] = fish(a - (l - b), a + (l - b));
            cnt++;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &arr[i].x);
            arr[i].y = i;
        }
        sort(num, num + cnt);
        sort(arr, arr + m);
        priority_queue<int, vector<int>, greater<int> > q;
        int ind = 0;
        for (int i = 0; i < m; i++) {
            while (ind < cnt && arr[i].x >= num[ind].x) {
                q.push(num[ind].y);
                ind++;
            }
            while (!q.empty() && q.top() < arr[i].x) q.pop();
            ans[arr[i].y] = q.size();
        }
        for (int i = 0; i < m; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
