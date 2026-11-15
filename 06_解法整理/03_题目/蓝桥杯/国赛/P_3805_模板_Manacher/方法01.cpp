// 原始稿：03_题目/蓝桥杯/国赛/P_3805_模板_Manacher.cpp
// 原文行号：1-93；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int N = 1.1e7 + 10;
const int B = 131, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int n;
string s;
ll p1[N], p2[N];
ll h1[N], h2[N];
ll rh1[N], rh2[N];

void init()
{
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p1[i] = p1[i - 1] * B % mod1;
        p2[i] = p2[i - 1] * B % mod2;
        h1[i] = (h1[i - 1] * B + s[i]) % mod1;
        h2[i] = (h2[i - 1] * B + s[i]) % mod2;
    }
    for (int i = n; i >= 1; i--)
    {
        rh1[i] = (rh1[i + 1] * B + s[i]) % mod1;
        rh2[i] = (rh2[i + 1] * B + s[i]) % mod2;
    }
}

pair<ll, ll> getH(int l, int r)
{
    ll v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
    ll v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;
    return {v1, v2};
}
pair<ll, ll> getRH(int l, int r)
{
    ll v1 = (rh1[l] - rh1[r + 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
    ll v2 = (rh2[l] - rh2[r + 1] * p2[r - l + 1] % mod2 + mod2) % mod2;
    return {v1, v2};
}

bool check(int len)
{
    for (int i = 1; i <= n - len + 1; i++)
    {
        if (getH(i, i + len - 1) == getRH(i, i + len - 1))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        cin>>s;
        n = s.size();
        s = " " + s;

        init();

        int l = 1, r = n + 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        cout<<r<<endl;
    }

    return 0;
}
