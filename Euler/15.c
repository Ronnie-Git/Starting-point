/*************************************************************************
	> File Name: 15.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 11时42分36秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main() {
    int64_t ans = 1, n = 21, m = 1;
    while (n <= 40 || m <= 20) { // C40(20) 边乘边除
        if (ans % m == 0) ans /= m++;
        if (n <= 40) ans *= n++;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
