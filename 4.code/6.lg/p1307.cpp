/*************************************************************************
	> File Name: p1307.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月31日 星期五 17时23分22秒
 ************************************************************************/

#include <stdio.h>
int main() {
	int n, x = 0, a;
	scanf("%d", &n);
	while (n == 0) {
		printf("%d", x);
	}
	while (n != 0) {
		a = n % 10;
		x = a + x * 10;
		n = n / 10;
	}
	printf("%d", x);
	return 0;
}
