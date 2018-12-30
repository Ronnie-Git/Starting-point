/*************************************************************************
	> File Name: tyyx.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月03日 星期一 18时44分51秒
 ************************************************************************/

#include <stdio.h>
int main() {
	int n, i, t;
	scanf("%d", &n);
	int A[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	t = A[0];
	for (i = t; i < n - 1;) {
		i = i + A[i];
		if (A[i] == 0)
			break;
	}
	if (i >= n - 1)
		printf("true");
	else
		printf("false");
}
