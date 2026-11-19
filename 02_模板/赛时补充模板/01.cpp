#include <bits/stdc++.h>
using namespace std;

struct Dinic
{
    struct E
    {
        int v, rev;
        long long c;
    };
    vector<vector<E>> g;
    vector<int> lv, it;
    Dinic(int n) : g(n), lv(n), it(n) {}
    void add(int u, int v, long long c)
    {
        int a = g[u].size(), b = g[v].size();
        g[u].push_back({v, b + (u == v), c});
        g[v].push_back({u, a, 0});
    }
    bool bfs(int s, int t)
    {
        fill(lv.begin(), lv.end(), -1);
        queue<int> q;
        q.push(s);
        lv[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &e : g[u])
                if (e.c && lv[e.v] < 0)
                    lv[e.v] = lv[u] + 1, q.push(e.v);
        }
        return lv[t] >= 0;
    }
    long long dfs(int u, int t, long long f)
    {
        if (u == t)
            return f;
        for (int &i = it[u]; i < (int)g[u].size(); i++)
        {
            E &e = g[u][i];
            if (e.c && lv[e.v] == lv[u] + 1)
            {
                long long z = dfs(e.v, t, min(f, e.c));
                if (z)
                {
                    e.c -= z;
                    g[e.v][e.rev].c += z;
                    return z;
                }
            }
        }
        return 0;
    }
    long long flow(int s, int t)
    {
        long long ans = 0, z;
        while (bfs(s, t))
        {
            fill(it.begin(), it.end(), 0);
            while ((z = dfs(s, t, LLONG_MAX / 4)))
                ans += z;
        }
        return ans;
    }
}; // 顶点从0开始；s!=t；结束后lv>=0的顶点为最小割源点侧
