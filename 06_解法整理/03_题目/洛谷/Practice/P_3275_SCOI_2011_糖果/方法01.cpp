// 原始稿：03_题目/洛谷/Practice/P_3275_SCOI_2011_糖果.cpp
// 原文行号：1-145；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, k;
        cin>>n>>k;

        vector<vector<pair<int, int>>> g(n + 1);
        // 检验有无正环
        bool bad = false;
        // 转换为差分约束
        for (int i = 0; i < k; i++)
        {
            int x, a, b;
            cin>>x>>a>>b;

            if (x == 1)
            {
                // a = b
                g[a].push_back({b, 0});
                g[b].push_back({a, 0});
            }
            else if (x == 2)
            {
                if (a == b)
                {
                    bad = true;
                }
                // a < b
                g[a].push_back({b, 1});
            }
            else if (x == 3)
            {
                // a >= b
                g[b].push_back({a, 0});
            }
            else if (x == 4)
            {
                if (a == b)
                {
                    bad = true;
                }
                // a > b
                g[b].push_back({a, 1});
            }
            else if (x == 5)
            {
                // a <= b
                g[a].push_back({b, 0});
            }
        }

        if (bad)
        {
            cout<<-1<<endl;
            return 0;
        }

        // 引入超级源点 0
        vector<vector<pair<int, int>>> ng(n + 2);
        for (int i = 1; i <= n; i++)
        {
            // xi >= 1
            ng[0].push_back({i, 1});
        }
        for (int i = 1; i <= n; i++)
        {
            for (auto binding_value_01 : g[i])
            {
                auto v = binding_value_01.first;
                auto w = binding_value_01.second;
                ng[i].push_back({v, w});
            }
        }

        // SPFA，但会TLE
        int tot = n + 1;
        vector<ll> dist(tot, -INF);
        vector<int> cnt(tot, 0);
        vector<bool> inq(tot, false);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        inq[0] = true;
        cnt[0] = 1;
        bool has_cycle = false;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            inq[u] = false;
            for (auto binding_value_02 : ng[u])
            {
                auto v = binding_value_02.first;
                auto w = binding_value_02.second;
                // 最长路
                if (dist[v] < dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    if (!inq[v])
                    {
                        q.push(v);
                        inq[v] = true;
                        if (++cnt[v] > tot)
                        {
                            has_cycle = true;
                            break;
                        }
                    }
                }
            }
            if (has_cycle)
            {
                break;
            }
        }

        if (has_cycle)
        {
            cout<<-1<<endl;
            return 0;
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += dist[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}
