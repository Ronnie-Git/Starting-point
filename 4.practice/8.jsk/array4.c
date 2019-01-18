/*************************************************************************
	> File Name: array4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月18日 星期三 15时54分38秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int index = 0;
    int start = 1;
    int mod = 1;
    scanf("%d%d", &start, &mod);
    for (index = start; index < 5; index++) {
        if (arr[index] % mod == 0) {
            continue;
            printf("%d ", arr[index] + 1);
            if (arr[index] % (mod + 1) == 0) {
                break;
            }
        } else {
            printf("%d ", arr[index]);
        }
    }

    return 0;
}
