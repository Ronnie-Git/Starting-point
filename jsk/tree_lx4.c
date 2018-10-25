/*************************************************************************
	> File Name: tree_lx4.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 16时25分29秒
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

int i = 1, m = 0;
void build(Node *s, char *str, int n) {
    int flag = 0;
    while (str[i]) {
        switch (str[i]) {
            case '(' : {
                i++;
                n = n + m + 1;
                build(s, str, n);
                n--;
                flag = 0;
            } break;
            case ')' : {
                return ;
            } break;
            case ',' : {
                flag = 1;
            } break;
            default : {
                s->len++;
                if (flag) s->data[2 * n + 1] = str[i], m = 1;
                else s->data[2 * n] = str[i], m = 0;
            } break;
        }
        i++;
    }
    return ;
}

void output(Node *s) {
    if (s->len == 0) return ;
    for (int j = 1; j < SIZE; j++) {
        if (j != 1 && s->data[j] != 0) printf(" ");
        if (s->data[j] != 0)printf("%c", s->data[j]);
    }
    printf("\n");
    return ;
}

void clear(Node *s) {
    free(s->data);
    free(s);
    return ;
}

int main() {
    char str[SIZE];
    scanf("%s", str);
    if (strlen(str) == 0) {
        printf("\n");
        return 0;
    }
    Node *s = init();
    s->data[1] = str[0];
    s->len++;
    build(s, str, 0);
    output(s);
    clear(s);
    return 0;
}
