#include <bits/stdc++.h>
using namespace std;

long long independent_set(const vector<vector<int>> &g,
                          const vector<int> &w, int rt = 0)
{
    int n = g.size();
    vector<int> fa(n, -1), ord(1, rt);
    for (int i = 0; i < (int)ord.size(); i++)
        for (int v : g[ord[i]])
            if (v != fa[ord[i]])
                fa[v] = ord[i], ord.push_back(v);
    vector<array<long long, 2>> f(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int u = ord[i];
        f[u][1] = w[u];
        for (int v : g[u])
            if (v != fa[u])
            {
                f[u][0] += max(f[v][0], f[v][1]);
                f[u][1] += f[v][0];
            }
    }
    return max(f[rt][0], f[rt][1]);
} // 允许空集，负权可不选；输入必须为一棵树
