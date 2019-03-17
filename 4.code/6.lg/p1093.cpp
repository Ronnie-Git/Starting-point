/*************************************************************************
	> File Name: p1093.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月26日 星期三 17时10分29秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct student{
    int num;
    int sum;
    int chinese;
} student;

bool cmp (student x, student y){
    if (x.sum == y.sum && x.chinese == y.chinese) {
        return x.num < y.num;
    } else if (x.sum == y.sum) {
        return x.chinese > y.chinese;
    } else {
        return x.sum > y.sum;
    }
}

int main() {
    int n;
    student stu[305];
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        stu[i].num = i + 1;
        stu[i].sum = a + b + c;
        stu[i].chinese = a;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < 5; i++) {
        cout << stu[i].num << " " << stu[i].sum << endl;
    }
    return 0;
}
