# B 题解

## 思路

两轮比赛日期分别是等差数列：

- 第一轮：`s1 + T1 * k`，`k = 0...n-1`
- 第二轮：`s2 + T2 * j`，`j = 0...m-1`

要求“先参加第一轮，再参加第二轮”，且不能同一天，所以对每个第二轮日期 `i`，需要统计满足：

$$
s1 + T1\cdot k \le i-1
$$

的第一轮场次数量。

从不等式可得：

$$
k \le \frac{i-1-s1}{T1}
$$

因此当前可选第一轮数量是：

$$
\min\left(n,\ \left\lfloor\frac{i-1-s1}{T1}\right\rfloor+1\right)
$$

若 `i-1-s1 <= 0`，说明一个都选不了，直接跳过。

把所有第二轮日期对应的可选数量累加，就是答案。

## 复杂度

- 时间复杂度：$O(m)$（逐个枚举第二轮场次）。
- 空间复杂度：$O(1)$。


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
    int s1 = 789456, T1 = 567890, n = 901234;
    int s2 = 654321, T2 = 876543, m = 500001;

    int ans = 0;
    for(int i = s2, j = 0; j < m; i += T2, j++) {
        if(i - 1 - s1 <= 0) continue;
        // s1 + T1 * k <= i - 1
        // T1 * k <= (i - 1 - s1)
        // k <= (i - 1 - s1) / T1
        int cur = min(n, (i - 1 - s1) / T1 + 1);
        ans += cur;
    }

    cout << ans << endl;
}



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
