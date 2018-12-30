/*************************************************************************
	> File Name: haffman.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月28日 星期日 20时01分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

typedef struct Node {
    int key, freq; 
    struct Node *lchild, *rchild;
} Node;

typedef struct priority_queue {
    Node **data;
    int cnt, size;
} priority_queue;

int swap_node(Node *p, Node *q) {
    Node temp = *p;
    *p = *q;
    *q = temp;
    return 1;
}

Node *getNewNode(int key, int freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (Node **)malloc(sizeof(Node *) * (n + 1));
    q->cnt = 0;
    q->size = n;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int push(priority_queue *q, Node *value) {
    if (q->cnt == q->size) return 0;
    q->data[++(q->cnt)] = value;
    int ind = q->cnt;
    while (ind > 1) {
        if (q->data[ind]->freq >= q->data[ind >> 1]->freq) break;
        swap_node(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (empty(q)) return 0;
    q->data[1] = q->data[(q->cnt)--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind;
        if (q->data[temp]->freq > q->data[ind << 1]->freq) temp = ind << 1;
        if ((ind << 1 | 1) <= q->cnt && q->data[temp]->freq > q->data[ind << 1 | 1]->freq) temp = ind << 1 | 1;
        if (temp == ind) break;
        swap_node(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;    
}

Node *top(priority_queue *q) {
    if (empty(q)) return 0;
    return q->data[1];
}

void clearTree(Node *r) {
    if (!r) return ;
    clearTree(r->lchild);
    clearTree(r->rchild);
    free(r);
    return ;
}

void clearQueue(priority_queue *q) {
    free(q->data);
    free(q);
    return ;
}

Node *build_haffman(priority_queue *q) {
    for (int i = q->cnt; i > 1; i--) {
        Node *a = top(q);
        pop(q);
        Node *b = top(q);
        pop(q);
        Node *temp = getNewNode(0, a->freq + b->freq);
        temp->lchild = a;
        temp->rchild = b;
        push(q, temp);
    }
    return q->data[1];
}

void extract_code(Node *root, char (*code)[20], int k, char *buff) {
    buff[k] = 0;
    if (root->key) { 
        strcpy(code[root->key], buff);
        return ;
    }
    buff[k] = '0';
    extract_code(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_code(root->rchild, code, k + 1, buff);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    priority_queue *q = init(n);
    Node *root;
    for (int i = 0; i < n; i++) {
        char key[10];
        int freq;
        scanf("%s%d", key, &freq);
        push(q, getNewNode(key[0], freq));
    }
    root = build_haffman(q);
    char code[256][20] = {0}, buff[20] = {0};
    extract_code(root, code, 0, buff);
    for (int i = 0; i < 256; i++) {
        if (code[i][0] == 0) continue;
        printf("%c : %s\n", i, code[i]);
    }
    clearTree(root);
    clearQueue(q);
    return 0;
}
