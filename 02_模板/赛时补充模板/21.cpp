#include <bits/stdc++.h>
using namespace std;

vector<int> bfs01(int s, const vector<vector<pair<int, int>>> &g)
{
    const int INF = 1e9;
    vector<int> d(g.size(), INF), done(g.size());
    deque<int> q;
    d[s] = 0;
    q.push_front(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        if (done[u])
            continue;
        done[u] = 1;
        for (auto e : g[u])
            if (d[e.first] > d[u] + e.second)
            {
                d[e.first] = d[u] + e.second;
                if (e.second)
                    q.push_back(e.first);
                else
                    q.push_front(e.first);
            }
    }
    return d;
} // e.first为终点，e.second只允许0或1
