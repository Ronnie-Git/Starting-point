/*************************************************************************
	> File Name: 2.P1433.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月30日 星期三 22时29分15秒
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cfloat>

using namespace std;

int n, vis[1001] = {0};
double x[105] = {0}, y[105] = {0}, num[1005][1005] = {0};
double ans = DBL_MAX;

void dfs(int k, int ind, double sum) {
    if (sum > ans) return;                                     
    if (k == n) {
        ans = min(ans, sum); 
        return ;
    }
    for (int i = 1; i <= n; i++) { 
        if(!vis[i]) {
            vis[i] = 1;
            dfs(k + 1, i, sum + num[ind][i]); 
            vis[i] = 0; 
        }
    }
}

void get_num() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            num[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    get_num();
    dfs(0, 0, 0.0); 
    printf("%.2lf\n",ans);
    return 0;
}
