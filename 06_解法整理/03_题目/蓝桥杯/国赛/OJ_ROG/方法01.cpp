// 原始稿：03_题目/蓝桥杯/国赛/OJ_ROG.cpp
// 原文行号：1-64；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int mod = 998244353;

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

        vector<string> g(n);
        for (int i = 0; i < n; i++)
        {
            cin>>g[i];
        }

        // 前缀和：R 的数量
        vector<vector<int>> preR(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                preR[i][j] = (preR[i - 1][j] + preR[i][j - 1] - preR[i - 1][j - 1] + (g[i - 1][j - 1] == 'R')) % mod;
            }
        }
        // 后缀和：G 的数量，从右下往左上
        vector<vector<int>> sufG(n + 2, vector<int>(m + 2, 0));
        for (int i = n; i >= 1; i--)
        {
            for (int j = m; j >= 1; j--)
            {
                sufG[i][j] = (sufG[i + 1][j] + sufG[i][j + 1] - sufG[i + 1][j + 1] + (g[i - 1][j - 1] == 'G')) % mod;
            }
        }

        ll ans = 0;
        // 枚举 O 的位置
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (g[i - 1][j - 1] == 'O')
                {
                    ans = (ans + 1LL * preR[i][j] * sufG[i][j]) % mod;
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
