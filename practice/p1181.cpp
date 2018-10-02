/*************************************************************************
	> File Name: p1181.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月02日 星期二 17时53分08秒
 ************************************************************************/
#include  <iostream>

using namespace std;

int main() {
    int i, N, M, a, j = 0, s = 0;
    cin >> N >> M;
    for (i = 0; i < N; i++) {
        cin >> a;
        s += a;
        if (s > M) {
            j++;
            s = a;
        }
    }
    cout << ++j;
    return 0;
}
