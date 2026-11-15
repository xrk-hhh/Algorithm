# D 题解

## 思路

设 `f(x)` 表示合成出等级 `x` 的西瓜所需的最少基础西瓜数。

结论是：

1. 当 `x <= y` 时，直接拿一个等级为 `x` 的基础西瓜即可，`f(x)=1`。
2. 当 `x > y` 时，先得到 `y+1` 级需要 `y+1` 个基础西瓜；之后每升 1 级，需求翻倍。

所以：

$$
f(x)=(y+1)\cdot 2^{x-y-1}\pmod{998244353}\quad (x>y)
$$

实现：

- `x <= y` 输出 `1`。
- 否则输出 `(y+1) * ksm(2, x-y-1, MOD) % MOD`。

其中 `ksm` 是快速幂。

## 复杂度

- 单组时间复杂度：$O(\log(x-y))$（快速幂）。
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
    int x, y;
    cin >> x >> y;
    if(x <= y) {
        cout << 1 << endl;
    } else {
        cout << (y + 1) * ksm(2LL, (x - y - 1), MOD) % MOD << endl;
    }
}



/*

012345
0123456
01234567
012345678
012345678....x-1
x

012...y
y+1 : 1
y+2 : 2
y+3 : 4
y+d : 2^(d-1)

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
