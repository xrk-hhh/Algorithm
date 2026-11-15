// 原始稿：03_题目/蓝桥杯/国赛/2026CB/P_16798_蓝桥杯_2026_国_B_Token_词元.cpp
// 原文行号：1-95；恢复外层注释 1 层；保留方法内部注释。
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

        // 经典图论建模
        // 不等关系 转 差分约束

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>p[i];
        }

        vector<int> c(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (i > 1 && p[i - 1] < p[i])
            {
                c[i]++;
            }
            if (i < n && p[i + 1] < p[i])
            {
                c[i]++;
            }
        }

        // 建一个有向无环图(DAG)
        vector<vector<int>> g(n + 1);
        vector<int> indeg(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            if (c[i] < c[i + 1])
            {
                g[i].push_back(i + 1);
                indeg[i + 1]++;
            }
            else if (c[i] > c[i + 1])
            {
                g[i + 1].push_back(i);
                indeg[i]++;
            }
        }

        // 拓扑排序 + dp
        vector<int> dp(n + 1, 1);
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : g[u])
            {
                dp[v] = max(dp[v], dp[u] + 1);
                if (--indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += dp[i];
        }

        cout<<ans<<endl;
    }

    return 0;
}
