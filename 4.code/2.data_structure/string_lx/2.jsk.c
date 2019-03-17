/*************************************************************************
	> File Name: trie.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月30日 星期日 20时38分47秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_CNT 26
#define BASE 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE_CNT];
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < BASE_CNT; i++) {
        p->next[i] = NULL;
    }
    p->flag = 0;
    return p;
}

int insert(Node *node, const char *str) {
    int cnt = 0;
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
            cnt += 1;
        }
        p = p->next[str[i] - BASE];
    }
    p->flag = 1;
    return cnt;
}

int search(Node *node, const char *str) {
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            return 0;
        }
        p = p->next[str[i] - BASE];
    }
    return p->flag;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE_CNT; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Node *root = getNewNode();
        char str[100] = {0};
        int ans = 0, max = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            if (max < strlen(str)) max = strlen(str);
            ans = ans + 2 * insert(root, str) + 1;
        }
        printf("%d\n", ans - max);
        clear(root);
    }
    return 0;
}
