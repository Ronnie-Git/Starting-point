/*************************************************************************
	> File Name: test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月12日 星期六 11时46分33秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int num[1005] = {0}, flag[5] = {0}, ans[5] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        flag[num[i]]++;
    }
    for (int i = 0; i < flag[1] + flag[2]; i++) {
        if (num[i] == 3) ans[3]++;
        if (num[i] == 2 && i < flag[1]) ans[2]++;
        if (num[i] == 1 && i >= flag[1]) ans[1]++;
    } 
    cout << ans[3] + max(ans[1], ans[2]) << endl;
    return 0;
}
