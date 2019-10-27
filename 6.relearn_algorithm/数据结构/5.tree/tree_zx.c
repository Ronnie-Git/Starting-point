/*************************************************************************
> File Name: h.c
> Author: x
> Mail: x.com
> Created Time: 2018年10月23日 星期二 19时39分08秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000
#define MAX_K 20

struct Edge {
    int v, n;
} g[MAX_N << 1]; // g数组中存的是两个点之间的连接关系

// head数组存的是下一个连接点连接关系的下标（g数组的下标）， cnt一共有多少关系（g数组有多少元素）
int head[MAX_N + 5] = {0}, cnt = 0;

// 内联函数  如果一些函数被频繁调用，不断地有函数入栈，即函数栈，会造成栈空间或栈内存的大量消耗。这时便使用内联函数
inline void add(int a, int b) { // a是父亲节点 b是字节点
    g[++cnt].v = b; // v是下一个点
    g[cnt].n = head[a]; // n是a（父节点）的原来的下标
    head[a] = cnt; // 更新head[a]
    return ;
}

//gas[i][j] -> i点往上走2^j步，所能到达的祖先节点编号
int gas[MAX_N][MAX_K] = {0}, dep[MAX_N] = {0};

//为什么0节点不用？

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

    for (int i = 0; i < MAX_K; i++) { // 对齐
        // 倍增法
        if ((l & (1 << i))) b = gas[b][i];
    }

    if (a == b) return a;
    
    for (int i = MAX_K - 1; i >= 0; i--) { // 一起走
        // 二进制的每一位加在一起可以遍历任意层数深度
        if (gas[a][i] != gas[b][i]) a = gas[a][i], b = gas[b][i];
        // a和b一定会跳到第一个公共祖先的下面的左右字节点
    }

    return gas[a][0];
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("lca(%d, %d) = %d, a -> b = %d\n", a, b, lca(a, b), dep[a] + dep[b] - 2 * dep[lca(a, b)]);
    }

    return 0;
}
