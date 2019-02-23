[TOC]

## 动态规划 

问题可以分解成若干相互联系的阶段，在每一个阶段都要做出决策，全部过程的决策是一个决策序列。要使整个活动的总体效果达到最优的问题，称为多阶段决策问题。动态规划就是解决多阶段决策最优化问题的一种思想方法。

#### 阶段

将所给问题的过程，按时间或空间特征分解成若干相互联系的阶段，以便按次序去求每阶段的解。

#### 状态

各阶段开始时的客观条件叫做状态。

#### 决策

当各段的状态取定以后，就可以做出不同的决定，从而确定下一阶段的状态，这种决定称为决策。

#### 策略

由开始到终点的全过程中，由每段决策组成的决策序列称为全过程策略，简称策略。

#### 状态转移方程

前一阶段的终点就是后一阶段的起点，前一阶段的决策选择导出了后一阶段的状态，这种关系描述了由k阶段到k+1阶段状态的演变规律，称为状态转移方程。

#### 目标函数与最优化概念

目标函数是衡量多阶段决策过程优劣的准则。最优化概念是在一定条件下找到一个途径，经过按题目具体性质所确定的运算以后，使全过程的总效益达到最优。



## 区间DP

区间dp就是在区间上进行动态规划，求解一段区间上的最优解。主要是通过合并小区间的 最优解进而得出整个大区间上最优解的dp算法。



### 思路

在一个区间上的最优解，可以将这个区间分割成一个个小区间，求解每个小区间的最优解，再合并小区间得到大区间即可。

所以在代码实现上，可以枚举区间长度len为每次分割成的小区间长度（由短到长不断合并），内层枚举该长度下可以的起点，自然终点也就明了了。然后在这个起点终点之间枚举分割点，求解这段小区间在某个分割点下的最优解。



### 代码（模板）

```c++
for (int len = 1; len <= n; len++) {//枚举长度
	for (int j = 1; j + len <= n + 1; j++) {//枚举起点，ends<=n
        int ends = j + len - 1;
        for (int i = j; i < ends; i++) {//枚举分割点，更新小区间最优解
            dp[j][ends] = min(dp[j][ends], dp[j][i] + dp[i + 1][ends] + w);
        }
    }
}
```



### 朴素区间dp

#### 例题 石子归并1

**时间复杂度 O(n^3^)**



#### 思路分析

**状态转移方程**

`dp[j][ends] = min(dp[j][ends],dp[j][i]+dp[i+1][ends]+weigth[i][ends]);`

j~ends堆合并 = 较小的（原来， 分割点i坐部分重量 + 分割点i右边部分重量 + 合并后两堆总重量）

可以用sum[j] - sum[i - 1]表示i~j堆的重量



#### 代码

```c++
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f
int stone[105] = {0};
int dp[105][105] = {0};
int sum[105] = {0};

int main() {
    int n;
    cin >> n;
    memset(dp, INF, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        cin >> stone[i];
        sum[i] = sum[i - 1] + stone[i];//重量
        dp[i][i] = 0;
    }
    for (int len = 1; len <= n; len++) {//枚举长度
        for (int j = 1; j + len <= n + 1; j++) {//枚举起点，ends<=n
            int ends = j + len - 1;
            for (int i = j; i < ends; i++) {//枚举分割点
                dp[j][ends] = min(dp[j][ends], dp[j][i] + dp[i+1][ends] + sum[ends] - sum[j-1]);//更新状态
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}

```



### 线性变环状

#### 例题 石子归并2

#### 思路分析

环状以后合并区间的情况就可以从后往前合并，最后合并完成可能是`1~n,2~n~1,3~n~2.....`这种n个石子合并的情况。所以我们可以破环成链，将前n-1各元素也放到n后面构成一个线性的环状序列，在对这个序列dp即可



#### 代码

