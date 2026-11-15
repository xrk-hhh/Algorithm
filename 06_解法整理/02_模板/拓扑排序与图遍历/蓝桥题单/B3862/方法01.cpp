// 原始稿：02_模板/拓扑排序与图遍历/蓝桥题单/B3862.cpp
// 原文行号：1-60；恢复外层注释 1 层；保留方法内部注释。
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

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin>>u>>v;

            g[u].push_back(v);
        }

        // 图的遍历（简单版）
        vector<bool> vis(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            vis.assign(n + 1, false);
            int maxx = 0;
            queue<int> q;
            vis[i] = true;
            q.push(i);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                maxx = max(maxx, u);

                for (int v : g[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = true; 
                        q.push(v);
                    }
                }
            }
            cout<<maxx<<' ';
        }
        cout<<endl;
    }

    return 0;
}
