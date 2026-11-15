// 原始稿：02_模板/最短路与差分约束/蓝桥题单/P4779.cpp
// 原文行号：1-64；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int INF = std::numeric_limits<int>::max();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, m, s;
        cin>>n>>m>>s;

        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;

            g[u].push_back({v, w});
        }

        // Dijkstra(单源最短路径（标准版）)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INF);
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty())
        {
            auto binding_value_01 = pq.top();
            auto d = binding_value_01.first;
            auto u = binding_value_01.second;
            pq.pop();

            if (d != dist[u])
            {
                continue;
            }

            for (auto binding_value_02 : g[u])
            {
                auto v = binding_value_02.first;
                auto w = binding_value_02.second;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout<<dist[i]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
