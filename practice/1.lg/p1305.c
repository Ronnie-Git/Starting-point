/*************************************************************************
	> File Name: p1305.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月05日 星期一 20时22分21秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int k;
    struct Node *l, *r;
} Node;

Node *init(int k) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->k = k;
    p->l = p->r = NULL;
    return p;
}

void build(Node *h, char *str) {
    if (h == NULL) return ;
    if (str[0] == h->k) {
        if (str[1] != '*') h->l = init(str[1]);
        if (str[2] != '*') h->r = init(str[2]);
        return ;
    }
    build(h->l, str);
    build(h->r, str);
    return ;
}

void output(Node *h) {
    if (h == NULL) return ;
    printf("%c", h->k);
    output(h->l);
    output(h->r);
    return ;
}

void clear(Node *h) {
    if (h == NULL) return ;
    clear(h->l);
    clear(h->r);
    free(h);
    return ;
}

int main() {
    int n;
    char str[10] = {0};
    scanf("%d", &n);
    Node *h = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (!i) h->k = str[0];
        build(h, str);
    }
    output(h);
    printf("\n");
    clear(h);
    return 0;
}
