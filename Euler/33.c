#include <stdio.h>

int num[5][2] = {0};
int k = 1;

int gcd (int a, int b) {//计算最大公因数
    return (b ? gcd(b, a % b) : a);
}

int solve (int i, int j) {
	for (int l = 1; l < 10; l++) {
		int a = i * 10 + l, b = l * 10 + j;
        if (a >= b) continue;
        if (a * j == b * i) {
            num[k][0] = a, num[k][1] = b;
            k++;
        }
    }
    return 0;
}

int main() {
    int k = 0;
    for (int i = 1; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            solve(i, j);// i 分子 j 分母
        }
    }
    int x = 1, y = 1, ans = 0;
    for (int i = 1; i < 5; ++i) {
        x *= num[i][0];
        y *= num[i][1];
        printf("%d %d\n", num[i][0], num[i][1]);
    }
    ans = y / gcd(y, x);
    printf("%d\n", ans);
    return 0;
}
