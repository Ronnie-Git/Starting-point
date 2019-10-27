#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
}

void insert(Graph *g, int x, int y) {
    g->mat[x][y] = 1;
    g->mat[y][x] = 1;
}

void floodfill(Graph *g, int *ind) {
    int cnt = 0;
    int q[MAX_N] = {0};
    for (int i = 0; i < g->n; i++) {
    	if (g->color[i]) continue;
    	cnt += 1;
    	g->color[i] = cnt;
    	int l = 0, r = 0;
    	q[r++] = i;
    	while (l < r) {
    		int qb = q[l++];
    		for (int j = 0; j < g->n; j++) {
    			if (g->mat[qb][j] && g->color[j] == 0) {
    				g->color[j] = cnt;
    				q[r++] = j;
				}
			}
		}
	}
	*ind = cnt;
    return ;
}

void output(Graph *g, int ind) {
	for (int i = 1; i <= ind; i++) {
		printf("%d:", i);
		for (int j = 0; j < g->n; j++) {
			if (g->color[j] == i) {
				printf("%d ", j);
			}
		}
		printf("\n");
	}
	return ;
}

int main() {
    int n, m;
    Graph *g = (Graph *)malloc(sizeof(Graph));
    scanf("%d %d", &n, &m);
    init_Graph(g, n);
    for (int i = 0; i < m; i++) {
    	int a, b;
    	scanf("%d %d", &a, &b);
    	insert(g, a, b);
	}
	int ind = 0;
	floodfill(g, &ind);
	output(g, ind);
	free(g);
    return 0;
}
