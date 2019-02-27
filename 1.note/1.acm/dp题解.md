### 例题  开心的金明

#### 题目链接

https://nanti.jisuanke.com/t/284

#### 所用知识

01背包

#### 题目讲解

* 将价格和重要度的乘积作为价值
* 带入01背包模板

#### 代码实现

```c++
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// 复习一下结构体的使用方式
typedef struct arr {
    int w, data;
} arr;

int main() {
    int n, m, dp[30005] = {0}; // 没有要求将背包恰好装满 初始化为零即可
    arr num[30005];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> num[i].w >> num[i].data;
        num[i].data *= num[i].w; // 将价格和重要度的乘积作为价值
    }
    
    // 01背包模板
    for (int i = 0; i < m; i++) {
        for (int j = n; j >= num[i].w; j--) {
            dp[j] = max(dp[j], dp[j - num[i].w] + num[i].data);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
```



### 例题  P1616 疯狂的采药

#### 题目链接

https://www.luogu.org/problemnew/show/P1616

#### 所用知识

完全背包

#### 题目讲解

直接套模板

#### 代码实现

```c++
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int T, M, dp[100005], t[100005], w[100005];
int main() {
    cin >> T >> M;
    for (int i = 0; i < M; ++i) cin >> t[i] >> w[i];
    for (int i = 0; i < M; ++i) {
        for (int j = t[i]; j <= T; ++j) { // 因为无限次 无论dp[j-c[i]]选没选过c[i]都可以 
             dp[j] = max(dp[j], dp[j - t[i]] +  w[i]);
        }
    }
    cout << dp[T] << endl;
    return 0;
}
```



### 例题 金明的预算方案

#### 题目链接

https://nanti.jisuanke.com/t/11589

#### 所用知识

有依赖的背包问题、01背包

#### 题目讲解

一个物品最多有两个附件，不买主件便不能买附件，即可以采用分组思想，可分为五种情况：

1. 不买主件也不买其附件
2. 只买主件
3. 买主件和附件A
4. 买主件和附件B
5. 买主件和附件A和附件B

最后再使用01背包求解即可。

#### 代码实现

```c++
#include <iostream>
#include <cstdio>

using namespace std;

// cnt记录该主件和附件共有几种组合
typedef struct data {
    int cnt;
    int c[4];
    int w[4];
} data;

int main() {
    data num[70];
    for (int i = 0; i < 70; i++) num[i].cnt = 0;
    int dp[32005] = {0};
    int n, m, a, b, c, ind = 0;
    cin >> n >> m;
    // 将主件和附件的几种组合情况分别储存
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (c == 0) {
            num[i].cnt = 1;
            num[i].c[0] = a;
            num[i].w[0] = a * b;
            continue;
        }
        int temp = num[c-1].cnt;
        num[c-1].c[temp] = num[c-1].c[0] + a;
        num[c-1].w[temp] = num[c-1].w[0] + a * b;
        num[c-1].cnt++;
        temp++;
        if (temp == 3) { // temp等于3代表有一个主件两个配件，把最后一种情况存入分组
            num[c-1].c[temp] = num[c-1].c[1] + a;
            num[c-1].w[temp] = num[c-1].w[1] + a * b;
            num[c-1].cnt++;
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (num[i].cnt == 0) continue;
        for (int l = n; l >= 0; l--) {
            for (int j = 0; j <= num[i].cnt - 1; j++) {
                if (l - num[i].c[j] < 0) continue;
                dp[l] = max(dp[l], dp[l - num[i].c[j]] + num[i].w[j]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
```



### 例题 P1164 小A点菜

#### 题目链接

https://www.luogu.org/problemnew/show/P1164

#### 所学知识

01背包变型

#### 题目讲解

只需将`dp[0] = 1 其他位置为0`，之后按01背包处理

#### 代码实现

```c++
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    int num[105] = {0}, dp[10005] = {0};
    dp[0] = 1; // 剩余的钱买完一道菜后刚好用完 所以剩余的这些钱只有一种买法
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= num[i]; j--) {
            dp[j] += dp[j - num[i]]; // 现在的花费（方法数） += 不点这个菜的时候的花费（方法数）
        }
    }
    cout << dp[m] << endl;
    return 0;
}
```



### 例题 HDU3506

