/*************************************************************************
	> File Name: AC_trie.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 21时10分47秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE], *fail;
} Node;

typedef struct Queue {
    Node **data;
    int head, tail, size;
} Queue;

Queue *init_queue(int n) {
    Queue *q = (Queue *)calloc(sizeof(Queue), 1);
    q->data = (Node **)malloc(sizeof(Node *) * n);
    q->tail = q->head = 0;
    return q;
}

Node *front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->head == q->tail;
}

void push(Queue *q, Node *node) {
    q->data[q->tail++] = node;
    return ;
}

void pop(Queue *q) {
    if (empty(q)) return ;
    q->head++;
}

void clear_queue(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, const char *str, int *ind) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), ++cnt;
        p = p->next[ind];
    }
    if (p->flag == 0) p->flag = *ind;
    else *ind = p->flag;
    return cnt;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

void build_ac(Node *root, int n) {
    Queue *q = init_queue(n + 10);
    root->fail = NULL;
    push(q, root);
    while (!empty(q)) {
        Node *now_node = front(q);
        pop(q);
        for (int i = 0; i < BASE; i++) {
            if (now_node->next[i] == NULL) continue;
            Node *p = now_node->fail;
            while (p && p->next[i] == NULL) p = p->fail;
            if (p == NULL) now_node->next[i]->fail = root;
            else now_node->next[i]->fail = p->next[i];
            push(q, now_node->next[i]);
        }
    }
    return ;
}

void match(Node *root, const char *str, int *num) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        while (p && p->next[ind] == NULL) p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[ind];
        Node *q = p;
        while (q) {
            if (q->flag) num[q->flag]++;
            q = q->fail;
        }
    }
    return ;
}

int main() {
    Node *root = getNewNode();
    int n, cnt = 0;
    char str[100005] = {0};
    
    // num数组存编号（第一个模式串的编号设为1而不是0）如果当前字符串之前已经出现过，那么存第一次出现的编号（结构体中flag存的是编号）
    int num[1005] = {0};
    // num2数组存存该号字符串出现了几次
    int num2[1005] = {0};
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int ind = i + 1;
        scanf("%s", str);
        cnt += insert(root, str, &ind);
        num[i] = ind;
    }
    build_ac(root, cnt);
    scanf("%s", str);
    match(root, str, num2);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, num2[num[i]]);
    }
    return 0;
}
