/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月09日 星期日 12时48分28秒
 ************************************************************************/

#include <stdio.h>

typedef struct Node {
    int l, r;
} Node;

Node num[100010];

int main() {
    int n, m, x, k, head = 1;
    scanf("%d", &n);
    num[1].l = 0, num[1].r = 0;
    num[0].l = 0, num[0].r = 0;
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &x, &k);
        if (k) {
            int temp = num[x].r;
            num[temp].l = i;
            num[x].r = i;
            num[i].l = x;
            num[i].r = temp;
        } else {
            if (head == x) head = i;
            int temp = num[x].l;
            num[temp].r = i;
            num[x].l = i;
            num[i].r = x;
            num[i].l = temp;
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (num[x].l == -1 && num[x].r == -1) continue;
        if (head == x) head = num[x].r;
        int temp_l = num[x].l, temp_r = num[x].r;
        num[temp_l].r = temp_r;
        num[temp_r].l = temp_l;
        num[x].l = -1, num[x].r = -1;
    }
    int p = head;
    for (int i = 0; p; i++) {
        i && printf(" ");
        printf("%d", p);
        p = num[p].r;
    }
    printf("\n");
    return 0;
}
