/*************************************************************************
	> File Name: search.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月16日 星期日 20时35分49秒
 ************************************************************************/

#ifndef _SEARCH_H
#define _SEARCH_H

int search(int *num, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (num[i] == value) return i + 1;
    }
    return -1;
}

void clear_arr(int *num) {
    free(num);
    return ;
}
#endif
