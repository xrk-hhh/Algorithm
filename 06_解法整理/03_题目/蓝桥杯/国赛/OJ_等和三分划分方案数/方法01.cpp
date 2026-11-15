// 原始稿：03_题目/蓝桥杯/国赛/OJ_等和三分划分方案数.cpp
// 原文行号：1-58；恢复外层注释 1 层；保留方法内部注释。
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

        vector<ll> a(n + 1);
        vector<ll> pre(n + 1, 0);
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
            sum += a[i];
            pre[i] = pre[i - 1] + a[i];
        }

        if (sum % 3 != 0)
        {
            cout<<0<<endl;
            return 0;
        }

        ll tar = sum / 3;
        ll cnt1 = 0, ans = 0;
        // 枚举 j 从 1 到 n-1，确保第三段非空
        for (int i = 1; i < n; i++)
        {
            // 当 当前位置的前缀和等于 2*tar 时，累加前面 tar 的个数
            if (pre[i] == (tar << 1))
            {
                ans += cnt1;
            }

            // 更新 tar 的个数
            if (pre[i] == tar)
            {
                cnt1++;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
