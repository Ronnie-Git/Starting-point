/*************************************************************************
	> File Name: p1507.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 14时33分17秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, max_m, max_v;
    int ans[405][405] = {0}, m[55] = {0}, v[55] = {0}, w[55] = {0}; 
    scanf("%d %d", &max_v, &max_m);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &v[i], &m[i], &w[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = max_v; j >= v[i]; j--) {
            for (int l = max_m; l >= m[i]; l--) {
                ans[j][l] = max(ans[j][l], ans[j - v[i]][l - m[i]] + w[i]);
            }
        }
    }
    printf("%d\n", ans[max_v][max_m]);
    return 0;
}
