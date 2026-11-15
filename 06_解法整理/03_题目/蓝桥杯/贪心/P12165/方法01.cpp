// 原始稿：03_题目/蓝桥杯/贪心/P12165.cpp
// 原文行号：1-43；恢复外层注释 1 层；保留方法内部注释。
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

        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++)
        {
            cin>>x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>y[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(x[i] - y[i]);
        }

        cout<<ans<<endl;
    }

    return 0;
}
