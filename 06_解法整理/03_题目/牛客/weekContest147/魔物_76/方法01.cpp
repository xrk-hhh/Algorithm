// 原始稿：03_题目/牛客/weekContest147/魔物_76.cpp
// 原文行号：1-57；恢复外层注释 1 层；保留方法内部注释。
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
        int n, q;
        cin>>n>>q;

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }

        vector<int> d(n);
        ll sum = 0;
        for (int i = 1; i < n; i++)
        {
            d[i] = ((a[i + 1] - a[i]) % 5 + 5) % 5;
            sum += d[i];
        }

        while (q--)
        {
            int l, r;
            cin>>l>>r;

            if (l > 1)
            {
                int t1 = d[l - 1];
                d[l - 1] = (d[l - 1] + 1) % 5;
                sum += d[l - 1] - t1;
            }
            if (r < n)
            {
                int t2 = d[r];
                d[r] = ((d[r] - 1) % 5 + 5) % 5;
                sum += d[r] - t2;
            }

            cout<<sum<<endl;
        }
    }

    return 0;
}
