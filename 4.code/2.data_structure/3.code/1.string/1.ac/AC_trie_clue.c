/*************************************************************************
	> File Name: 1.AC_trie_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月20日 星期日 09时51分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;
const char BASE = 'a';
const int MAX_SIZE = 100000;
const int MAX_LEN = 1000;

typedef struct TrieNode {
    int count;
    struct TrieNode** childs;
    struct TrieNode* fail;
} TrieNode, *Trie;

TrieNode* new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
    p->count = 0;
    return p;
}
/*
void clear(TrieNode *p) {
    if (p != NULL) {
        for (int i = 0; i < SIZE; i++) {
            if (p->childs[i] != NULL) {
                clear(p->childs[i]);
            }
        }
        free(p->childs);
        free(p);
    }
}
*/
void insert(Trie trie, char *buffer) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(buffer); i++) {
        if (p->childs[buffer[i] - BASE] == NULL) {
            p->childs[buffer[i] - BASE] = new_node();
        }
        p = p->childs[buffer[i] - BASE];
    }
    p->count++;
}

void build_automaton(TrieNode *node) {
    TrieNode **queue = (TrieNode **)malloc(sizeof(TrieNode *) * (MAX_SIZE + 5));
    int head = 0, tail = 0;
    queue[tail++] = node;
    while (head < tail) {
        TrieNode *now = queue[head++];
        for (int i = 0; i < SIZE; i++) {
            if (now->childs[i] == NULL) {
                // 如果当前孩子节点为NULL 并且不是根节点的孩子 则存该孩子节点的失败指针
                if (now != node) now->childs[i] = now->fail->childs[i];
                continue;
            }
            TrieNode *p = (now->fail ? now->fail->childs[i] : node);
            if (p == NULL) p = node;
            now->childs[i]->fail = p; // 更新当前孩子节点(当前孩子节点存在，并且存的一定不是线索)该失败指针
            queue[tail++] = now->childs[i];
        }
    }
    return ;
}

int match_count(Trie root, const char *buffer) {
    TrieNode *p = root;
    int total_count = 0;
    for (int i = 0; buffer[i]; i++) {
     	p = p->childs[buffer[i] - BASE]; 
        TrieNode *iter = p;
        while (iter != root) {
            total_count += iter->count;
            iter = iter->fail;
        }
    }
    return total_count;
}

int main() {
    Trie root = new_node();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char pattern[MAX_LEN + 5];
        scanf("%s", pattern);
        insert(root, pattern);
    }
    build_automaton(root);
    char str_buffer[MAX_SIZE + 5];
    scanf("%s", str_buffer);
    printf("%d\n", match_count(root, str_buffer));
    //clear(root);
    return 0;
}