#### 题目链接

http://acm.hdu.edu.cn/showproblem.php?pid=3506

#### 所学知识

区间dp、四边形优化

#### 题目讲解

将前n-1依次个移到第n个后面，将环变成线。

定义状态`dp[i,j]`表示将区间`[i,j]`的石子合并所需的最小代价，则状态转移方程为

`dp[i, j] = min(dp[i, k] + dp[k + 1,j] + sum[i, j])`

利用四边形不等式优化，限制`k[i,j]`的取值范围在`k[i, j-1] ~ k[i+1,j]`之间

#### 代码实现

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 2010;
const int INF = 0x3f3f3f3f;

int dp[MAX_N][MAX_N] = {0};
int sum[MAX_N] = {0};
int w[MAX_N] = {0};
int num[MAX_N][MAX_N] = {0};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        sum[0] = 0;
        memset(dp, INF, sizeof(dp));
        for (int i = 1; i <= n * 2; i++) {
            if (i <= n) cin >> w[i];
            else w[i] = w[i - n];
            sum[i] = sum[i - 1] + w[i];
            dp[i][i] = 0;
            num[i][i] = i;
        }
        for (int len = 2; len <= n; len++) {
            for (int j = 1; j + len <= n * 2; j++) {
                int ends = j + len - 1;
                for (int i = num[j][ends - 1]; i <= num[j + 1][ends]; i++) {
                    int temp = dp[j][i] + dp[i + 1][ends] + sum[ends] - sum[j - 1];
                    if (dp[j][ends] > temp) {
                        dp[j][ends] = temp;
                        num[j][ends] = i;
                    }
                }
            }
        }
    
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[i][i + n - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}
```



### 例题 HDU2089

#### 题目链接

http://acm.hdu.edu.cn/showproblem.php?pid=2089

#### 所用知识

数位dp、枚举

#### 题目讲解

数位上不能有4也不能有连续的62，没有4的话在枚举的时候判断一下，不枚举4就可以保证状态合法了，所以这个约束没有记忆化的必要。

对于62，涉及到两位，当前一位是6或者不是6这两种不同情况计数是不相同的，所以要用状态来记录不同的方案数。

`dp[pos][sta]`表示当前第pos位，前一位是否是6的状态，这里sta只需要去0和1两种状态就可以了，不是6的情况可视为同种，不会影响计数。

#### 代码实现

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
int a[20] = {0};
int dp[20][2] = {0};
int dfs(int pos, int pre, int sta, bool limit) {
    if (pos == -1) return 1;
    if (!limit && dp[pos][sta] != -1) return dp[pos][sta];
    int up = (limit ? a[pos] : 9);
    int tmp = 0;
    for (int i = 0; i <= up; i++) {
        if (pre == 6 && i == 2) continue;
        if (i == 4) continue;//都是保证枚举合法性
        tmp += dfs(pos - 1, i, i == 6, limit && i == a[pos]);
    }
    if (!limit) dp[pos][sta] = tmp;
    return tmp;
}
int solve(int x) {
    int pos = 0;
    while (x) {
        a[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, -1, 0, true);
}

int main() {
    int le, ri;
    //memset(dp,-1,sizeof dp);可优化
    while(scanf("%d%d", &le, &ri) != EOF && le + ri) {
        memset(dp,-1,sizeof dp);
        printf("%d\n",solve(ri) - solve(le - 1));
    }
    return 0;
}

```



### 例题 HDU1520

#### 题目链接

http://acm.hdu.edu.cn/showproblem.php?pid=1520

#### 所用知识

树状dp、vector

#### 题目讲解

树形dp的常规入门题：设`dp[i][0]`表示:当前这个点不选，`dp[i][1]`表示当前这个点选择的最优解。

**转移方程**

`dp[cur][0]+=max(dp[son][1],dp[son][0]);`

当前这个点不选，那他的孩子可选可不选，取最大的。 

`dp[cur][1]+=dp[son][0]`

当前这点选择，那他的孩子就不能选择。

#### 代码实现

