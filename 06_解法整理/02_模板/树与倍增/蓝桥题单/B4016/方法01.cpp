// 原始稿：02_模板/树与倍增/蓝桥题单/B4016.cpp
// 原文行号：1-85；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int n;
vector<vector<int>> g;
vector<int> bfs(int start)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (dist[v] == - 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        cin>>n;
        g.resize(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin>>u>>v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        // 两次BFS，先找到离随便一个点最远的点
        auto dist1 = bfs(1);
        int maxx = 0, idx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist1[i] != -1)
            {
                if (dist1[i] > maxx)
                {
                    maxx = dist1[i];
                    idx = i;
                }
            }
        }

        // 再找到距离这个点最远的点
        auto dist2 = bfs(idx);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist2[i] != -1)
            {
                ans = max(ans, dist2[i]);
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
