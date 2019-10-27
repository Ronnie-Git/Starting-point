#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5005 

const int INF = 0x3f3f3f3f;

typedef struct Graph {
    int n; // ��ĸ��� 
    int vis[MAX_N]; // �Ƿ��Ѽ��뵽��С�������� 
	int dist[MAX_N]; // ÿ�������С�������ľ��� 
    int mat[MAX_N][MAX_N]; // ��Ȩ 
}Graph;

void init(Graph *g, int input_n) {
    g->n = input_n;
    for (int i = 0; i <= g->n; i++) {
        for (int j = 0; j <= g->n; j++) {
            g->mat[i][j] = INF; // ����Ȩ��ʼ��Ϊ������ 
        }
    }
}

// �����Ȩ 
void insert(Graph *g, int x, int y, int w) {
    g->mat[x][y] = w;
    g->mat[y][x] = w;
}

// ���Ĵ��� 
int prim(Graph *g, int v) {
    int sum = 0; // ��СȨֵ��
    for (int i = 1; i <= g->n; i++) {
        g->vis[i] = 0;
        g->dist[i] = INF; //����С�������ľ���Ϊ������ 
    }
    g->dist[v] = 0; // ��ʼ�����С�������ľ���Ϊ0 
    
    for (int i = 1; i <= g->n; i++) {
        int min_dist = INF, min_v; // min_dist��С���룬min_v����С����������ĵ� 
        // �ҵ�����㣬�������� 
		for (int j = 1; j <= g->n; j++) {
            if (!g->vis[j] && g->dist[j] < min_dist) {
                min_dist = g->dist[j];
                min_v = j;
            }
        }
        sum += min_dist;
        g->vis[min_v] = 1;
        
        // �����뵱ǰ����������ĵ㵽��С��������������� 
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
