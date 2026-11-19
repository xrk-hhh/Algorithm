#include <bits/stdc++.h>
using namespace std;

struct MCMF
{
    using ll = long long;
    struct E
    {
        int v, rev;
        ll cap, cost;
    };
    vector<vector<E>> g;
    MCMF(int n) : g(n) {}
    void add(int u, int v, ll c, ll w)
    {
        int a = g[u].size(), b = g[v].size();
        g[u].push_back({v, b + (u == v), c, w});
        g[v].push_back({u, a, 0, -w});
    }
    pair<ll, ll> run(int s, int t)
    {
        ll F = 0, C = 0, INF = LLONG_MAX / 4;
        int n = g.size();
        while (1)
        {
            vector<ll> d(n, INF);
            vector<int> pv(n), pe(n), in(n);
            queue<int> q;
            q.push(s);
            d[s] = 0;
            in[s] = 1;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                in[u] = 0;
                for (int i = 0; i < (int)g[u].size(); i++)
                {
                    E &e = g[u][i];
                    if (!e.cap || d[e.v] <= d[u] + e.cost)
                        continue;
                    d[e.v] = d[u] + e.cost;
                    pv[e.v] = u;
                    pe[e.v] = i;
                    if (!in[e.v])
                        in[e.v] = 1, q.push(e.v);
                }
            }
            if (d[t] == INF)
                break;
            ll f = INF;
            for (int v = t; v != s; v = pv[v])
                f = min(f, g[pv[v]][pe[v]].cap);
            F += f;
            C += f * d[t];
            for (int v = t; v != s; v = pv[v])
            {
                E &e = g[pv[v]][pe[v]];
                e.cap -= f;
                g[v][e.rev].cap += f;
            }
        }
        return {F, C};
    }
}; // 允许负费用边；要求初始残量网络无负费用环；s!=t
