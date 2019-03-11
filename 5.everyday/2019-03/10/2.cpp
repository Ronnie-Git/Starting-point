/*************************************************************************
	> File Name: 2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月10日 星期日 19时58分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 1000000;
int arr[MAX_N + 5] = {0};
int dp[MAX_N + 5] = {0};
int len[MAX_N + 5] = {0};

int bs(int *num, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] >= x) tail = mid;
        else head = mid + 1;
    }
    return head;
}

int main() {
    memset(len, 0x3f, sizeof(len));
    int n, ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    len[dp[0]] = arr[0];
    len[0] = -1;
    for (int i = 1; i < n; i++) {
        dp[i] = bs(len, ans + 1, arr[i]);
        len[dp[i]] = arr[i];            
        if (dp[i] > ans) ans = dp[i];
    }
    return 0;
}