```c++
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f
int stone[105] = {0};
int dpmin[205][205] = {0};//最小
int dpmax[205][205] = {0};//最大
int sum[205] = {0};
int main() {
    int n;
    cin >> n;
    memset(dpmin, INF, sizeof(dpmin));
    memset(dpmax, -1, sizeof(dpmax));
    for (int i = 1; i <= n; i++) {
        cin >> stone[i];
        sum[i] = sum[i - 1] + stone[i];
        dpmin[i][i] = 0;
        dpmax[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        sum[i + n] = sum[i + n - 1] + stone[i];//展开的n后面的n-1~1重量
        dpmin[i + n][i + n] = 0;
        dpmax[i + n][i + n] = 0;
    }
    for (int len = 1; len <= n; len++) {//长度还是最大n
        for (int j = 1; j + len <= 2 * n; j++) {//起点枚举最大到2*n-1,ends<=2*n-1
            int ends = j + len - 1;
            for (int i = j; i < ends; i++) {//注意！i<ends！！！因为i=ends时，dp[ends+1][ends]是不成立的！
                dpmin[j][ends] = min(dpmin[j][ends], dpmin[j][i] + dpmin[i + 1][ends] + sum[ends] - sum[j - 1]);
                dpmax[j][ends] = max(dpmax[j][ends], dpmax[j][i] + dpmax[i + 1][ends] + sum[ends] - sum[j - 1]);
            }
        }
    }
    int ansmin = 0xfffffff;
    int ansmax = -1;
    for (int i = 1; i <= n; i++) {
        ansmin = min(ansmin, dpmin[i][i + n - 1]);//找1~n,2~n~1,3~n~2....的合并n个堆的中最大和最小的值
        ansmax = max(ansmax, dpmax[i][i + n - 1]);
    }
    cout << ansmin << endl;
    cout << ansmax << endl;
    return 0;
}

```



### 时间优化（四边形优化）

**时间复杂度 O(n^2^)**

#### 思路

在查找最优分割点的时候，我们浪费了大量时间。那么我们可以把最优分割点保存下来，在查找的时候利用保存的最优分割点来优化查找过程。



#### 四边形不等式优化

