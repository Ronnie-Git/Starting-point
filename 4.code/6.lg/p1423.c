/*************************************************************************
	> File Name: p1423.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月11日 星期四 17时56分40秒
 ************************************************************************/

#include <stdio.h>
int main() {
	int n;
	float x, s = 2, k = 2;
	scanf("%f", &x);
	for(n = 1; ; n++) {
		if (s >= x) {
			printf("%d", n);
			break;
		}
		k = 0.98 * k;
		s =k + s;
	}
	return 0;
}
