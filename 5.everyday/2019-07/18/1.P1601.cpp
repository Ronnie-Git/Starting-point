/*************************************************************************
	> File Name: 1.P1601.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月18日 星期四 21时14分34秒
 ************************************************************************/

// A+B Problem (高精)
#include<iostream>
#include<cstring>
using namespace std;

const int SIZE = 1005;

void big(char *a, char *b, int *arr) {
    int lena = strlen(a), lenb = strlen(b);
    arr[0] = (lena > lenb ? lena : lenb);
    for (int i = 0; i < lena; i++) arr[lena - i] += (a[i] - '0');
    for (int i = 0; i < lenb; i++) arr[lenb - i] += (b[i] - '0');

    for (int i = 1; i <= arr[0]; i++) {
        if (arr[i] < 10) continue;
        arr[i + 1] += arr[i] / 10;
        arr[i] %= 10;
        arr[0] += (i == arr[0]);
    }
    return ;
}

void output(int *ans) {
    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return ;
}

int main() {
    char a[SIZE] = {0}, b[SIZE] = {0};
    int ans[SIZE] = {0};
    cin >> a >> b;
    big(a, b, ans);
    output(ans);
    return 0;
}
