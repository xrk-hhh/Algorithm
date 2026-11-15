// 原始稿：02_模板/背包与动态规划/蓝桥题单/P1115.cpp
// 原文行号：1-46；恢复外层注释 1 层；保留方法内部注释。
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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        // 最大子段和
        ll ans = a[0];
        ll cur = a[0];
        for (int i = 1; i < n; i++)
        {
            if (cur + a[i] > a[i])
            {
                cur += a[i];
            }
            else
            {
                cur = a[i];
            }
            ans = max(ans, cur);
        }

        cout<<ans<<endl;
    }

    return 0;
}
