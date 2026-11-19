#include <bits/stdc++.h>
using namespace std;

struct Cut
{
    int n, tim = 0;
    vector<vector<pair<int, int>>> g;
    vector<int> dfn, low, cut;
    vector<pair<int, int>> bridge;
    vector<vector<int>> blocks;
    vector<int> st;
    Cut(int n) : n(n), g(n), dfn(n), low(n), cut(n) {}
    void add(int u, int v, int id)
    {
        g[u].push_back({v, id});
        g[v].push_back({u, id});
    }
    void dfs(int u, int pe)
    {
        dfn[u] = low[u] = ++tim;
        st.push_back(u);
        int son = 0;
        for (auto e : g[u])
        {
            int v = e.first, id = e.second;
            if (id == pe)
                continue; // 用边编号跳父边，允许重边
            if (!dfn[v])
            {
                son++;
                dfs(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    bridge.push_back({u, v});
                if (low[v] >= dfn[u])
                {
                    if (pe != -1 || son > 1)
                        cut[u] = 1;
                    vector<int> b;
                    int x;
                    do
                    {
                        x = st.back();
                        st.pop_back();
                        b.push_back(x);
                    } while (x != v);
                    b.push_back(u);
                    blocks.push_back(b);
                }
            }
            else
                low[u] = min(low[u], dfn[v]);
        }
        if (pe == -1 && g[u].empty())
            blocks.push_back({u});
    }
    void run()
    {
        for (int u = 0; u < n; u++)
            if (!dfn[u])
            {
                dfs(u, -1);
                st.clear();
            }
    }
}; // 无自环无向图；blocks是点双连通分量，桥单独构成二点分量