```c++
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

#define N 6010

int num[N] = {0}, dp[N][2] = {0}, f[N] = {0},n;
vector<int> E[N]; // 存节点的子节点

void dfs(int cur) {
    dp[cur][1] = num[cur];
    for (int i = 0; i < E[cur].size(); i++) {
        int son = E[cur][i];
        dfs(son);
        dp[cur][0] += max(dp[son][1], dp[son][0]);
        dp[cur][1] += dp[son][0];
    }
    return ;
}

int main(){
    while(scanf("%d", &n) != EOF){
        for (int i = 1; i <= n; i++){
            cin >> num[i];
            E[i].clear();
            dp[i][0] = dp[i][1] = 0;
            f[i] = -1;
        }
        int a, b;
        while (scanf("%d%d", &a, &b) != EOF) {
            if (a == 0 && b == 0) break;
            E[b].push_back(a);
            f[a]=b;
        }
        int root = 1;
        while (f[root] != -1) root = f[root]; // 找根节点
        dfs(root);
        cout << max(dp[root][1], dp[root][0]) << endl;
    }
    return 0;
}
```



### 例题 HDU1992

#### 题目链接

http://acm.hdu.edu.cn/showproblem.php?pid=1992

#### 所用知识

状压dp、位运算

#### 题目讲解

算成n行的砖，每行有四。然后用4个01位表示一行，如果是0表示这一行不会占用下一行的地方，如果是1表示会占用下一行的砖。

状态转移有三种：

1. 当前行当前位为1，那么直接转移到下一位
2. 当前行当前位为0，那么可以表示下一行可以为1
3. 当前行当前位和下一位为00，那么下一行也可以为00

#### 代码实现

```c++
#include <iostream>

using namespace std;
 
int dp[1005][16] = {0};
 
void dfs(int r, int c, int cur, int next) {
//分别表示当前行，当前列,当前状态，可转移的状态
    if (c > 3) {
        dp[r + 1][next] += dp[r][cur];
        return;
    }
    if (!(cur & (1 << c))) {
        dfs(r, c + 1, cur, next | (1 << c));   //竖着放，用1
        if (c <= 2 && !(cur & (1 << (c + 1)))) {
            dfs(r, c + 2, cur, next);  //也可以横着放，两个0
        }
    } else {
        dfs(r, c + 1, cur, next);   //位置被上面的占了
    }
    return ;
}

void init() {
    dp[0][0] = 1;
    for (int i = 0; i < 22; i++) {   //22已经爆int32了
        for(int j = 0; j < 16; j++) {
            if (dp[i][j]) dfs(i, 0, j, 0);
        }
    }
    return ;
}
 
int main() {
    init();
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cout << i << " " << dp[x][0] << endl;
    }
    return 0;
}
```



### 例题 HDU3853

#### 题目大意

- 有一个迷宫r行m列，开始点在[1,1]，现在要走到[r,c]
- 对于在点[x,y]可以打开一扇门走到[x+1,y]或者[x,y+1]
- 消耗2点魔力
- 问平均消耗多少魔力能走到[r,c]

#### 所学知识

概率dp

#### 题目讲解

假设`dp[i][j]`表示在点`[i,j]`到达`[r,c]`所需要消耗的平均魔力(期望)，则`从dp[i][j]`可以到达:
`dp[i][j],dp[i+1,j],dp[i][j+1];`

**对应概率分别为**
`p1,p2,p3`
由`E(aA+bB+cC...)=aEA+bEB+cEC+...`包含状态A,B,C的期望可以分解子期望求解 
得到`dp[i][j]=p1*dp[i][j]+p2*dp[i+1][j]+p3*dp[i][j+1]+2;`

#### 代码实现

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
 
const int MAX_N = 1010;
double dp[MAX_N][MAX_N] = {0}, p[MAX_N][MAX_N][3] = {0};
 
int main(){
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(dp, 0, sizeof(dp));
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%lf %lf %lf", &p[i][j][0], &p[i][j][1], &p[i][j][2]);
            }
        }
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                if (i == n && j == m) continue;
                if (fabs(p[i][j][0] - 1.0) < 1e-8) continue; //该点无路可走,期望值肯定为0(dp[i][j]=0)
                dp[i][j] = (p[i][j][1] * dp[i][j + 1] + p[i][j][2] * dp[i + 1][j] + 2.00) / (1.00 - p[i][j][0]);
            }
        }
        printf("%.3lf\n", dp[1][1]);
    }
    return 0;
} 
```

