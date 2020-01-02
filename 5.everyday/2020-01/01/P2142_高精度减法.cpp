/*************************************************************************
	> File Name: P2142_高精度减法.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Jan 2020 06:38:34 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define max(a, b) (a > b ? a : b)
#define MAXN 20005
int ans[MAXN];
char stra[MAXN], strb[MAXN];
int flag = 1; // 记录答案的正负，1为正，-1为负

void init(int *a, int *b) {
    int lena = strlen(stra), lenb = strlen(strb);
    for (int i = lena - 1; i >= 0 && stra[i] != '-'; i--) a[++a[0]] = stra[i] - 48;
    for (int i = lenb - 1; i >= 0 && strb[i] != '-'; i--) b[++b[0]] = strb[i] - 48;
    return ;
}

// 比较 a 和 b 的大小
bool cmp(int *a, int *b) {
    if (a[0] > b[0]) return true;
    if (a[0] < b[0]) return false;
    for (int i = a[0]; i > 0; i--) if (a[0] < b[0]) return false;
    return true;
}

// a + b
void add(int *a, int *b) {
    int len = max(a[0], b[0]);
    ans[0] = len;
    for (int i = 1; i <= len; i++) ans[i] = a[i] + b[i];
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == ans[0]);
    }
    return ;
}

// a - b
void sub(int *a, int *b) {
    int len = max(a[0], b[0]);
    ans[0] = len;
    for (int i = 1; i <= len; i++) ;
    for (int i = 1; i <= ans[0]; i++) {
        if (a[i] < b[i]) {
            a[i + 1] -= 1;
            a[i] += 10;
        }
        ans[i] = a[i] - b[i];
    }
    while (ans[0] > 1 && ans[ans[0]] == 0) --ans[0];
    return ;
}

// 输出答案
void output() {
    if (flag == -1) cout << '-';
    for (int i = ans[0]; i >= 1; i--) cout << ans[i];
    cout << endl;
    return ;
}

void solve() {
    int a[MAXN] = {0}, b[MAXN] = {0};
    init(a, b);
    if (stra[0] == '-' && strb[0] == '-') { // -a - (-b) = b - a
        if (cmp(b, a)) sub(b, a);
        else flag *= -1, sub(a, b);
    } else if (stra[0] == '-') { // -a - b = -(a + b)
        flag *= -1;
        add(a, b);
    } else if(strb[0] == '-') { // a - (-b) = a + b
        add(a, b);
    } else {
        if (cmp(a, b)) sub(a, b);
        else flag *= -1, sub(b, a);
    }
    output();
    return ;
}

int main() {
    cin >> stra >> strb;
    solve();
    return 0;
}
