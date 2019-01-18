/*************************************************************************
	> File Name: p1008.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月23日 星期五 20时33分57秒
 ************************************************************************/

#include <stdio.h>

int main() {
	for (int i = 123; i < 333; i++) {
		int num[10] = {0}, x, y = i, n = 1;
		while (n < 4) {
			x = y % 10;
			if (!x || num[x]) break;
			num[x] = 1;
			y = (y / 10 == 0 ? ++n * i : y / 10);
		}
		if (n == 4) printf("%d %d %d\n", i, i * 2, i * 3);
	}
	return 0;

}
