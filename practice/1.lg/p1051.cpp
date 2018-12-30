/*************************************************************************
	> File Name: p1051.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月28日 星期五 18时01分55秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct stu {
    int num, score;
    char str[25];
} stu;

bool cmp(stu x, stu y) {
    if (x.score == y.score) {
        return x.num < y.num;
    }
    return x.score > y.score;
}

int main() {
    int n, score1, score2, essay;
    char cadre, west;
    stu arr[105];
    cin >> n;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        cin >> arr[i].str;
        cin >> score1 >> score2;
        cin  >> cadre  >> west >> essay;
        arr[i].num = i + 1;
        if (score1 > 80 && essay >= 1) sum += 8000;
        if (score1 > 85 && score2 > 80) sum += 4000;
        if (score1 > 90) sum += 2000;
        if (score1 > 85 && west == 'Y') sum += 1000;
        if (score2 > 80 && cadre == 'Y') sum += 850;
        arr[i].score = sum;
    }
    sort(arr, arr + n, cmp);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += arr[i].score;
    }
    cout << arr[0].str << endl;
    cout << arr[0].score << endl;
    cout << ans << endl;
    return 0;
}
