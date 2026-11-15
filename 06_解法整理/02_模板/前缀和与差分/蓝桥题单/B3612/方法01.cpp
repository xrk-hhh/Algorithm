// 原始稿：02_模板/前缀和与差分/蓝桥题单/B3612.cpp
// 原文行号：1-48；恢复外层注释 1 层；保留方法内部注释。
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
        int n;
        cin>>n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }

        // 求区间和
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + a[i];
        }

        int m;
        cin>>m;

        while (m--)
        {
            int l, r;
            cin>>l>>r;

            int ans = pre[r] - pre[l - 1];

            cout<<ans<<endl;
        }
    }

    return 0;
}
