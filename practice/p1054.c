/*************************************************************************
	> File Name: p1054.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月23日 星期二 18时15分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 0x3f3f3f3f
#define N 100000007

typedef long long LL;

LL p(LL a, LL b) {
    LL ret = 1;
    for (LL i = 0; i < b; i++) {
        ret = ret * a % N;
    }
    return ret % N;
}

int calc(const char *str, int l, int r, int a_value) {
    int pos = -1, temp_prior = 0, prior = INF - 1;
    for (int i = l; i <= r; i++) {
        int cur_prior = INF;
        switch (str[i]) {
            case '(' : temp_prior += 4; break;
            case ')' : temp_prior -= 4; break;
            case '+' : cur_prior = temp_prior + 1; break;
            case '-' : cur_prior = temp_prior + 1; break;
            case '*' : cur_prior = temp_prior + 2; break;
            case '/' : cur_prior = temp_prior + 2; break;
            case '^' : cur_prior = temp_prior + 3; break;
        }
        if (cur_prior <= prior) {
            prior = cur_prior;
            pos = i;
        }
    }
    if (pos == -1) {
        LL num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] == 'a') return a_value;
            if (str[i] < '0' || str[i] > '9') continue;
            num = (num * 10 + str[i] - '0') % N;
        }
        return num;
    } else {
        LL a = calc(str, l, pos - 1, a_value); 
        LL b = calc(str, pos + 1, r, a_value);
        switch (str[pos]) {
            case '+' : return (a + b) % N;
            case '-' : return (a - b) % N;
            case '*' : return a * b % N;
            case '/' : return a / b % N;
            case '^' : return p(a, b) % N;
        }
    }
    return 0;
}

int main() {
    char str[100000] = {0};
    int n;
    scanf("%[^\n]s", str);
    getchar();
    scanf("%d", &n);
    getchar();
    LL k = calc(str, 0, strlen(str) - 1, 3);
    for (int i = 0; i < n; i++) {
        getchar();
        memset(str, '\0', sizeof(str));
        scanf("%[^\n]s", str);
        if (k == calc(str, 0, strlen(str) - 1, 3)) {
            printf("%c", 'A' + i);
        }
    }
    return 0;
}
