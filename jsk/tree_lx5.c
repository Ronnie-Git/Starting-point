/*************************************************************************
	> File Name: tree_lx5.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月26日 星期五 17时12分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    char data;
    struct tree *l, *r;
} tree;

tree *init(char data) {
    tree *t = (tree *)malloc(sizeof(tree));
    t->data = data;
    t->l = t->r = NULL;
    return t;
}

void out(tree *t) {
    if (!t) return ;
    printf("%c", t->data);
    if (!t->l && !t->r) return;
    printf("(");
    if (t->l) {
        out(t->l);
    }
    if (t->r) {
        printf(",");
        out(t->r);
    }
    printf(")");
    return ;
}

void clear(tree *t) {
    if (!t) return ;
    if (t->l) clear(t->l);
    if (t->r) clear(t->r);
    free(t);
    return ;
}

tree *n[30] = {0};

int main() {
    char a[5] = {0};
    tree *t = NULL, *root = NULL;
    while (scanf("%s", a) != EOF) {
        if (a[0] == '^' && a[1] == '^') break;
        t = init(a[1]);
        n[a[1] - 'A'] = t;
        if (a[0] == '^') {
            root = t;
        } else {
            switch (a[2]) {
                case 'L' : {
                    n[a[0] - 'A']->l = t;
                } break;
                case 'R' : {
                    n[a[0] - 'A']->r = t;
                } break;
            }
        }
        memset(a, 0, sizeof(a));
    }
    out(root);
    printf("\n");
    clear(root);
    return 0;
}
