/*************************************************************************
	> File Name: 1.AC_trie_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月20日 星期日 09时51分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_CNT 26
#define BASE 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE_CNT], *fail, *father;
} Node;

Node *getNewNode(Node *father) {
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < BASE_CNT; i++) {
        p->next[i] = NULL;
    }
    p->father = father;
    p->flag = 0;
    p->fail = NULL;
    return p;
}

void insert(Node *node, const char *str) {
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode(p);
        }
        p = p->next[str[i] - BASE];
    }
    p->flag = 1;
    return ;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE_CNT; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

// root节点的失败指针为NULL root节点的父亲节点为NULL
void build_ac(Node *node) {
    if (node == NULL) return ;

    // 如果当前节点的失败指针为空，通过递归它的父亲节点来建立它的失败指针
    if (node->fail == NULL) build_ac(node->father); 
    
    for (int i = 0; i < BASE; i++) { // 建立每个孩子的失败指针
        if (node->next[i] == NULL) continue;
        
        // 因为在之前其他节点建立失败指针时，可能已经把当前node节点孩子的失败指针都建立完了
        if (node->next[i]->fail) continue; // 不加这句话会引发爆栈
        
        Node *p = node->fail, *pre_p = node;
        while (p && p->next[i] == NULL) {
            if (p->fail == NULL) build_ac(p->father);
            pre_p = p;
            p = p->fail;
        }

        // p等于NULL时 pre_p为root(因为root节点的失败指针为NULL) 
        if (p == NULL) p = pre_p;
        else p = p->next[i];
        node->next[i]->fail = p;
        build_ac(node->next[i]);
    }
    return ;
}

int main() {
    return 0;
}
