// 原始稿：03_题目/蓝桥杯/国赛/luogu_imitation/T_746895_商店.cpp
// 原文行号：1-87；恢复外层注释 1 层；保留方法内部注释。
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
        int n, m, P;
        cin>>n>>m>>P;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }

        vector<vector<pair<int, int>>> t(n + 1);
        for (int i = 0; i < m; i++)
        {
            int x, y, k;
            cin>>x>>y>>k;

            t[x].push_back({y, k});
        }

        vector<vector<int>> dp(n + 1, vector<int>(P + 1, 0));
        vector<int> ans(n + 1, 0);
        vector<vector<int>> b(P + 1);
        for (int u = 1; u <= n; u++)
        {
            if (a[u] <= P)
            {
                dp[u][a[u]] = 1;
                ans[u] = (ans[u] + 1) % mod;
                b[a[u]].push_back(u);
            }
        }

        for (int c = 0; c <= P; c++)
        {
            for (int u : b[c])
            {
                int vv = dp[u][c];
                if (vv == 0)
                {
                    continue;
                }

                for (auto binding_value_01 : t[u])
                {
                    auto v = binding_value_01.first;
                    auto k = binding_value_01.second;
                    int nc = c + k;
                    if (nc > P)
                    {
                        continue;
                    }

                    int pre = dp[v][nc];
                    dp[v][nc] = (pre + vv) % mod;
                    ans[v] = (ans[v] + vv) % mod;

                    if (pre == 0 && dp[v][nc] != 0)
                    {
                        b[nc].push_back(v);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout<<ans[i]<<endl;
        }
    }

    return 0;
}
