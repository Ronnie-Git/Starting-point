/*************************************************************************
	> File Name: 20.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月22日 星期一 17时15分59秒
 ************************************************************************/

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

bool isValid(char* s) {
    Stack *a = init(1000000);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(a, s[i]);
        } else {
            if (empty(a)) {
                clear(a);
                return 0;
            }
            switch (s[i]) {
                case ')' : {
                    if (top(a) == '(') {
                        pop(a);
                    } else {
                        clear(a);
                        return 0;
                    }
                    break;
                }
                case ']' : {
                    if (top(a) == '[') {
                        pop(a);
                    } else {
                        clear(a);
                        return 0;
                    }
                    break;
                }
                case '}' : {
                    if (top(a) == '{') {
                        pop(a);
                    } else {
                        clear(a);
                        return 0;
                    }
                }
            }
        }
    }
    if (empty(a)) {
        clear(a);
        return 1;
    }
    clear(a);
    return 0;
}
