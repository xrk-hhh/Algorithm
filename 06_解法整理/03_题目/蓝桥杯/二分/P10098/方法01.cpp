// 原始稿：03_题目/蓝桥杯/二分/P10098.cpp
// 原文行号：1-66；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int n;
ll p;
vector<int> z, a, b;

bool check(ll x)
{
    ll pp = 0;
    for (int i = 0; i < n; i++)
    {
        if (x <= z[i])
        {
            pp += a[i] * x;
        }
        else
        {
            pp += 1LL * a[i] * z[i] + b[i] * (x - z[i]);
        }
    }

    return pp >= p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        cin>>n>>p;
        z.resize(n);
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin>>z[i]>>a[i]>>b[i];
        }

        ll l = 0, r = 1e12;
        while (l < r)
        {
            ll mid = (l + r) >> 1;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout<<l<<endl;
    }

    return 0;
}
