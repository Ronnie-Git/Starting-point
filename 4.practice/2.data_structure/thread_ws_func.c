/*************************************************************************
	> File Name: thread_ws_func.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月04日 星期二 18时38分50秒
 ************************************************************************/

void cond_var_wait(struct cond_var *condition, struct spinlock *lock) {
    TCB *curr = current_thread();
    struct list_elem *new_waiter = calloc(1, sizeof(struct list_elem));
    new_waiter->thread = curr;
    new_waiter->next = NULL;
    struct list_element *temp = condition->waiters;
    if (!temp) {
        condition->waiters = new_waiter;
    } else {
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_waiter;
    }
    disable_interrupt();
    spinlock_unlock(lock);
    thread_block(curr);
    spinlock_acquire(lock);
    enable_interrupt();
}

void cond_var_signal(struct cond_var *condition) {
    if (!condition->waiters) return ;
    struct list_element *head = condition->waiters;
    condition->waiters = head->next;
    thread_unblock(head->TCB);
    free(head);
}
