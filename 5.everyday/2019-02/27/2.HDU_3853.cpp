/*************************************************************************
	> File Name: 2.HDU_3853.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月27日 星期三 09时10分19秒
 ************************************************************************/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
 
const int MAX_N = 1010;
double dp[MAX_N][MAX_N] = {0}, p[MAX_N][MAX_N][3] = {0};
 
int main(){
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(dp, 0, sizeof(dp));
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%lf %lf %lf", &p[i][j][0], &p[i][j][1], &p[i][j][2]);
            }
        }
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                if (i == n && j == m) continue;
                if (fabs(p[i][j][0] - 1.0) < 1e-8) continue;
                dp[i][j] = (p[i][j][1] * dp[i][j + 1] + p[i][j][2] * dp[i + 1][j] + 2.00) / (1.00 - p[i][j][0]);
            }
        }
        printf("%.3lf\n", dp[1][1]);
    }
    return 0;
} 

