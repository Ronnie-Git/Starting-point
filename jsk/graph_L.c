/*************************************************************************
	> File Name: graph_L.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月29日 星期一 16时14分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000

typedef struct Node {
    int vertex;
    struct Node *next;
} Node, *LinkedList;

LinkedList insert_node(LinkedList head, int index) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->vertex = index;
    node->next = head;
    head = node;
    return head;
}

typedef struct Graph {
    LinkedList e[MAX_N];
    int n;
} Graph;

void init(Graph *g, int n) {
    g->n = n;
    for (int i = 0; i < g->n; i++) {
        g->e[i] = NULL;
    }
    return ;
}

void insert(Graph *g, int a, int x, int y) {
    if (x < 0 || x >= g->n || y < 0 || y >= g->n) return ;
    switch (a) {
        case 0: {
        	g->e[x] = insert_node(g->e[x], y);
        } break;
        case 1: {
            g->e[x] = insert_node(g->e[x], y);
            g->e[y] = insert_node(g->e[y], x);
        } break;
    }
}

void output(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("%d:", i);
        for (Node *j = g->e[i]; j; j = j->next) {
            printf(" %d", j->vertex);
        }
        printf("\n");
    }
    return ;
}

void clear(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        Node *head = g->e[i];
        while (head != NULL) {
            Node *p = head;
            head = head->next;
            free(p);
        }
    }
    free(g);
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
    clear(g);
    return 0;
}
