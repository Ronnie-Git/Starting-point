/*************************************************************************
	> File Name: 232.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月22日 星期一 18时21分15秒
 ************************************************************************/

typedef struct {
    int *data;
    int top, size;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * maxSize);
    q->top = -1;
    q->size = maxSize;
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->top++;
    obj->data[obj->top] = x;
    return ;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    MyQueue *q = myQueueCreate(obj->size);
    while (obj->top > -1) {
        myQueuePush(q, obj->data[obj->top]);
        obj->top--;
    }
    int ans = q->data[q->top];
    q->top--;
    while (q->top > -1) {
        myQueuePush(obj, q->data[q->top]);
        q->top--;
    }
    free(q->data);
    free(q);
    return ans;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    MyQueue *q = myQueueCreate(obj->size);
    while (obj->top > -1) {
        myQueuePush(q, obj->data[obj->top]);
        obj->top--;
    }
    int ans = q->data[q->top];
    while (q->top > -1) {
        myQueuePush(obj, q->data[q->top]);
        q->top--;
    }
    free(q->data);
    free(q);
    return ans;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if (obj->top == -1) return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
