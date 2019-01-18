/*************************************************************************
	> File Name: trie.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月30日 星期日 20时38分47秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#define BASE_CNT 26
#define BASE 'a'

using namespace std;

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
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
        }
        p = p->next[str[i] - BASE];
    }
    if (p->flag) return 0;
    p->flag = 1;
    return 1;
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
    char str[100005] = {0};
    while (scanf("%[^\n]s", str) != EOF) {
        getchar();
        if (strcmp(str, "#") == 0) break;
        int ans = 0, i = 0, j = 0;
        Node *root = getNewNode();
        char temp[100005] = {0};
        while (str[i]) {
            if (str[i] == ' ') {
                if (temp[0] != '\0' && temp[0] != ' ')ans += insert(root, temp);
                memset(temp, 0, sizeof(temp));
                j = 0;
            } else {
                temp[j] = str[i];
                j++;
            }
            i++;
        }
        if (temp[0] != '\0' && temp[0] != ' ') ans += insert(root, temp);
        printf("%d\n", ans);
        clear(root);
    }
    return 0;
}
