/*************************************************************************
	> File Name: hash.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月16日 星期日 20时37分25秒
 ************************************************************************/

#ifndef _HASH_H
#define _HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *init_node(int value, Node *head) { // 头插法
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = value;
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) { // 头插法
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n + 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

int hash(HashTable *h, int key) {
    return key % h->size;
}

int insert_hashtable(HashTable *h, int value) {
    int ind = hash(h, value);
    h->data[ind] = init_node(value, h->data[ind]); // 拉链法（链表插入用头插法）
    return 1;
}

int search_hashtable(HashTable *h, int value) {
    int ind = hash(h, value);
    Node *p = h->data[ind];
    int cnt = 1;
    while (p && p->value != value) {
        p = p->next;
        cnt++;
    }
    return (p != NULL) ? cnt : -1;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) clear_node(h->data[i]);
    free(h->data);
    free(h);
    return ;
}

#endif
