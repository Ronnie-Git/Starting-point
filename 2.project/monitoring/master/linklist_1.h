/*************************************************************************
	> File Name: LinkedList.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月11日 星期四 20时23分22秒
 ************************************************************************/

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
typedef struct LinkNode {
    int port;
    int flag;
    char *IP;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    pthread_mutex_t  mutex;
    int cnt;
    int length;
} LinkList;

LinkList *init(int cnt) {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->head.next = NULL;
    p->cnt = cnt;
    p->length = 0;
    pthread_mutex_init(&p->mutex, NULL);
    return p;
}

LinkNode *getNewNode(char *IP, int port) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->port = port;
    p->IP = strdup(IP);
    p->next = NULL;
    return p;
}

int search(LinkList *l, char *IP) {
    LinkNode *p = l->head.next;
    while (p) {
        if (strcmp(p->IP, IP) == 0) return 1;
        p = p->next;
    }
    return 0;
}

int insert(LinkList *l, char *IP, int port) {
    if (pthread_mutex_lock(&l->mutex) != 0) {
        printf("insert加锁失败！\n");
        return -1;       
    }
    LinkNode *p = &(l->head);
    while (p->next) {
        p = p->next;
    }
    LinkNode *new_node = getNewNode(IP, port);
    //new_node->next = p->next;
    p->next = new_node;
    l->length += 1;
    if (pthread_mutex_unlock(&l->mutex) != 0) {
        printf("insert解锁失败！\n");
        return -1;
    }
    return 1;
}
void del(LinkList *l, LinkNode *del_node) {
    if (pthread_mutex_lock(&l->mutex) != 0) {
        printf("del加锁失败！\n");
        return (void )-1;
    }
    LinkNode *p = &(l->head);
    while (p->next != NULL) {
        if (p->next->port != del_node->port || strcmp(p->next->IP, del_node->IP) != 0) {
            p = p->next;
            continue;
        }
        LinkNode *q = p->next;
        p->next = p->next->next;
        free(q);
        l->length -= 1;
        break;
    }
    if (pthread_mutex_unlock(&l->mutex) != 0) {
        printf("del解锁失败！\n");
        return (void )-1;
    }
    return ;
}
/*
void clear(LinkList *l) {
    if (l->head.next == NULL) return ;
    LinkNode *p = l->head.next, *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return ;
}
*/
void output(LinkList *l) {
    if (pthread_mutex_lock(&l->mutex) != 0) {
        printf("output加锁失败!\n");
        return (void )-1;
    }
    printf("-----------------------------------------\n");
    printf("线程%d:\n", l->cnt);
    LinkNode *p = l->head.next;
    while (p != NULL) {
        printf("%s %d\n", p->IP, p->port);
        //printf("%s %d %d\n", p->IP, p->port, p->flag);
        p = p->next;
    }
    printf("-----------------------------------------\n\n");
    if (pthread_mutex_unlock(&l->mutex) != 0) {
        printf("output解锁失败!\n");
        return (void )-1;
    }
    return ;
}
