/*************************************************************************
	> File Name: 19.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 11时41分39秒
 ************************************************************************/

#include <stdio.h>

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap_year(int y) { // 判断润年
    return (y % 4 == 0 && y % 100) || (y % 400 == 0);
}

int get_next_data(int y, int m, int d) { // 日更新
    d++;
    if (d > days[m] + (m == 2 && leap_year(y))) d = 1;
    return d;
}
int main() {
    int ans = 0, y = 1900, m = 1, d = 1, w = 1;
    do {
        d = get_next_data(y, m, d);
        m += (d == 1); // 月更新
        y += (m == 13 && (m = 1)); // 年更新
        if (++w == 8) w = 1; // 星期更新
        if (y > 1900 && w == 7 && d == 1) ans++;
    } while (y < 2001);
    printf("%d\n", ans);
    return 0;
}
