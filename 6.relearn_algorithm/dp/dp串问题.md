## 最长上升子序列（LIS）

### 简介

简称LIS，就是给你一个序列，请你在其中求出一段不断严格上升的部分，它不一定要连续。也有些情况求的是最长非降序子序列，二者区别就是序列中是否可以有相等的数



### 例题 NOI_1759:最长上升子序列

#### 解题思路

dp(i) 就是找以 arr[i] 结尾的，在 arr[i] 之前的最长上升子序列 + 1，当 arr[i] 之前没有比 arr[i] 更小的数时，dp(i) = 1。所有的 d(i) 里面最大的那个就是最长上升子序列。

就是每次都向前找比它小的数和比它大的数的位置，将第一个比它大的替换掉，这样操作虽然LIS序列的具体数字可能会变，但是很明显LIS长度还是不变的，因为只是把数替换掉了，并没有改变增加或者减少长度。

#### 代码 O(n^2^)

```c++
#include <iostream>
#include <cstdio>

using namespace std;

int arr[1005] = {0}, dp[1005] = {0};

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
```



#### 代码 O(nlogn)

通过二分查找优化

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_SIZE 1005

int dp[MAX_SIZE] = {0}; // 存以 arr[i] 为结尾的最长上升子序列的长度 
int arr[MAX_SIZE] = {0};
int len[MAX_SIZE] = {0}; // len[i] 存长度为 i 的最长上升子序列以谁为结尾 

void init() {
    memset(len, 0x3f, sizeof(len));
    dp[0] = 1;
    len[1] = arr[0];
    len[0] = -1;
    return ;
}

// 找到以 arr[i] 为结尾最长上升子序列的长度
int find(int *num, int n, int key) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (num[mid] >= key) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    int n, ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    init();
    for (int i = 1; i < n; i++) {
        dp[i] = find(len, ans + 1, arr[i]);
        len[dp[i]] = arr[i];
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
```



### 最长上升子序列（模板）

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_N 1010
int arr[MAX_N] = {0};
int dp[MAX_N] = {0};

void init_dp() {
    memset(dp, -1, sizeof(dp)); // 注意初始化的值
    dp[1] = arr[0];
    return ;
}

int serach(int *num, int n, int key) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (num[mid] >= key) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    int n, ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    init_dp();
    for (int i = 1; i < n; i++) {
        if (arr[i] > dp[ans]) dp[++ans] = arr[i]; // 求最长不下降子序列时 arr[i] >= dp[ans];
        else {
            dp[serach(dp, ans + 1, arr[i])] = arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}
```



### 最长下降子序列（模板）

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_N 1010
int arr[MAX_N] = {0};
int dp[MAX_N] = {0};

void init_dp() {
    memset(dp, 0x3f, sizeof(dp)); // 注意初始化的值
    dp[1] = arr[0];
    return ;
}

int serach(int *num, int n, int key) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (num[mid] <= key) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    int n, ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    init_dp();
    for (int i = 1; i < n; i++) {
        if (arr[i] < dp[ans]) dp[++ans] = arr[i]; // 求最长不上升子序列时 arr[i] <= dp[ans];
        else {
            dp[serach(dp, ans + 1, arr[i])] = arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}
```



## 最长公共子序列（LCS）

### 求解思想

假设`X=<x1,x2,⋯,xm>`, `Y=<y1,y2,⋯,yn>`,`Z=<z1,z2,⋯,zk>`是X与Y的LCS

* 如果Xm=Yn，则Zk=Xm=Yn，有Zk−1是Xm−1与Yn−1的LCS
* 如果Xm≠Yn，则Zk是Xm与Yn−1的LCS，或者是Xm−1与Yn的LCS

因此，求解LCS的问题则变成递归求解的两个子问题。

![1](/home/x/7.比赛/3.DP/1.code/images/1.jpg)

### 举例

设所给的两个序列为`X=<A，B，C，B，D，A，B>`和`Y=<B，D，C，A，B，A>`

![2](/home/x/7.比赛/3.DP/1.code/images/2.jpg)



### 最长公共子序列（模板）

```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
char a[MAX_N] = {0}, b[MAX_N] = {0};
int dp[MAX_N][MAX_N] = {0};

int main() {
    cin >> a >> b;
    int lena = strlen(a), lenb = strlen(b);
    for (int i = 1; i <= lena; i++) {
    	for (int j = 1; j <= lenb; j++) {
        	if (a[i - 1] == b[j - 1]) {
            	dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
            	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
       	}
    }
   	cout << dp[lena][lenb] << endl;
    return 0;
}
```



### 最长公共子序列（滚动数组模板）

```c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define SIZE 10010
#define swap(a, b) { a ^= b; b ^= a; a ^= b; }

int dp[2][SIZE] = {0};
char a[SIZE] = {0}, b[SIZE] = {0};

int main() {
    int now = 1, pre = 0;
    cin >> a >> b;
    int lena = strlen(a), lenb = strlen(b);
    for (int i = 0; i < lena; i++) {
        swap(now, pre);
        for (j = 0; j < lenb; j++) {
        	if (a[i] == b[j]) {
            	dp[now][j + 1] = dp[pre][j] + 1;
            } else {
            	dp[now][j + 1] = max(dp[pre][j + 1], dp[now][j]);
            }
        }
    }
    cout << dp[now][lenb] << endl;
    return 0;
}
```



## 最长公共子串

**子串是一种特殊的子序列**



### 动态转移方程

![3](/home/x/7.比赛/3.DP/1.code/images/3.jpg)



### 最长公共子串（模板）

```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
char a[MAX_N] = {0}, b[MAX_N] = {0};
int dp[MAX_N][MAX_N] = {0};

int main() {
    cin >> a >> b;
    int lena = strlen(a), lenb = strlen(b), ans = 0;
    for (int i = 1; i <= lena; i++) {
    	for (int j = 1; j <= lenb; j++) {
        	if (a[i - 1] == b[j - 1]) {
            	dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
            	dp[i][j] = 0;
            }
            ans = (dp[i][j], ans);
       	}
    }
   	cout << ans << endl;
    return 0;
}
```



## 练习题

### P1020 导弹拦截

#### 所学知识

最长上升序列

#### 问题解析

- 计算这套系统最多能拦截多少导弹?
  - 直接使用模板跑出最长不上升子序列长度
- 拦截所有导弹最少要配备多少套这种导弹拦截系统？
  - 通过Dilworth定理可以知道**最少的下降序列个数就等于整个序列最长上升子序列的长度**
  - 使用模板跑出最长上升子序列长度

#### 代码

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 100010
int len[MAX_N] = {0};
int arr[MAX_N] = {0};

void init(int x) {
    memset(len, x, sizeof(len));
    len[1] = arr[0];
    return ;
}

bool check(int flag, int x, int y) {
    return (flag ? x >= y : x < y);
}

int find(int *num, int n, int key, int flag) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(flag, num[mid], key)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    int n = 0, ans = 1, sum = 1;
    while (scanf("%d", &arr[n]) != EOF) ++n;
    init(0x3f);
    for (int i = 1; i < n; i++) {
        if (len[ans] >= arr[i]) len[++ans] = arr[i];
        else {
            len[find(len, ans + 1, arr[i], 0)] = arr[i];
        }
    }
    init(-1);
    for (int i = 1; i < n; i++) {
        if (len[sum] < arr[i]) len[++sum] = arr[i];
        else {
            len[find(len, sum + 1, arr[i], 1)] = arr[i];
        }
    }
    cout << ans << endl << sum << endl;
    return 0;
}
```