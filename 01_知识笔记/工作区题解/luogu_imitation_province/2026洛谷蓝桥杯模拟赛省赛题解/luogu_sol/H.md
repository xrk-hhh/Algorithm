# H-树上检查

## 一、考虑 k 是非常小的

设选出的 `k` 个检查点集合是 `S`。

在本题范围 `k<=4` 下，一个集合 `S` 的最少路径条数只有两种可能：

1. `S` 全在同一条简单路径上，最少是 `1` 条。
2. 否则最少是 `2` 条。

因此总答案可以写成：

$$
\text{Ans}=1\cdot good + 2\cdot(total-good)=2\cdot total-good
$$

其中：

1. `total = C(n,k)`，是所有 `k` 点集合个数。
2. `good` 是“这 `k` 个点能被一条简单路径覆盖”的集合个数。

代码里的 `sum`，就是这个 `good`。

---

## 二、`k=1,2` 的特判（对应代码前半段）

代码：

```cpp
if(k <= 2) {
    if(k == 1) cout << n;
    else cout << n * (n - 1) / 2;
    return;
}
```

解释：

1. `k=1` 时任意单点都只需 1 条路径，答案 `n`。
2. `k=2` 时任意两点天然在同一条简单路径上，答案 `C(n,2)`。

---

## 三、DP 状态含义（对应 `f` 数组）

根设为 `1`，DFS。

定义（按这份代码的转移语义）：

`f[u][x]` 表示在 `u` 的子树中，选 `x` 个点，且这些点可以放在一条“单臂路径”上（只向一个儿子方向延伸，不跨两个儿子方向）的方案数。

这里“单臂”是为了和后面“跨两个儿子、经过 `u` 的路径”区分开。

---

## 四、DFS 内每段代码在做什么

### 1. 初始化与合并儿子

```cpp
f[u][0] = 1;
for(v in son[u]) {
    dfs(v,u);
    for(x=1..k) f[u][x] += f[v][x];
}
```

解释：

1. `f[u][0]=1` 是空选。
2. 先把“完全在某个儿子单臂里的方案”加到 `u`。

### 2. 把 `u` 自己并进方案

```cpp
for(int x = k; x > 0; x--) f[u][x] += f[u][x - 1];
```

解释：

1. 下降循环避免重复使用本轮新值。
2. 含义是：若原来有 `x-1` 个点在这条单臂路径上，再把 `u` 选上，就得到 `x` 个点方案。

### 3. 统计“经过 `u`、跨两个儿子”的一条路径

```cpp
for(int x = 1; x < k; x++) {
    vector<int> dp(k + 1);
    for(v in son[u]) {
        sum += dp[x] * f[v][k - x];
        if(x - 1 > 0) sum += dp[x - 1] * f[v][k - x];
        if(k - x - 1 > 0) sum += dp[x] * f[v][k - x - 1];
        dp[x] += f[v][x];
    }
}
```

解释：

1. 固定拆分 `x`，表示左侧（已处理儿子）拿 `x` 个点，右侧（当前儿子 `v`）拿剩余点。
2. `dp[x]` 累积“前面儿子里拿 `x` 个点”的单臂方案。
3. 第一项 `dp[x] * f[v][k-x]` 对应不把 `u` 作为检查点时的拼接。
4. 第三项 `dp[x] * f[v][k-x-1]` 对应把 `u` 作为检查点，右侧少拿一个点。
5. 第二项 `dp[x-1] * f[v][k-x]` 也是“`u` 作为检查点”的对称写法；在这份代码里 `dp` 每个 `x` 重新初始化，这项通常为 0，保留不影响最终正确性。

这段的本质是：把“来自两个不同儿子方向”的单臂路径拼成一条经过 `u` 的完整简单路径，从而把对应 `k` 点集合计入 `sum`。

### 4. DFS 结束后的补充

```cpp
sum += f[1][k];
```

解释：

1. 上面双儿子拼接只统计了“真正跨两个方向”的路径。
2. `f[1][k]` 补上“不跨两个方向、只是一条单臂链”的 `k` 点方案。

于是 `sum` 就是 `good`。

---

## 五、组合数与最终输出

代码：

```cpp
int total = C(n,3) 或 C(n,4);
cout << (((total - sum) * 2 + sum) % MOD + MOD) % MOD;
```

其中组合数用快速幂逆元算：

1. `C(n,3)=n(n-1)(n-2)/6`
2. `C(n,4)=n(n-1)(n-2)(n-3)/24`

最终式子就是：

$$
2\cdot total - good
$$

按 `MOD=998244353` 取模输出。

---

## 六、复杂度

1. 每条边在 DFS 中被遍历常数次。
2. `k` 只有 `1..4`，内层拆分是常数级。

所以单组复杂度：

1. 时间复杂度 `O(n*k)`，在本题等价于 `O(n)`。
2. 空间复杂度 `O(n*k)`，在本题等价于 `O(n)`。


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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for(int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    if(k <= 2) {
        if(k == 1) {
            cout << n << endl;
        } else {
            cout << (n * (n - 1) / 2) % MOD << endl;
        }
        return ;
    }

    int sum = 0;
    vector<vector<int>> f(n + 1, vector<int>(k + 1));
    auto dfs = [&](auto && self, int u, int fa) -> void {
        f[u][0] = 1;
        for(auto & v : g[u]) {
            if(v == fa) continue;
            self(self, v, u);
            for(int x = 1; x <= k; x++) {
                f[u][x] += f[v][x];
                f[u][x] %= MOD;
            }
        }
        for(int x = k; x > 0; x--) {
            f[u][x] += f[u][x - 1];
            f[u][x] %= MOD;
        }
        for(int x = 1; x < k; x++) {
            vector<int> dp(k + 1);
            for(auto & v : g[u]) {
                if(v == fa) continue;
                sum += dp[x] * (f[v][k - x]) % MOD;
                sum %= MOD;
                if(x - 1 > 0) {
                    sum += dp[x - 1] * (f[v][k - x]) % MOD;
                    sum %= MOD;
                }
                if(k - x - 1 > 0) {
                    sum += dp[x] * (f[v][k - x - 1]) % MOD;
                    sum %= MOD;
                }
                dp[x] += (f[v][x]);
                dp[x] %= MOD;
            }
        }
    };
    dfs(dfs, 1, 0);
    sum += f[1][k];

    auto inv = [&](int x) -> int {
        return ksm(x, MOD - 2, MOD);
    };

    int total = n * (n - 1) % MOD * (n - 2) % MOD * inv(6) % MOD;
    if(k == 4) {
        total = n * (n - 1) % MOD * (n - 2) % MOD * (n - 3) % MOD * inv(24) % MOD;
    }
    // cerr << "total : " << total << ", sum : " << sum << endl;

    cout << (((total - sum) * 2 + sum) % MOD + MOD) % MOD << endl;
}



/*



*/

signed main () {
    // sieve(minp, primes, m); // primes
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // init();
    int _ = 1;
    cin >> _;
    while(_ -- ) {
        solve();
    }
    return 0;
}
```
