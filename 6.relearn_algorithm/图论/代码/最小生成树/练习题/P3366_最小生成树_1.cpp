#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5005 

const int INF = 0x3f3f3f3f;

typedef struct Graph {
    int n; // 点的个数 
    int vis[MAX_N]; // 是否已加入到最小生成树中 
	int dist[MAX_N]; // 每个点距最小生成树的距离 
    int mat[MAX_N][MAX_N]; // 边权 
}Graph;

void init(Graph *g, int input_n) {
    g->n = input_n;
    for (int i = 0; i <= g->n; i++) {
        for (int j = 0; j <= g->n; j++) {
            g->mat[i][j] = INF; // 将边权初始化为正无穷 
        }
    }
}

// 插入边权 
void insert(Graph *g, int x, int y, int w) {
    g->mat[x][y] = w;
    g->mat[y][x] = w;
}

// 核心代码 
int prim(Graph *g, int v) {
    int sum = 0; // 最小权值和
    for (int i = 1; i <= g->n; i++) {
        g->vis[i] = 0;
        g->dist[i] = INF; //距最小生成树的距离为正无穷 
    }
    g->dist[v] = 0; // 初始点距最小生成树的距离为0 
    
    for (int i = 1; i <= g->n; i++) {
        int min_dist = INF, min_v; // min_dist最小距离，min_v距最小生成树最近的点 
        // 找到最近点，加入树中 
		for (int j = 1; j <= g->n; j++) {
            if (!g->vis[j] && g->dist[j] < min_dist) {
                min_dist = g->dist[j];
                min_v = j;
            }
        }
        sum += min_dist;
        g->vis[min_v] = 1;
        
        // 更新与当前最近点相连的点到最小生成树的最近距离 
        for (int j = 1; j <= g->n; j++) {
            if (!g->vis[j] && g->mat[min_v][j] < g->dist[j]) {
                g->dist[j] = g->mat[min_v][j];
            }
        }
    }
    return sum;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *g = (Graph *)malloc(sizeof(Graph));
    init(g, n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b ,&c);
        insert(g, a, b, c);
    }
    int ans = prim(g, 1), flag = 0;
    for (int i = 1; i <= g->n; i++) {
    	if (g->vis[i] == 0) {
    		flag = 1;
    		break;
		}
	}
	if (flag) {
		printf("orz\n");
	} else {
		printf("%d\n", ans);
	}
    free(g);
    return 0;
} 
