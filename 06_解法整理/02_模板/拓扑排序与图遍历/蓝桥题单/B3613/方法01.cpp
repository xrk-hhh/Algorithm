// 原始稿：02_模板/拓扑排序与图遍历/蓝桥题单/B3613.cpp
// 原文行号：1-46；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
    using namespace std;

    #define endl '\n'
    using ll = long long;

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T = 1;
        cin>>T;

        while (T--)
        {
            int n, m;
            cin>>n>>m;

            // 图的存储与出边的排序
            vector<vector<int>> g(n + 1);
            for (int i = 0; i < m; i++)
            {
                int u, v;
                cin>>u>>v;

                g[u].push_back(v);
            }

            for (int i = 1; i <= n; i++)
            {
                sort(g[i].begin(), g[i].end());
            }

            for (int i = 1; i <= n; i++)
            {
                for (int v : g[i])
                {
                    cout<<v<<" ";
                }
                cout<<endl;
            }
        }

        return 0;
    }
