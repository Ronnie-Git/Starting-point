/*************************************************************************
	> File Name: 4.P1080.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年05月13日 星期一 17时59分26秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_SIZE = 10005;

struct Node {
    int l, r, x;
} num[MAX_SIZE];

bool cmp(Node a, Node b) {
    return a.x < b.x;
}

// 初始化 tl, ans 数组
void init(int *tl, int *ans, int key) {
    tl[0] = ans[0] = 1;
    tl[1] = key;
    return ;
}

// 大数乘法
void mul(int *arr, int x) {
    for (int i = 1; i <= arr[0]; i++) arr[i] *= x;
    for (int i = 1; i <= arr[0]; i++) {
        if (arr[i] < 10) continue;
        arr[i + 1] += arr[i] / 10;
        arr[i] %= 10;
        arr[0] += (i == arr[0]);
    }
    return ;
}

// 大数除法
void div(int *ret, int *arr, int x) {
    int temp = 0;
    for(int i = arr[0]; i >= 1; i--) {
        temp = temp * 10 + arr[i];
        ret[i] = temp / x;
        if (ret[0] == 0 && ret[i] != 0) ret[0] = i;
        temp %= x; 
    }
    return ;
}

void copy(int *a, int *b) {
    memset(b, 0, sizeof(b));
    b[0] = a[0];
    for (int i = a[0]; i >= 1; i--) b[i] = a[i];
    return ;
}

// 比较 tl 和 ans 的大小
void mymax(int *tl, int *ans, int x) {
    int temp[MAX_SIZE] = {0};
    div(temp, tl, x);
    if (temp[0] > ans[0]) copy(temp, ans);
    if (temp[0] == ans[0]) {
        for (int i = temp[0]; i >= 1; i--) {
            if (ans[i] >= temp[i]) continue;
            copy(temp, ans);
            break;
        }    
    }
    return ;
}

void output(int *arr) {
    for (int i = arr[0]; i > 0; i--) {
        cout << arr[i];
    }
    cout << endl;
    return ;
}

int main() {
    int n, gl, gr;
    int tl[MAX_SIZE] = {0}, ans[MAX_SIZE] = {0};
    cin >> n >> gl >> gr;
    for (int i = 0; i < n; i++) {
        cin >> num[i].l >> num[i].r;
        num[i].x = num[i].l * num[i].r;
    }
    init(tl, ans, gl);

    sort(num, num + n, cmp);
    for (int i = 0; i < n; i++) {
        mymax(tl, ans, num[i].r);
        mul(tl, num[i].l);
    }
    output(ans);
    return 0;
}
