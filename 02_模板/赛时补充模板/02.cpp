#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> mt, vis;
bool dfs_match(int u)
{
    for (int v : g[u])
        if (!vis[v])
        {
            vis[v] = 1;
            if (mt[v] == -1 || dfs_match(mt[v]))
                return mt[v] = u, true;
        }
    return false;
}
int max_match()
{
    int ans = 0;
    mt.assign(m + 1, -1);
    for (int u = 1; u <= n; u++)
    {
        vis.assign(m + 1, 0);
        ans += dfs_match(u);
    }
    return ans;
}
