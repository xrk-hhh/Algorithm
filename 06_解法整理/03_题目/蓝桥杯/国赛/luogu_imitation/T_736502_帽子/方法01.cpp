// 原始稿：03_题目/蓝桥杯/国赛/luogu_imitation/T_736502_帽子.cpp
// 原文行号：1-51；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int mod = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        vector<int> cnt(n + 1, 0);
        ll ans = 1;
        for (int i = 0; i < n; i++)
        {
            ll t = m - cnt[a[i]];
            if (t <= 0)
            {
                ans = 0;
            }
            else
            {
                t %= mod;
                ans = ans * t % mod;
            }

            cnt[a[i]] += 1;

            cout<<ans<<' ';
        }
        cout<<endl;
    }

    return 0;
}
