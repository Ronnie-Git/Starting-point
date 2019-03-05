### HDU1203

http://acm.hdu.edu.cn/showproblem.php?pid=1203

#### 题目大意

一共有n万美元，有m个学校，他要在m个学校中选择若干学校投递申请，每个学校有各自的申请费用和得到这个学校offer的概率，求他至少可以收到一个offer的概率

#### 所学知识

01背包

#### 题目讲解

要求至少可以收到一个offer的概率，可以先求收不到offer的最小概率，再用1减去其概率即可

**动态转移方程**

v该学校的费用 p得不到该学校offer的概率

`dp[i] = min(dp[i], dp[i] - v) * p`

#### 代码实现

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 10010;
double dp[MAX_N] = {0};
int v[MAX_N] = {0};
double w[MAX_N] = {0};

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
        for (int i = 0; i <= n; i++) dp[i] = 1;
        for (int i = 0; i < m; i++) {
            cin >> v[i] >> w[i];
            w[i] = 1 - w[i];
        }
        for (int i = 0; i < m; i++) {
            for (int j = n; j >= v[i]; j--) {
                dp[j] = min(dp[j], dp[j - v[i]] * w[i]);
            }
        }
        printf("%.1lf%%\n", (1.0 - dp[n]) * 100.0);
    }
    return 0;
}
```



### HDU1284

http://acm.hdu.edu.cn/showproblem.php?pid=1284

#### 题目大意

在一个国家仅有1分，2分，3分硬币，将钱N兑换成硬币有多少种兑法

#### 所学知识

完全背包

#### 题目讲解

`dp[0] = 1`

#### 代码实现

```c++
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 40000;

int dp[MAX_N] = {0};

void init() {
    int num[5] = {1, 2, 3};
    dp[0] = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = num[i]; j < MAX_N; j++) {
            dp[j] += dp[j - num[i]];
        }
    }
    return ;
}

int main() {
    init();
    int n;
    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}
```



### HDU2159

#### 题目链接

http://acm.hdu.edu.cn/showproblem.php?pid=2159

#### 所学知识

完全背包

#### 题目讲解

* 以忍耐度为背包，经验为dp值，在dp时记录杀怪的次数

* 再扫一边背包，看是否有经验值达到要求的

#### 代码实现

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 110;
const int INF = 0x3f3f3f3f;
int dp[MAX_N] = {0}, cnt[MAX_N] = {0};

int main() {
    int n, m, k, s, a, b;
    while (cin >> n >> m >> k >> s) {
        memset(dp, -INF - 1, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        dp[0] = 0;
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            for (int j = b; j <= m; j++) {
                if (cnt[j - cnt[b]] + 1 > s) break;
                if (dp[j] < dp[j - b] + a) {
                    dp[j] = dp[j - b] + a;
                    cnt[j] = cnt[j - b] + 1;
                }
            }
        }
        int ind = 1;
        while (dp[ind] < n && ind <= m) ++ind;
        printf("%d\n", ind > m ? -1 : m - ind);
    }
    return 0;
}
```