1. 功能：用来寻找，`s[i][j]`(i~j的最优分割点）与其他分割点的关系

2. 不等式内容：如果某东西满足a<b<=c<d且`f[a][c]+f[b][d]<=f[a][d]+f[b][c]`,则说这个东西满足四边形不等式。简而言之：交叉小于包含！

3. 结论关系：`s[i][j-1]<=s[i][j]<=s[i+1][j]` 

4. 证明过程：https://blog.csdn.net/noiau/article/details/72514812



#### 代码（石子归并2）

```c++
#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f
int dp[2005][2005] = {0};
int sum[2005] = {0};
int relation[2005][2005] = {0};
int num[2005] = {0};
int main() {
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        dp[i][i] = 0;
        relation[i][i] = i;
        sum[i] = sum[i-1] + num[i];
    }
    for (int i = 1; i <= n; i++) {
        sum[i + n] = sum[i + n - 1] + num[i];
        relation[i + n][i + n] = i + n; //分割点初始化
        dp[i + n][i + n] = 0;
    }
    for (int len = 1; len <= n; len++){
        for (int j = 1; j + len <= 2 * n; j++){
            int ends = j + len - 1;
            for (int k = relation[j][ends - 1]; k <= relation[j + 1][ends]; k++) {//k的范围
                if (dp[j][ends] > dp[j][k] + dp[k + 1][ends] + sum[ends] - sum[j - 1]) {
                    dp[j][ends] = dp[j][k] + dp[k + 1][ends] + sum[ends] - sum[j - 1];
                    relation[j][ends] = k;
                }
            }
        }
    }
    int ans = 0xfffffff;
    for (int i = 1; i <= n; i++){
        ans = min(ans, dp[i][i + n - 1]);
    }
    cout << ans << endl;
    return 0;
}
```





## 数位DP

大佬的博客 https://blog.csdn.net/wust_zzwh/article/details/52100392

这里只做数位dp的入门讲解，数位dp的变化比较多，其他的dp也一样，想学好dp（所有的知识都要不断的刷题）只能不断的刷题，建立自己的思维，有兴趣的可以看看这篇博客，学习一下数位dp的优化方法



数位dp是一种计数用的dp，一般就是要统计一个区间内满足一些条件数的个数。

数位的含义：一个数有个位、十位、百位、千位......数的每一位就是数位

 **数位dp的实质就是换一种暴力枚举的方式，使得新的枚举方式满足dp的性质，然后记忆化就可以了。**



### 枚举

控制上界枚举，从最高位开始往下枚举，例如：ri=213，那么我们从百位开始枚举：百位可能的情况有0、1、2，然后每一位枚举都不能让枚举的这个数超过上界213（下界就是0或者1）。

* 当百位枚举了1，那么十位枚举就是从0到9，因为百位1已经比上界2小了，后面数位枚举什么都不可能超过上界。所以问题就在于：当高位枚举刚好达到上界是，那么紧接着的一位枚举就有上界限制了。

* 如果百位枚举了2，那么十位的枚举情况就是0到1。

* 如果前两位枚举了21，最后一位之是0到3**(这一点正好对于代码模板里的一个变量limit 专门用来判断枚举范围)**。

* 最高位枚举0：百位枚举0，相当于此时我枚举的这个数最多是两位数，如果十位继续枚举0，那么我枚举的就是一位数，因为我们要枚举的是小于等于ri的所以数，当然不能少了位数比ri小的**(这样枚举是为了无遗漏的枚举，不过可能会带来一个问题，就是前导零的问题，模板里用lead变量表示，不过这个不是每个题目都是会有影响的，可能前导零不会影响我们计数，具体要看题目)**

**既然从高位往低位枚举，那么状态一般都是与前面已经枚举的数位有关并且通常是根据约束条件当前枚举的这一位能使得状态完整**(比如一个状态涉及到连续k位，那么就保存前k-1的状态，当前枚举的第k个是个恰好凑成成一个完整的状态，不过像那种状态是数位的和就直接保存前缀和为状态了)



**这种枚举只控制了上界所以我们的主函数应为**

```c++
int main() {
    long long le,ri;
    while (scanf("%lld %lld", &le, &ri) != EOF) {
        printf("%lld\n",solve(ri) - solve(le - 1));
    }
}
```



### 代码 (模板)

```c++
typedef long long ll;
int a[20] = {0};
ll dp[20][state] = {0};//不同题目状态不同
ll dfs(int pos, /*state变量*/, bool lead/*前导零*/, bool limit/*数位上界变量*/) {//不是每个题都要判断前导零
    //递归边界，既然是按位枚举，最低位是0，那么pos==-1说明这个数我枚举完了
    if (pos == -1) return 1;/*这里一般返回1，表示你枚举的这个数是合法的，那么这里就需要你在枚举时必须每一位都要满足题目条件，也就是说当前枚举到pos位，一定要保证前面已经枚举的数位是合法的。不过具体题目不同或者写法不同的话不一定要返回1 */
    //第二个就是记忆化(在此前可能不同题目还能有一些剪枝)
    if (!limit && !lead && dp[pos][state] != -1) return dp[pos][state];
    /*常规写法都是在没有限制的条件记忆化，这里与下面记录状态是对应，具体为什么是有条件的记忆化后面会讲*/
    int up = (limit ? a[pos] : 9);//根据limit判断枚举的上界up;这个的例子前面用213讲过了
    ll ans = 0;
    //开始计数
    for (int i = 0;i <= up; i++) {//枚举，然后把不同情况的个数加到ans就可以了
        if() ...
        else if()...
        ans += dfs(pos - 1, /*状态转移*/, lead && i == 0, limit && i == a[pos]) //最后两个变量传参都是这样写的
        /*当前数位枚举的数是i，然后根据题目的约束条件分类讨论
        去计算不同情况下的个数，还有要根据state变量来保证i的合法性，比如题目
        要求数位上不能有62连续出现,那么就是state就是要保存前一位pre,然后分类，
        前一位如果是6那么这意味就不能是2，这里一定要保存枚举的这个数是合法*/
    }
    //计算完，记录状态
    if (!limit && !lead) dp[pos][state] = ans;
    /*这里对应上面的记忆化，在一定条件下时记录，保证一致性，当然如果约束条件不需要考虑lead，这里就是lead就完全不用考虑了*/
    return ans;
}
ll solve(ll x) {
    int pos = 0;
    while(x) {//把数位都分解出来
        a[pos++] = x % 10;//个人老是喜欢编号为[0,pos),看不惯的就按自己习惯来，反正注意数位边界就行
        x /= 10;
    }
    return dfs(pos - 1/*从最高位开始枚举*/, /*一系列状态 */, true, true);//刚开始最高位都是有限制并且有前导零的，显然比最高位还要高的一位视为0嘛
}
int main() {
    ll le,ri;
    while(scanf("%lld%lld", &le, &ri) != EOF) {
        //初始化dp数组为-1,这里还有更加优美的优化
        printf("%lld\n", solve(ri) - solve(le - 1));
    }
}
```



### 例题 HDU2089



#### 思路分析

数位上不能有4也不能有连续的62，没有4的话在枚举的时候判断一下，不枚举4就可以保证状态合法了，所以这个约束没有记忆化的必要。

对于62，涉及到两位，当前一位是6或者不是6这两种不同情况计数是不相同的，所以要用状态来记录不同的方案数。

`dp[pos][sta]`表示当前第pos位，前一位是否是6的状态，这里sta只需要去0和1两种状态就可以了，不是6的情况可视为同种，不会影响计数。



### 代码

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





## 树状DP

之所以这样命名树规，是因为树形DP的这一特殊性：没有环，dfs是不会重复，而且具有明显而又严格的层数关系。利用这一特性，我们可以很清晰地根据题目写出一个在树（型结构）上的记忆化搜索的程序。而深搜的特点，就是“不撞南墙不回头”。这一点在之后的文章中会详细的介绍。



### 树的特点与性质：

1、 有n个点，n-1条边的无向图，任意两顶点间可达
2、 无向图中任意两个点间有且只有一条路
3、 一个点至多有一个前趋，但可以有多个后继
4、 无向图中没有环；

#### 拿到一道树规题，我们有以下3个步骤需要执行：

**判断是否是一道树规题：**

即判断数据结构是否是一棵树，然后是否符合动态规划的要求。如果是，那么执行以下步骤，如果不是，那么换台。

**建树：**

通过数据量和题目要求，选择合适的树的存储方式。

如果节点数小于5000，那么我们可以用邻接矩阵存储，如果更大可以用邻接表来存储(注意边要开到2*n，因为是双向的。这是血与泪的教训)。如果是二叉树或者是需要多叉转二叉，那么我们可以用两个一维数组brother[]，child[]来存储（这一点下面会仔细数的）。

**写出树规方程：**

通过观察孩子和父亲之间的关系建立方程。我们通常认为，树形DP的写法有两种：

* 根到叶子: 不过这种动态规划在实际的问题中运用的不多。本文只有最后一题提到。
* 叶子到根: 既根的子节点传递有用的信息给根，完后根得出最优解的过程。这类的习题比较的多。

**注意：**

这两种写法一般情况下是不能相互转化的。但是有时可以同时使用具体往后看。



### 以下即将分析的题目的目录及题目特点：

1. 加分二叉树：区间动规+树的遍历；
2. 二叉苹果树：二叉树上的动规；
3. 最大利润：多叉树上的动规；
4. 选课：多叉树转二叉；
5. 选课（输出方案）：多叉转二叉+记录路径；
6. 软件安装：判断环+缩点+多叉转二叉；

**4 5 6属于依赖问题的变形**



### HDU1520

#### 思路分析

树形dp的常规入门题：设`dp[i][0]`表示:当前这个点不选，`dp[i][1]`表示当前这个点选择的最优解。

**转移方程**

`dp[cur][0]+=max(dp[son][1],dp[son][0]);`

当前这个点不选，那他的孩子可选可不选，取最大的。 

`dp[cur][1]+=dp[son][0]`

当前这点选择，那他的孩子就不能选择。



### 代码

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





## 状态压缩DP

状态压缩动态规划，就是我们俗称的**状压DP**，是利用**计算机二进制**的性质来描述状态的一种DP方式

很多棋盘问题都运用到了状压，同时，状压也很经常和ＢＦＳ及ＤＰ连用，例题里会给出介绍

有了状态，DP就比较容易了

举个例子：有一个大小为n*n的农田，我们可以在任意处种田，现在来描述一下某一行的某种状态：

设n = 9；
有二进制数 100011011（九位），每一位表示该农田是否被占用，1表示用了，0表示没用，这样一种状态就被我们表示出来了：见下表

| 列 数  | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| ------ | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 二进制 | 1    | 0    | 0    | 0    | 1    | 1    | 0    | 1    |
| 是否用 | √    | ×    | ×    | ×    | √    | √    | ×    | √    |

所以我们最多只需要 2^n+1^−1 的十进制数就好（左边那个数的二进制形式是n个1）

现在我们有了表示状态的方法，但心里也会有些不安:上面用十进制表示二进制的数，枚举了全部的状态，DP起来复杂度岂不是很大？没错，状压其实是一种**很暴力的算法**，因为他需要遍历每个状态，所以将会出现2^n^的情况数量，不过这并不代表这种方法不适用：**一些题目可以依照题意，排除不合法的方案，使一行的总方案数大大减少从而减少枚举**



### 位运算在状压dp中的应用

#### 判断一个数字x二进制下第i位是不是等于1。

方法：

```c++
if (((1 << (i − 1)) & x) > 0)
```

将1左移i-1位，相当于制造了一个只有第i位上是1，其他位上都是0的二进制数。然后与x做与运算，如果结果>0，说明x第i位上是1，反之则是0。

#### 将一个数字x二进制下第i位更改成1。

方法：

```c++
x = x | (1 << (i − 1))
```

#### 把一个数字二进制下最靠右的第一个1去掉。

方法：

```c++
x = x & (x − 1)
```



### HDU1992

#### 思路分析

算成n行的砖，每行有四。然后用4个01位表示一行，如果是0表示这一行不会占用下一行的地方，如果是1表示会占用下一行的砖。

状态转移有三种：

1. 当前行当前位为1，那么直接转移到下一位
2. 当前行当前位为0，那么可以表示下一行可以为1

3. 当前行当前位和下一位为00，那么下一行也可以为00



#### 代码

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





## 概率DP

- 数学期望 P=Σ每一种状态*对应的概率。
- 因为不可能枚举完所有的状态，有时也不可能枚举完，比如抛硬币，有可能一直是正面。大多数题就是手动**找公式**或者**DP推出**即可，只要**处理好边界**，然后**写好方程**，代码超级简短。与常规的求解不同，数学期望经常逆向推出。

- 比如常规的dp[x]可能表示**到了x这一状态有多少，最后答案是dp[n]**。而数学期望的dp[x]一般表示**到了x这一状态还差多少，最后答案是dp[0]**。



### 例题 掷骰子

```c++
#include <iostream>
using namespace std;
int dp[1005][1005] = {0};

int gcd(int x, int y) {
     if(y == 0) return x;    
     if(x < y) return gcd(y, x);    
     else return gcd(y, x % y); 
} 

int main(){
	int n, m;
	cin >> n >> m;
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 6 * i; j++){
			for(int k = 1; k <= 6; k++){
				dp[i+1][j+k] += dp[i][j];//前一次的投的方案数加上这一次投的数字   的方案数 
			}
		}
	}
	int ans = 0;
	for(int i = m; i <= 6 * n; i++){
		ans += dp[n][i];
	}
	int sum = 1;
	for(int i = 0; i < n; i++){
		sum *= 6;
	}
	int temp = gcd(ans, sum);
	cout << ans / temp << "/" << sum / temp << endl;
	return 0;
}
```

