# E 题解

## 思路

把“停在某个前缀矿井内结束”逐个考虑。

设当前扫到矿井 `i`：

- `m`（代码里直接复用变量）表示扣掉移动费用后的剩余金钱。
- 在 `1..i` 中最多只能选 `K` 个矿井采矿，且每挖 1 矿要 1 金钱。

所以若我们知道前缀 `1..i` 里“可选的最多矿石量”为 `sumTopK`，则这一站能实现的采矿量是：

$$
\min(m,\ sumTopK)
$$

关键在于动态维护 `sumTopK`：

- 用一个**小根堆**保存当前前缀里选中的矿井矿石量。
- 每到新矿井 `i`，把 `A_i` 入堆并加到 `sum`。
- 如果堆大小超过 `K`，弹出最小值并从 `sum` 里减掉。
- 这样 `sum` 始终是“当前前缀最大的 `K` 个 `A` 之和”。

同时每步先做 `m -= c[i]`（`c[1]=0`），表示走到当前矿井的移动成本。
枚举全部前缀，取最大值即答案。

## 复杂度

- 时间复杂度：$O(n\log K)$。
- 空间复杂度：$O(K)$（堆）+ 输入数组。


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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n + 1), a(n + 1);
    for(int i = 2; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> q; // 小根堆
    int sum = 0;
    for(int i = 1; i <= n; i++) { // 枚举结束矿井的位置
        m -= c[i]; // m只在坐车花出去了
        // m 就是能用来开采的钱数
        sum += a[i];
        q.push(a[i]);
        if(q.size() > k) {
            sum -= q.top(); // 剔除目前最小的一个(小根堆)
            q.pop();
        }
        ans = max(ans, min(m, sum));
    }
    cout << ans << endl;
}

// 枚举+反悔贪心(小根堆动态维护前k大数字的和)

/*



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
