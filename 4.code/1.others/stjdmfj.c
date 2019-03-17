/*************************************************************************
	> File Name: stack.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月21日 星期日 19时15分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
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

int push(Stack *s, int value) {
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
    for (int i = s->top; i >= 0; i--) {
        printf(" %d", s->data[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int n, num, f = 1, x = 1;
    scanf("%d", &n);
    Stack *s = init(n + 5);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (!f) continue;
        while (x <= num) {
            push(s, x);
            x++;
        }
        while (!empty(s) && top(s) != num) {
            pop(s);
        }
        if (top(s) == num) {
            pop(s);
        } else {
            f = 0;
            printf("NO\n");
        }
    }
    f && printf("YES\n");
    clear(s);
    return 0;
}
