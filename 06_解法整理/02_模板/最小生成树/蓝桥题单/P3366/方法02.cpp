// 原始稿：02_模板/最小生成树/蓝桥题单/P3366.cpp
// 原文行号：114-192；恢复外层注释 2 层；保留方法内部注释。
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

        // Prim 算法（基于点，优先队列优化）
        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;

            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        // 每个点到当前已选集合的最小边权
        vector<ll> dist(n + 1, 1e18);
        vector<bool> vis(n + 1, false);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        dist[1] = 0;
        pq.push({0, 1});
        ll ans = 0;
        int cnt = 0;
        while (!pq.empty())
        {
            auto binding_value_01 = pq.top();
            auto d = binding_value_01.first;
            auto u = binding_value_01.second;
            pq.pop();

            if (vis[u])
            {
                continue;
            }
            vis[u] = true;
            // 累加边权
            ans += d;
            // 点数加一
            cnt++;
            for (auto binding_value_02 : g[u])
            {
                auto v = binding_value_02.first;
                auto w = binding_value_02.second;
                if (!vis[v] && dist[v] > w)
                {
                    dist[v] = w;
                    pq.push({dist[v], v});
                }
            }
        }

        // 图连通
        if (cnt == n)
        {
            cout<<ans<<endl;
        }
        // 图不连通
        else
        {
            cout<<"orz"<<endl;
        }
    }

    // 通常，如果边数小于 10^5，Kruskal 足够；
    // 如果边数接近完全图（如 10^5 个点，边数 10^7），则应使用 Prim（或使用 Kruskal 加快速读入，但排序可能成为瓶颈）。

    return 0;
}
