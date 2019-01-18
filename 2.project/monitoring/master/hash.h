/*************************************************************************
	> File Name: hash.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月10日 星期一 16时31分35秒
 ************************************************************************/

#ifndef _HASH_H
#define _HASH_H

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
    pthread_mutex_t  mutex;
} HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

int BKDRHash(char *str) {
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) hash = hash *seed + str[i];
    return hash & 0x7fffffff;
}

int insert_hash(HashTable *h, char *str) {
    if (pthread_mutex_lock(&h->mutex) != 0) {
        printf("insert加锁失败！\n");
        return -1;       
    }
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    if (pthread_mutex_unlock(&h->mutex) != 0) {
        printf("insert解锁失败！\n");
        return -1;
    }
    return 1;
}

int search_hash(HashTable *h, char *temp_IP) {
    if (pthread_mutex_lock(&h->mutex) != 0) {
        printf("insert加锁失败！\n");
        return -1;       
    }
    char *str = strdup(temp_IP);
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    if (pthread_mutex_unlock(&h->mutex) != 0) {
        printf("insert解锁失败！\n");
        return -1;
    }
    return p != NULL;
}

int del_hash(HashTable *h, char *str) {
    if (pthread_mutex_lock(&h->mutex) != 0) {
        printf("insert加锁失败！\n");
        return -1;       
    }
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = h->data[ind];
    Node *q = head;
    while (p && (strcmp(p->str, str) != 0)) {
        q = q->next;
        p = p->next;
    }
    if (p) {
        q->next = p->next;
        free(p);
    }
    h->data[ind] = head->next;
    if (pthread_mutex_unlock(&h->mutex) != 0) {
        printf("insert解锁失败！\n");
        return -1;
    }
    return 1;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) free(h->data[i]);
    free(h->data);
    free(h);
    return ;
}

#endif
