// 原始稿：03_题目/洛谷/Practice/P_1807_最长路.cpp
// 原文行号：1-90；恢复外层注释 1 层；保留方法内部注释。
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
        int n, m;
        cin>>n>>m;

        vector<vector<pair<int, int>>> g(n + 1);
        // 入度
        vector<int> indeg(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;

            g[u].push_back({v, w});
            indeg[v]++;
        }

        // 拓扑排序
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            topo.push_back(u);
            for (auto binding_value_01 : g[u])
            {
                auto v = binding_value_01.first;
                auto w = binding_value_01.second;
                if (--indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // 动态规划求最长路径
        vector<ll> dist(n + 1, -INF);
        dist[1] = 0;
        for (int u : topo)
        {
            // 不可达，跳过
            if (dist[u] == -INF)
            {
                continue;
            }

            for (auto binding_value_02 : g[u])
            {
                auto v = binding_value_02.first;
                auto w = binding_value_02.second;
                if (dist[v] < dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        if (dist[n] == -INF)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<dist[n]<<endl;
        }
    }

    return 0;
}
