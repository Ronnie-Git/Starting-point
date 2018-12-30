/*************************************************************************
	> File Name: p1022.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月11日 星期四 16时21分03秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char n[1000005] = {0};

int main() {
	char x;
	long long int a = 0, b = 0, c = 0, d = 0, i, t = 1, p = 0;
	scanf("%s", n);
	for (i = 0; n[i] != '='; i++) {
	    if (n[i] == '-') {
	        a += p * t;
	        p = 0;
	        t = -1;
	    }
	    if (n[i] == '+') {
	        a += p * t;
	        p = 0;
	        t = 1;
	    }
	    if (n[i] > 63) {
	        if (!p) b += t;
	        else b += p * t;
	        x = n[i];
	        p = 0;
	    }
	    if (n[i] >= '0' && n[i] <= '9') {
	        p = p * 10 + (n[i] - '0');
	    }
	}
	a += p * t;
	p = 0, t = 1;
	for (i = i; i < strlen(n); i++) {
	    if (n[i] == '-') {
	        c += p * t;
	        p = 0;
	        t = -1;
	    }
	    if (n[i] == '+') {
	        c += p * t;
	        p = 0;
	        t = 1;
	    }
	    if (n[i] > 63) {
	        if(!p) d += t;
	        else d += p * t;
	        p = 0;
	        x = n[i];
	    }
	    if (n[i] >= '0' && n[i] <= '9') {
	        p = p * 10 + (n[i] - '0');
	    }
	}
	c += p * t;
	double ans = 1.0 * (c - a) / (b - d);
	if (!ans) printf("%c=0.000\n", x);
	else printf("%c=%.3lf\n", x, ans);
	return 0;
}
