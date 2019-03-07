/*************************************************************************
	> File Name: 2.HDU_3068.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月22日 星期五 15时14分14秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAX_N 300010

char str[MAX_N] = {0}, t[MAX_N] = {0};
int p[MAX_N] = {0};

int Manacher() {
    int len = 2, ans = 0;
    t[0] = '$', t[1] = '#';
    for (int i = 0; str[i]; i++) {
        t[len++] = str[i];
        t[len++] = '#';
    }
    int mx = 0, id = 0;
    for (int i = 1; i < len; i++) {
        p[i] = (mx > i ? (min(p[2 * id - i], mx - i)) : 1);
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        ans = max(ans, p[i]);
    }
    return ans - 1;
}

int main() {
    while (scanf("%s", str) != EOF) {
        printf("%d\n", Manacher());
    }
    return 0;
}
