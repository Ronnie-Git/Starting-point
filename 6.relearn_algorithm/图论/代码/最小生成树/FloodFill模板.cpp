#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

typedef struct Graph {
    int n;
    int color[MAX_N];
    int mat[MAX_N][MAX_N];
} Graph;

void init_Graph(Graph *g, int input_n) {
    g->n = input_n;
    for (int i = 0; i < g->n; i++) {
        g->color[i] = 0;
        for (int j = 0; j < g->n; j++) {
            g->mat[i][j] = 0;
        }
    }
    return ; 
}

void insert(Graph *g, int x, int y) {
    g->mat[x][y] = 1;
    g->mat[y][x] = 1;
}

void floodfill(Graph *g) {
    int color_cnt = 0;
    int q[MAX_N];
    for (int i = 0; i < g->n; i++) {
        if (g->color[i] == 0) {
            color_cnt += 1;
            g->color[i] = color_cnt;
            int l = 0, r = 0;
            q[r++] = i;
            while (l < r) {
                int vertex = q[l++];
                for (int j = 0; j < g->n; j++) {
                    if (g->mat[vertex][j] && g->color[j] == 0) {
                        g->color[j] = color_cnt;
                        q[r++] = j;
                    }
                }
            }
        }
    }
    for (int i = 0; i < g->n; i++) {
        printf("%d %d\n", i, g->color[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *g = (Graph *)malloc(sizeof(Graph));
    init_Graph(g, n);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        insert(g, a, b);
    }
    floodfill(g);
    free(g);
    return 0;
}
