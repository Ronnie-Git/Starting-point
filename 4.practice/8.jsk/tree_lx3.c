/*************************************************************************
	> File Name: tree_gyb.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月24日 星期三 18时54分34秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000000

typedef struct Node {
    char *data;
    int len;
} Node;

Node *init() {
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = (char *)malloc(sizeof(char) * SIZE);
    s->len = 0;
    return s;
}

void output(Node *s, int n) {
    if (s == NULL) return ;
    int flag = 0;
    printf("%c", s->data[n]);
    if (2 * n > s->len) {
        return;
    } else {
        printf("(");
        output(s, 2 * n);
        flag = 1;
    }
    if (2 * n + 1 > s->len) {
        flag && printf(")");
        return;
    } else {
        printf(","); 
        output(s, 2 * n + 1);
        flag = 1;
    }
    flag && printf(")");
    return ;
}

void clear(Node *s) {
    free(s->data);
    free(s);
    return ;
}

int main() {
    char a;
    Node *s = init();
    while (scanf("%c", &a) && a != '$') {
        if (a == ' ') continue;
        s->len++;
        s->data[s->len] = a;
    }
    if (s->len) output(s, 1);
    printf("\n");
    clear(s);
    return 0;
}
