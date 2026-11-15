# C 题解

## 思路

按题意逐对检查相邻柱子高度差即可。

设相邻两柱高度为 `a[i-1]`、`a[i]`：

- 如果是上升：`a[i] > a[i-1]`，则要求 `a[i]-a[i-1] <= 1`。
- 如果是下降：`a[i] < a[i-1]`，则要求 `a[i-1]-a[i] <= X`。

直接线性扫一遍：

1. 读入数组。
2. 从 `i=2` 到 `n`：
   - 若下降且降幅大于 `X`，输出 `Lose` 并返回。
   - 否则若上升且升幅大于 `1`，输出 `Lose` 并返回。
3. 扫完都合法，输出 `Win`。

## 复杂度

- 单组时间复杂度：$O(n)$。
- 单组空间复杂度：$O(n)$（存输入数组）。


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
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++) {
        if(a[i] < a[i - 1] && abs(a[i] - a[i - 1]) > x) {
            cout << "Lose" << endl;
            return ;
        } else if(a[i] > a[i - 1] && abs(a[i] - a[i - 1]) > 1) {
            cout << "Lose" << endl;
            return ;
        }
    }

    cout << "Win" << endl;
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
