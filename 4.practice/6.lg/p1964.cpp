/*************************************************************************
	> File Name: p1964.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 15时19分22秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct thing {
    int a, b, c;
    char s[105];
} thing;

bool cmp(thing x, thing y) {
    return (x.a * x.b) > (y.a * y.b);
}

int main() {
    int n, m, a, b, c, sum = 0, k = 0;
    char s[105] = {0};
    thing num[105];
    cin >> m >> n;
    m = 21 - m;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> s;
        int flag = 0;
        for (int j = 0; j < k; j++) {
            if (!strcmp(num[j].s, s)) {
                if (a + num[j].a <= num[j].c) {
                    num[j].a += a;
                    flag = 1;
                    break;    
                } else {
                    a = a - (num[j].c - num[j].a);
                    num[j].a = num[j].c;
                }
            }
        }
        if (flag == 0) {
            num[k].a = a; num[k].b = b; num[k].c = c;
            strcpy(num[k].s, s);
            k++;
        }
    }
    sort(num, num + k, cmp);
    for (int i = 0; i < m; i++) {
        sum += (num[i].a * num[i].b);
    }
    cout << sum << endl;
    return 0;
}
