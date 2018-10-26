/*************************************************************************
> File Name: h.c
> Author: x
> Mail: x.com
> Created Time: 2018年10月23日 星期二 19时39分08秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000
#define MAX_K 25

#define eq(a, b, c) ((a == b) ? c : ((a == c) ? b : a))

struct Edge {
    int v, n;
} g[MAX_N << 1];

int head[MAX_N + 5] = {0}, cnt = 0;

inline void add(int a, int b) {
    g[++cnt].v = b;
    g[cnt].n = head[a];
    head[a] = cnt;
    return ;
}

int gas[MAX_N][MAX_K] = {0}, dep[MAX_N] = {0};

void dfs(int u, int father) {
    gas[u][0] = father;
    dep[u] = dep[father] + 1;
    for (int i = 1; i < MAX_K; i++) {
        gas[u][i] = gas[gas[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i; i = g[i].n) {
        if (g[i].v == father) continue;
        dfs(g[i].v, u);
    }
    return ;
}

int lca(int a, int b) {
    if (dep[b] < dep[a]) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int l = dep[b] - dep[a];
    for (int i = 0; i < MAX_K; i++) {
        if ((l & (1 << i))) b = gas[b][i];
    }
    if (a == b) return a;
    for (int i = MAX_K - 1; i >= 0; i--) {
        if (gas[a][i] != gas[b][i]) a = gas[a][i], b = gas[b][i];
    }
    return gas[a][0];
}

int main() {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        int x = lca(a, b), y = lca(b, c), z = lca(a, c), ans = 0;
        ans = eq(x, y, z);
        printf("%d %d\n", ans, dep[a] + dep[b] + dep[c] - dep[x] - dep[y] - dep[z]);
    }
    return 0;
}
