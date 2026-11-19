#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
// 当前解x≡a(mod m)，合入x≡b(mod n)，成功后写回a,m
bool crt_merge(ll &a, ll &m, ll b, ll n)
{
    ll x, y, g = exgcd(m, n, x, y);
    i128 d = (i128)b - a;
    if (d % g)
        return false;
    ll z = n / g;
    ll k = (d / g * x % z + z) % z;
    i128 mod = (i128)m * z; // 合并模数须在long long范围内
    a = ((i128)a + (i128)m * k) % mod;
    if (a < 0)
        a += mod;
    m = (ll)mod;
    return true;
} // 初始a=0,m=1；要求每个模数>0
