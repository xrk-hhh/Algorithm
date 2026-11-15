# G-彩色装饰

## 题意转成“边界贡献”

对颜色 `k` 和区间 `[l,r]`，把 `a[l..r]` 全刷成 `k` 后：

1. 左半段 `a[1..l-1]` 的美丽度不变。
2. 右半段 `a[r+1..n]` 的美丽度不变。
3. 中间刷色段默认会贡献 `+1` 段。
4. 若 `l>1` 且 `a[l-1]=k`，会和左边并段，贡献减 `1`。
5. 若 `r<n` 且 `a[r+1]=k`，会和右边并段，贡献再减 `1`。

所以每个区间的最终贡献是：

$$
\text{left}+\text{right}+1-\mathbf{1}_{\text{左并}}-\mathbf{1}_{\text{右并}}
$$

代码就是把这几部分拆开统计。



## 一、固定颜色 `k` 后怎么加“中间段贡献”

记总区间数：

$$
TOT=\frac{n(n+1)}{2}
$$

再定义三类区间数量：

1. `ADD`：左右都不并段（中间净贡献 `+1`）。
2. `SAME`：恰好一侧并段（中间净贡献 `0`）。
3. `DEL`：两侧都并段（中间净贡献 `-1`）。

于是：

$$
ans_k = BASE + ADD - DEL
$$

代码正是：

```cpp
int ADD = TOT - DEL - SAME;
cout << BASE + ADD - DEL << endl;
```



## 二、`BASE` 的含义与代码解释

`BASE` 统计的是“所有区间的 left+right 之和”，与 `k` 无关。

代码前半段：

```cpp
pre += (a[i] != a[i - 1]);
BASE += pre * (n - i);
```

解释：

1. `pre` 表示前缀 `a[1..i]` 的美丽度。
2. 当 `l=i+1` 时，左段固定是 `a[1..i]`，右端点 `r` 有 `n-i` 种选法。
3. 所以这部分累计 `pre*(n-i)`。

代码后半段：

```cpp
suf += (a[i] != a[i + 1]);
BASE += suf * (i - 1);
```

解释：

1. `suf` 表示后缀 `a[i..n]` 的美丽度。
2. 当 `r=i-1` 时，右段固定是 `a[i..n]`，左端点 `l` 有 `i-1` 种选法。
3. 所以这部分累计 `suf*(i-1)`。

两段加起来就是所有区间的 `left+right` 总和。



## 三、`DEL`、`SAME` 在代码里如何被算出来

设 `pos[k]` 是颜色 `k` 的出现位置，升序为 $p_0,p_1,...,p_{s-1}$。

### 1. 第一遍循环（从左到右）

代码：

```cpp
int del = i;
if(i > 0 && pos[k][i - 1] == pos[k][i] - 1) del--;
int same = (pos[k][i] - 1) - del;
DEL += del;
SAME += same;
```

这一段可以理解为“固定右并段边界”：

1. 令 $r+1 = p_i$，则 $r = p_i-1$，可选的 $l$ 一共有 $p_i-1$ 种。
2. 其中会同时左并 $+$ 右并的有 $del$ 种。
3. 剩下 $same = (p_i-1)-del$ 种是“仅右并段”。

$del$ 初值是 $i$，表示可选左侧 $k$ 的个数；若 $p_{i-1}$ 与 $p_i$ 相邻，则这对边界中间没有空间放区间，需要减掉 1，所以有 `del--`。

### 2. 第二遍循环（从右到左）

代码：

```cpp
int del = (pos[k].size() - i - 1);
if(i < pos[k].size() - 1 && pos[k][i + 1] == pos[k][i] + 1) del--;
int same = (n - pos[k][i]) - del;
SAME += same;
```

这一段对称地“固定左并段边界”：

1. 令 $l-1 = p_i$，则 $l = p_i+1$，可选的 $r$ 一共有 $n-p_i$ 种。
2. 其中两侧都并段的还是 `del`（这里只用于扣除）。
3. 剩下 $same$ 是“仅左并段”，加到 `SAME`。

### 3. 颜色不存在的特判

若 `pos[k]` 为空，不可能发生并段：

1. `DEL=0,SAME=0,ADD=TOT`
2. 直接输出 `BASE+TOT`

对应代码：

```cpp
if(pos[k].empty()) {
    cout << BASE + (n + 1) * n / 2 << endl;
    continue;
}
```

---

## 四、复杂度

1. 建 `pos`、算 `BASE`：$O(n)$。
2. 每个颜色的循环里，总访问位置次数等于该颜色出现次数，所有颜色合计 $O(n)$。
3. 再加外层颜色枚举 $O(m)$。

总时间复杂度 $O(n+m)$，空间复杂度 $O(n+m)$。


## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
typedef pair<ll, ll> P;
#define x first
#define y second
#define int long long
#define i128 __int128
#define i64 long long

const int mod = 1e9 + 7;
const int MOD = 998244353;

const int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int ddx[8] = {1, 1, 2, 2, -1, -1, -2, -2}, ddy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

ll ksm(ll a, ll b, ll p) {
    ll sum = 1;
    a %= p;
    while(b) {
        if(b & 1) sum = (sum * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return sum % p;
}

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    std::uniform_int_distribution<int> distribution(l, r);
    return distribution(rng);
}



void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2);
    vector<vector<int>> pos(m + 1);
    int BASE = 0;
    int pre = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].emplace_back(i);
        pre += (a[i] != a[i - 1]);
        BASE += pre * (n - i);
    }

    int suf = 0;
    for(int i = n; i > 0; i--) {
        suf += (a[i] != a[i + 1]);
        BASE += suf * (i - 1);
    }
    // cerr << "BASE : " << BASE << endl;

    for(int k = 1; k <= m; k++) {
        int DEL = 0, SAME = 0;
        if(pos[k].empty()) {
            cout << BASE + (n + 1) * n / 2 << endl;
            continue;
        }
        for(int i = 0; i < pos[k].size(); i++) {
            int del = i;
            if(i > 0 && pos[k][i - 1] == pos[k][i] - 1) {
                del--;
            }
            int same = (pos[k][i] - 1) - del;
            DEL += del;
            SAME += same;
        }
        for(int i = pos[k].size() - 1; i >= 0; i--) {
            int del = (pos[k].size() - i - 1);
            if(i < pos[k].size() - 1 && pos[k][i + 1] == pos[k][i] + 1) {
                del--;
            }
            int same = (n - pos[k][i]) - del;
            SAME += same;
        }
        int ADD = (n + 1) * n / 2 - DEL - SAME;
        // cerr << "DEL : " << DEL << ", SAME : " << SAME << ", ADD : " << ADD << endl;

        cout << BASE + ADD - DEL << endl;
    }
}



/*

50 20
17 5 9 8 3 7 17 3 1 9 18 14 9 5 5 12 12 16 11 19 12 2 14 12 12 16 2 10 12 9 20 3 14 6 10 13 10 10 17 11 15 10 2 1 8 18 6 3 12 17

*/

signed main () {
    // sieve(minp, primes, m); // primes
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // init();
    int _ = 1;
    // cin >> _;
    while(_ -- ) {
        solve();
    }
    return 0;
}
```
