/*************************************************************************
	> File Name: search_lx4.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月12日 星期一 17时25分29秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b, f = 0, target;
    scanf("%d", &n);
    int *num = (int *)malloc(sizeof(int) * (n + 2));
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    scanf("%d", &target);
    
    for (int i = 0; !f && i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (num[i] + num[j] == target) {
                a = i;
                b = j;
                f = 1;
                break;
            }
        }
    }
    free(num);
    printf("%d %d\n", a + 1, b + 1);
    return 0;
}
