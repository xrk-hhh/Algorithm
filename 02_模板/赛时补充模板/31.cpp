#include <bits/stdc++.h>
using namespace std;

bool bipartite(vector<vector<int>> &g, vector<int> &col)
{
    for (int s = 0; s < g.size(); s++)
        if (!col[s])
        {
            col[s] = 1;
            queue<int> q;
            q.push(s);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : g[u])
                    if (!col[v])
                        col[v] = 3 - col[u], q.push(v);
                    else if (col[v] == col[u])
                        return false;
            }
        }
    return true;
}
