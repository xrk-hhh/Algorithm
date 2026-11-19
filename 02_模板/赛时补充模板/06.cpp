#include <bits/stdc++.h>
using namespace std;

struct HLD
{
    int n, tim = 0;
    vector<vector<int>> g;
    vector<int> fa, dep, sz, son, top, dfn, rk;
    HLD(int n)
        : n(n), g(n), fa(n), dep(n), sz(n), son(n, -1), top(n),
          dfn(n), rk(n)
    {
    }
    void dfs1(int u, int f)
    {
        fa[u] = f;
        sz[u] = 1;
        for (int v : g[u])
            if (v != f)
            {
                dep[v] = dep[u] + 1;
                dfs1(v, u);
                sz[u] += sz[v];
                if (son[u] == -1 || sz[v] > sz[son[u]])
                    son[u] = v;
            }
    }
    void dfs2(int u, int tp)
    {
        top[u] = tp;
        dfn[u] = tim;
        rk[tim++] = u;
        if (son[u] != -1)
            dfs2(son[u], tp);
        for (int v : g[u])
            if (v != fa[u] && v != son[u])
                dfs2(v, v);
    }
    void build(int rt = 0)
    {
        dfs1(rt, -1);
        dfs2(rt, rt);
    }
    // 对每个闭区间调用op(l,r)，接区间加/区间和等线段树
    template <class F> void path(int u, int v, F op)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
                swap(u, v);
            op(dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v])
            swap(u, v);
        op(dfn[u], dfn[v]);
    }
}; // 子树闭区间[dfn[u],dfn[u]+sz[u]-1]，本实现点权、0基下标
