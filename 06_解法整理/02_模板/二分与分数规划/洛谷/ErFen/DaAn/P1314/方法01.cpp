// 原始稿：02_模板/二分与分数规划/洛谷/ErFen/DaAn/P1314.cpp
// 原文行号：1-82；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, m;
        ll s;
        cin>>n>>m>>s;


        vector<int> w(n + 1), v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>w[i]>>v[i];
        }

        vector<int> l(m + 1), r(m + 1);
        for (int i = 1; i <= m; i++)
        {
            cin>>l[i]>>r[i];
        }

        ll ans = 1e18;

        auto check = [&](int W) -> bool
        {
            vector<ll> sn(n + 1), sv(n + 1);
            for (int i = 1; i <= n; i++)
            {
                if (w[i] >= W)
                {
                    sn[i] = sn[i - 1] + 1;
                    sv[i] = sv[i - 1] + v[i];
                }
                else
                {
                    sn[i] = sn[i - 1];
                    sv[i] = sv[i - 1];
                }
            }

            ll y = 0;
            for (int i = 1; i <= m; i++)
            {
                y += (sn[r[i]] - sn[l[i] - 1]) * (sv[r[i]] - sv[l[i] - 1]);
            }

            ans = min(ans, llabs(s - y));

            return y <= s;
        };
        
        int Wl = 0,  Wr = 1e6 + 1;
        while (Wl + 1 < Wr)
        {
            int mid = (Wl + Wr) >> 1;
            if (check(mid))
            {
                Wr = mid;
            }
            else
            {
                Wl = mid;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
