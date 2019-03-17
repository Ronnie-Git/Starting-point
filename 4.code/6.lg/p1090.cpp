/*************************************************************************
	> File Name: p1090.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月28日 星期五 16时26分33秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue <int, vector<int>, greater<int> > q;
    int n, num, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        q.push(num);
    }
    while (q.size() > 1) {
        int x = q.top();
        q.pop();
        x += q.top();
        sum += x;
        q.pop();
        q.push(x);
    }
    printf("%d\n", sum);
    q.pop();
    return 0;
}
