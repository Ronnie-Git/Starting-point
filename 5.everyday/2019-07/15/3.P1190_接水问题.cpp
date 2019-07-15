/*************************************************************************
	> File Name: 3.P1190_接水问题.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月15日 星期一 18时42分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 10010;
const int INF = 0x3f3f3f3f;

bool cmp(int x, int y) {
    return x > y;    
}

int main() {
    int n, m;
    int arr[SIZE] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int ans = 0, min_num = INF, min_ind = 0;
    for (int i = m; i < n; i++) {
        min_num = INF, min_ind = 0;
        for (int j = 0; j < m; j++) {
            if (min_num <= arr[j])  continue;
            min_num = arr[j];
            min_ind = j;
        }
        arr[min_ind] += arr[i];
    }

    for (int i = 0; i < m; i++) {
        if (arr[i] > ans) ans = arr[i];
    }
    cout << ans << endl;
    return 0;
}
