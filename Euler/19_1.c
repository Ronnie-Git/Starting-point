/*************************************************************************
	> File Name: 19_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 12时32分33秒
 ************************************************************************/

#include <stdio.h>

int day(int d, int m, int y) {
    int ans = 0;
    if (m == 1 || m == 2) {
        y -= 1;
        m += 12;
    }
    ans = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7; // 公式
    return ans + 1;
}

int main() {
    int ans = 0;
    for (int i = 1901; i < 2001; i++) {
        for (int j = 1; j < 13; j++) {
            if (day(1, j, i) == 7) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
