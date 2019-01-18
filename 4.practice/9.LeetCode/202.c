/*************************************************************************
	> File Name: 202.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月14日 星期日 10时56分20秒
 ************************************************************************/

// get_next(1999999999) = 730 所以将次题想象成链表 该链表长度不会超过731
int get_next(int x) {
    int ret = 0;
    while (x) {
        ret += (x % 10) * (x % 10);
        x /= 10;
    }
    return ret;
}

bool isHappy(int n) { 
    int p = n, q = get_next(get_next(n)); // 等同于快慢指针
    while (q != 1) {
        p = get_next(p);
        q = get_next(get_next(q));
        if (p == q) return 0;
    }
    return 1;
}
