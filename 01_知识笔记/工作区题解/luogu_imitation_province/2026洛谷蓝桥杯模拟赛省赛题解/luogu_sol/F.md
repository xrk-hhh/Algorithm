# F 题解

## 思路

做法是一个按楼层从低到高的贪心模拟。

先把所有请求 `(F_i, A_i)` 按楼层升序排序，电梯先移动到最低请求楼层，代价：

$$
|X-F_{\min}|
$$

然后依次处理每层：

设当前楼层是 `f`，人数是 `a`，容量 `W`。

1. **整车人数**：`q = a / W`
   - 每一整车都要从 `f` 运到 `Y`，再回到 `f` 继续接人（按计法），
   - 贡献 `q * 2 * (Y-f)`。

2. **余数人数**：`r = a % W`
   - 若 `r > 0`：
     - 不是最后一层：把这 `r` 人“带着上行”到下一请求楼层，`a[i+1] += r`，并加路程 `F_{i+1}-f`。
     - 是最后一层：最后一次只需上到 `Y`，加 `Y-f`。
   - 若 `r = 0`：
     - 说明最后一次整车不需要“回到本层”，所以减去一次 `(Y-f)`。
     - 若还有下一层，请从 `Y` 下到下一层继续，补上 `(Y-F_{i+1})`。

上述转移完全对应每个分支与加减项。

## 复杂度

- 时间复杂度：排序 $O(n\log n)$，扫描 $O(n)$，总计 $O(n\log n)$。
- 空间复杂度：$O(n)$。


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
    int n, x, y, w;
    cin >> n >> x >> y >> w;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end());
    int ans = abs(x - a[1].first);
    for(int i = 1; i <= n; i++) {
        ans += (a[i].second / w) * (y - a[i].first) * 2;
        if(a[i].second % w > 0) {
            if(i < n) {
                a[i + 1].second += (a[i].second % w);
                ans += (a[i + 1].first - a[i].first);
            } else {
                ans += (y - a[i].first);
            }
        } else {
            ans -= (y - a[i].first);
            if(i < n) {
                ans += (y - a[i + 1].first);
            }
        }
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
