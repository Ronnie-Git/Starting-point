#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 5005
char a[MAXN] = {0}, b[MAXN] = {0};
int dp[MAXN][MAXN] = {0};

int main() {
    cin >> a >> b;
    int lena = strlen(a), lenb = strlen(b);
    for (int i = 1; i <= lena; i++) {
    	for (int j = 1; j <= lenb; j++) {
        	if (a[i - 1] == b[j - 1]) {
            	dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
            	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
       	}
    }
   	cout << dp[lena][lenb] << endl;
    return 0;
}
