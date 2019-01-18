/*************************************************************************
	> File Name: 225.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月22日 星期一 18时42分12秒
 ************************************************************************/

typedef struct {
    int *data;
    int h, t, len;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->data = (int *)malloc(sizeof(int) * maxSize);
    s->h = 0;
    s->t = -1;
    s->len = maxSize;
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->t++;
    obj->data[obj->t] = x;
    return ;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    MyStack *s = myStackCreate(obj->len);
    while (obj->h < obj->t) {
        myStackPush(s, obj->data[obj->h]);
        obj->h++;
    }
    int ans = obj->data[obj->h];
    obj->h = 0, obj->t = -1;
    while (s->h <= s->t) {
        myStackPush(obj, s->data[s->h]);
        s->h++;
    }
    free(s->data);
    free(s);
    return ans;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    MyStack *s = myStackCreate(obj->len);
    while (obj->h < obj->t) {
        myStackPush(s, obj->data[obj->h]);
        obj->h++;
    }
    int ans = obj->data[obj->h];
    myStackPush(s, ans);
    obj->h = 0, obj->t = -1;
    while (s->h <= s->t) {
        myStackPush(obj, s->data[s->h]);
        s->h++;
    }
    free(s->data);
    free(s);
    return ans;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->h > obj->t) return true;
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
    return ;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */
