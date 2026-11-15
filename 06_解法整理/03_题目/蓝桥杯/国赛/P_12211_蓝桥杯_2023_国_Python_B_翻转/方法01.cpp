// 原始稿：03_题目/蓝桥杯/国赛/P_12211_蓝桥杯_2023_国_Python_B_翻转.cpp
// 原文行号：1-80；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int N = 26;
const int INF = -1e9;

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

        vector<string> s(n);
        for (int i = 0; i < n; i++)
        {
            cin>>s[i];
        }

        // dp[c]：当前最后一个工件的尾字符为 c 时的最大节省次数
        vector<int> dp(N, INF);
        // 初始化第一个工件
        for (int flip = 0; flip < 2; flip++)
        {
            char first = flip ? s[0][1] : s[0][0];
            char last = flip ? s[0][0] : s[0][1];

            // 第一个工件没有前置合并
            dp[last - 'a'] = 0;
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> ndp(N, INF);

            int maxx = 0;
            for (int j = 0; j < N; j++)
            {
                maxx = max(maxx, dp[j]);
            }

            for (int flip = 0; flip < 2; flip++)
            {
                char first = flip ? s[i][1] : s[i][0];
                char last = flip ? s[i][0] : s[i][1];

                int f = first - 'a';
                int l = last - 'a';

                int best = max(maxx, dp[f] + 1);

                ndp[l] = max(ndp[l], best);
            }

            dp.swap(ndp);
        }
        

        int maxx = 0;
        for (int i = 0; i < N; i++)
        {
            maxx = max(maxx, dp[i]);
        }

        int ans = (n << 1) - maxx;

        cout<<ans<<endl;
    }

    return 0;
}
