// 原始稿：03_题目/蓝桥杯/贪心/P12218.cpp
// 原文行号：1-39；恢复外层注释 1 层；保留方法内部注释。
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

        vector<int> w(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin>>w[i];
        }

        sort(w.begin(), w.end());

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            // 记得乘上 1LL
            ans += 1LL * w[i] * w[2 * n - 1 - i];
        }

        cout<<ans<<endl;
    }

    return 0;
}
