/*************************************************************************
	> File Name: array7.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月18日 星期三 16时14分27秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int n = 1000000;
int mark[1000001];

int main() {
        int c;
        memset(mark, 0, sizeof(mark));
        mark[0] = 1;
        mark[1] = 1;
        int n, m;
        scanf("%d%d", &n, &m);
        for (c = 2; c * c <= n; c++) {
            if (!mark[c]) {
                for (int i = c; c * i <= n; ++i) {
                    mark[c * i] = 1;                
                }
            }
        }
        for (int i = m; i <= n; ++i) {
            if (!mark[i]) {
                printf("%d\n", i);
            }
        }
        return 0;

}
