// 原始稿：03_题目/蓝桥杯/国赛/luogu_imitation/T_753435_复习.cpp
// 原文行号：1-52；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        ll x, y, z;
        cin>>x>>y>>z;

        ll ans;
        if (z == 0)
        {
            ans = y + (x >= 1 ? 1 : 0);
        }
        else
        {
            ll t = (y << 1) + (z << 1) - 1;
            ll maxx = 0, maxk = min(x, z - 1);
            for (ll k = 0; k <= maxk; k++)
            {
                ll r = x - k;
                ll p = 0;
                if (r >= 1)
                {
                    p += 2;
                }
                if (r >= 2)
                {
                    p += 1;
                }

                maxx = max(maxx, k + p);
            }

            ans = t + maxx;
        }

        cout<<ans<<endl;
    }

    return 0;
}
