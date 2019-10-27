#include<iostream>
using namespace std;

#define maxn 1000
#define INF 0x3f3f3f3f

int g[maxn][maxn];
int arr[10005];

void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    return ;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    floyd(n);
    int sum = 0;
    for (int i = 1; i < m; i++) {
        sum += g[arr[i - 1]][arr[i]];
    }
    cout << sum << endl;
    return 0;
}

