// 原始稿：03_题目/牛客/contest/03/j.cpp
// 原文行号：1-51；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int log2(ll x)
{
    return 63 - __builtin_clzll(x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;

    while (T--)
    {
        ll n, q;
        cin>>n>>q;

        int h = log2(n) + 1;

        while (q--)
        {
            ll x;
            cin>>x;

            int dp = log2(x);

            ll ans = 0;
            if (dp < h - 1)
            {
                ans = 1LL << dp;
            }
            else
            {
                ll tmp = 1LL << dp;

                ans = n - tmp + 1;
            }

            cout<<ans<<endl;
        }
    }

    return 0;
}
