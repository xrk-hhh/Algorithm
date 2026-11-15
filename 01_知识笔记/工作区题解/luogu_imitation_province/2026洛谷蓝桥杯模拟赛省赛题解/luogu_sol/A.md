# A 题解

## 思路

这题是结果填空题，标程做法是**直接按日期暴力枚举**。

固定起止日期：

- 起点：`2239-09-09`
- 终点：`9876-01-01`

写两个辅助函数：

1. `run(y)`：判断闰年（和题面规则一致）。
2. `check(y,m,d)`：把年、月、日的十进制数位出现次数统计到 `cnt[10]`，忽略前导零；然后检查所有出现过的数字频次是否完全相同。

接着按标程分段遍历日期并累计：

1. 先单独判断终点 `9876-01-01`。
2. 枚举 `2239-09-09` 到 `2239-09-30`。
3. 枚举 `2239-10-01` 到 `2239-12-31`。
4. 枚举整年 `2240` 到 `9875` 的所有合法日期（2 月天数按闰年加 1）。

把所有 `check(...)` 为真的日期数量累加后直接输出。

## 复杂度

- 时间复杂度：$O(D)$，其中 $D$ 是被枚举的总天数（常数规模，约几百万天）。
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
    int y1 = 2239, m1 = 9, d1 = 9;
    int y2 = 9876, m2 = 1, d2 = 1;

    auto run = [&](int y) -> bool {
        if(y % 4 == 0 && y % 100) return 1;
        if(y % 400 == 0) return 1;
        return 0;
    };
    int M[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    auto check = [&](int y, int m, int d) -> bool { // 求一个年月日是否可爱
        vector<int> cnt(10);
        while(y) {
            cnt[y % 10]++;
            y /= 10;
        }
        while(m) {
            cnt[m % 10]++;
            m /= 10;
        }
        while(d) {
            cnt[d % 10]++;
            d /= 10;
        }
        int lst = -1;
        for(int i = 0; i < 10; i++) {
            if(cnt[i] == 0) continue;
            if(lst == -1) {
                lst = cnt[i];
            } else {
                if(lst != cnt[i]) {
                    return 0;
                }
            }
        }
        return 1;
    };
    
    int ans = check(y2, m2, d2);
    for(int d = 9; d <= M[9]; d++) { // 9-9 到 9-30
        ans += check(y1, m1, d);
    }
    for(int m = 10; m <= 12; m++) { // 2039年的10-12月
        for(int d = 1; d <= M[m]; d++) {
            ans += check(y1, m, d);
        }
    }
    for(int y = y1 + 1; y < y2; y++) {
        for(int m = 1; m <= 12; m++) {
            for(int d = 1; d <= M[m] + (run(y) && m == 2); d++) {
                ans += check(y, m, d);
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
