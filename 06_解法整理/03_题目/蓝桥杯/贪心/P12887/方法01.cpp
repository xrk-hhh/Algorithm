// 原始稿：03_题目/蓝桥杯/贪心/P12887.cpp
// 原文行号：1-40；恢复外层注释 1 层；保留方法内部注释。
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
        int n, m;
        cin>>n>>m;

        string s, t;
        cin>>s>>t;

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            // 两人有多少个答案相同
            if (s[i] == t[i])
            {
                cnt++;
            }
        }

        // 让相同的尽可能是朋友对的，那么最多对的数量就是 (总的 - 朋友对的但与自己不同的)
        int ans = n - abs(m - cnt);

        cout<<ans<<endl;
    }

    return 0;
}
