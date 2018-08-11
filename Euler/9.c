/*************************************************************************
	> File Name: 9.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 16时55分31秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int gcd(int m, int n) {
    return (n == 0 ? m : gcd(n, m % n));
}

int main() {
    int n = 0, a, b, c;
    while (n++ < 16) { 
        int m = n;
        while (m++ < 16) { // a, b 一奇一偶 n, m互质 m > n
            if (gcd(m, n) != 1) continue;
            a = 2 * n * m;
            b = m * m - n * n;
            c = m * m + n * n;
            if (1000 % (a + b + c) == 0)
                printf("%d\n", a * b * c * (int)pow(1000 / (a + b + c), 3));
        }
    }
    return 0;
}
