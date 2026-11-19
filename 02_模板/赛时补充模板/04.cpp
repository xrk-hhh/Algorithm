#include <bits/stdc++.h>
using namespace std;

struct TwoSAT
{
    int n, ti = 0, bc = 0;
    vector<vector<int>> g;
    vector<int> dfn, low, stk, ins, bel, ans;
    TwoSAT(int n)
        : n(n), g(2 * n), dfn(2 * n), low(2 * n), ins(2 * n),
          bel(2 * n), ans(n)
    {
    }
    // 节点2*i+a表示命题 x_i=a；子句 (x_i=a) 或 (x_j=b)
    void add_or(int i, int a, int j, int b)
    {
        int x = 2 * i + a, y = 2 * j + b;
        g[x ^ 1].push_back(y);
        g[y ^ 1].push_back(x);
    }
    void dfs(int u)
    {
        dfn[u] = low[u] = ++ti;
        stk.push_back(u);
        ins[u] = 1;
        for (int v : g[u])
        {
            if (!dfn[v])
                dfs(v), low[u] = min(low[u], low[v]);
            else if (ins[v])
                low[u] = min(low[u], dfn[v]);
        }
        if (low[u] == dfn[u])
        {
            int v;
            do
            {
                v = stk.back();
                stk.pop_back();
                ins[v] = 0;
                bel[v] = bc;
            } while (v != u);
            bc++;
        }
    }
    bool solve()
    {
        for (int i = 0; i < 2 * n; i++)
            if (!dfn[i])
                dfs(i);
        for (int i = 0; i < n; i++)
        {
            if (bel[2 * i] == bel[2 * i + 1])
                return false;
            ans[i] = bel[2 * i + 1] < bel[2 * i];
        }
        return true;
    }
};
