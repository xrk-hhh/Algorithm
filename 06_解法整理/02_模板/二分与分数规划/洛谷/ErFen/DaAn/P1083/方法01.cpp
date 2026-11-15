// 原始稿：02_模板/二分与分数规划/洛谷/ErFen/DaAn/P1083.cpp
// 原文行号：1-76；恢复外层注释 1 层；保留方法内部注释。
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
        cin>>n>>m;

        vector<int> r(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>r[i];
        }

        vector<int> d(m + 1), s(m + 1), t(m + 1);
        for (int i = 1; i <= m; i++)
        {
            cin>>d[i]>>s[i]>>t[i];
        }

        auto check = [&](int x) -> bool
        {
            vector<ll> cnt(n + 2);
            for (int i = 1; i <= x; i++)
            {
                cnt[s[i]] += d[i];
                cnt[t[i] + 1] -= d[i];
            }

            for (int i = 1; i <= n; i++)
            {
                cnt[i] += cnt[i - 1];
                if (cnt[i] > r[i])
                {
                    return false;
                }
            }
            return true;
        };

        if (check(m))
        {
            cout<<0<<endl;
            return 0;
        }

        int ml = 0, mr = m + 1;
        while (ml + 1 < mr)
        {
            int mid = (ml + mr) >> 1;
            if (check(mid))
            {
                ml = mid;
            }
            else
            {
                mr = mid;
            }
        }

        cout<<-1<<endl<<mr<<endl;
    }

    return 0;
}
