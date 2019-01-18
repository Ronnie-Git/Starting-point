/*************************************************************************
	> File Name: p1067.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月28日 星期五 17时12分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = n; i >= 0; i--) {
        scanf("%d", &m);
        if (m == 0) continue;
        (i != n || m < 0) && printf("%c", m > 0 ? '+' : '-');
        (abs(m) != 1 || i == 0) && printf("%d", abs(m)); 
        i && (i > 1 ? printf("x^%d", i) : printf("x"));
    }
    printf("\n");
    return 0;
}
