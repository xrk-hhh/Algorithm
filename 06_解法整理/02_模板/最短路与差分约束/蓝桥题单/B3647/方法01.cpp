// 原始稿：02_模板/最短路与差分约束/蓝桥题单/B3647.cpp
// 原文行号：1-62；恢复外层注释 1 层；保留方法内部注释。
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
        int n, m;
        cin>>n>>m;

        // Floyd（无向图，有重边）
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
        for (int i = 1; i <= n; i++)
        {
            dist[i][i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;

            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout<<dist[i][j]<<' ';
            }
            cout<<endl;
        }
    }

    return 0;
}
