/*************************************************************************
	> File Name: AC_fx.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月12日 星期六 19时00分48秒
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

void build_automaton(Trie root) {
    root->fail = root;
    TrieNode *q[MAX_SIZE];
    int l = 0, r = 0;
    q[r++] = root;
    while (l < r) {
        TrieNode *now = q[l++];
        for (int i = 0; i < SIZE; i++) {
            if (now->childs[i] != NULL) {
            	TrieNode *child = now->childs[i];
                if (now == root) {
                	child->fail = root;
            	} else {
                    TrieNode *iter = now;
                    while (iter != root && iter->fail->childs[i] == NULL) {
                		iter = iter->fail;
            		}
                    if (iter->fail->childs[i] != NULL) {
                        child->fail = iter->fail->childs[i];
                    } else {
                        child->fail = root;
                    }
                }
                q[r++] = child;
            }
        }
    }
}

int match_count(Trie root, const char *buffer) {
    TrieNode *p = root;
    int total_count = 0;
    for (int i = 0; buffer[i]; i++) {
        while (p != root && p->childs[buffer[i] - BASE] == NULL) {
            p = p->fail;
        }
     	p = p->childs[buffer[i] - BASE]; 
        if (p == NULL) {
            p = root;
        }
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
    clear(root);
    return 0;
}
