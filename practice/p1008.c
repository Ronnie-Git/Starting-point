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
