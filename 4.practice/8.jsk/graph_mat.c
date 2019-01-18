/*************************************************************************
	> File Name: graph_mat.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月29日 星期一 16时14分50秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 500

typedef struct Graph {
    int mat[MAX_N][MAX_N];
    int n;
}Graph;

void init(Graph *g, int len) {
    g->n = len;
    memset(g->mat, 0, sizeof(g->mat));
}

void insert(Graph *g, int a, int x, int y) {
    if (x < 0 || x >= g->n || y < 0 || y >= g->n) return ;
    switch (a) {
        case 0: g->mat[x][y] = 1; break;
        case 1: {
            g->mat[x][y] = 1;
            g->mat[y][x] = 1;
        } break;
    }
    return ;
}

void output(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            j && printf(" ");
            printf("%d", g->mat[i][j]);
        }
        printf("\n");
    }
    return ;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *g = (Graph *)malloc(sizeof(Graph));
    init(g, n);
    for (int i = 0; i < m; i++) {
        int a, x, y;
        scanf("%d %d %d", &a, &x, &y);
        insert(g, a, x, y);
    }
    output(g);
    return 0;
}
