/*************************************************************************
	> File Name: p1424.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月06日 星期六 21时20分46秒
 ************************************************************************/

#include <stdio.h>
int main() {
	int x;
	long int n, s = 0, i;
	scanf("%ld %ld", &x, &n);
	for (i = x; i <= (n - 1 + x); i++) {
		if (i % 7 != 6 && i % 7 != 0) {
			s = s + 250;
		}
	}
	printf("%ld", s);
	return 0;
}
