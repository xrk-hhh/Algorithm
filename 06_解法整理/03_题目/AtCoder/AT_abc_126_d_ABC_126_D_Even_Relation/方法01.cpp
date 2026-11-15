// 原始稿：03_题目/AtCoder/AT_abc_126_d_ABC_126_D_Even_Relation.cpp
// 原文行号：1-56；恢复外层注释 1 层；保留方法内部注释。
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

        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;

            g[u].push_back({v, w % 2});
            g[v].push_back({u, w % 2});
        }

        vector<int> col(n + 1, -1);
        queue<int> q;
        col[1] = 0;
        q.push(1);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto binding_value_01 : g[u])
            {
                auto v = binding_value_01.first;
                auto w = binding_value_01.second;
                if (col[v] == -1)
                {
                    col[v] = col[u] ^ w;
                    q.push(v);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout<<col[i]<<endl;
        }
    }

    return 0;
}
