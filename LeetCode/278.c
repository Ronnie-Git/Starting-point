/*************************************************************************
	> File Name: 278.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月08日 星期四 20时20分13秒
 ************************************************************************/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int l = 1, r = n, mid;
    while (l < r) {
        mid = (r - l) / 2 + l;
        if (isBadVersion(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
