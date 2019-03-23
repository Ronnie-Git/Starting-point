/*************************************************************************
	> File Name: 3.HDU_10002.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月23日 星期六 17时13分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int SIZE = 1005;

void func_plus(char *temp, int *ans) {
    int len = strlen(temp);
    ans[0] = max(ans[0], len);
    for (int i = len - 1; i >= 0; i--) {
        ans[len - i] += (temp[i] - '0');
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == ans[0]);
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        if (i > 1) printf("\n");
        char a[SIZE] = {0}, b[SIZE] = {0};
        int ans[SIZE] = {0};
        cin >> a >> b;
        printf("Case %d:\n", i);
        func_plus(a, ans);
        func_plus(b, ans); 
        printf("%s + %s = ", a, b);
        for (int i = ans[0]; i >= 1; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
