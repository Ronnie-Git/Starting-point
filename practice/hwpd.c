/*************************************************************************
	> File Name: stack.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月21日 星期日 19时15分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (char *)malloc(sizeof(char) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

int push(Stack *s, char value) {
    if (s->top + 1 == s->size) return 0;
    s->top += 1;
    s->data[s->top] = value;
    return 1;
}

void pop(Stack *s) {
    if (empty(s)) return ;
    s->top -= 1;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

void output(Stack *s) {
    printf("Stack = [");
    for (int i = s->top; i >= 0; i--) {
        printf(" %d", s->data[i]);
        i && printf(",");
    }
    printf("]\n");
    return ;
}

int main() {
    char str[100] = {0};
    int f = 1;
    Stack *s = init(50);
    scanf("%s", str);
    for (int i = 0; str[i] != '@'; i++) {
        push(s, str[i]);
    }
    for (int i = 0; i < strlen(str) - 1; i++) {
        if (str[i] != top(s)) {
            f = 0;
            printf("false\n");
            break;
        }
        pop(s);
    }
    f && printf("true\n");
    clear(s);
    return 0;
}
