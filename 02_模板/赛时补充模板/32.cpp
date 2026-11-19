#include <bits/stdc++.h>
using namespace std;

struct Centroid
{
    int n;
    long long K, ans = 0;
    vector<vector<pair<int, int>>> g;
    vector<int> sz, dead;
    Centroid(int n, long long K)
        : n(n), K(K), g(n), sz(n), dead(n)
    {
    }
    int size(int u, int f)
    {
        sz[u] = 1;
        for (auto e : g[u])
            if (e.first != f && !dead[e.first])
                sz[u] += size(e.first, u);
        return sz[u];
    }
    int center(int u, int f, int total)
    {
        for (auto e : g[u])
            if (e.first != f && !dead[e.first] &&
                sz[e.first] > total / 2)
                return center(e.first, u, total);
        return u;
    }
    void collect(int u, int f, long long d, vector<long long> &a)
    {
        a.push_back(d);
        for (auto e : g[u])
            if (e.first != f && !dead[e.first])
                collect(e.first, u, d + e.second, a);
    }
    long long count(vector<long long> &a)
    {
        sort(a.begin(), a.end());
        long long z = 0;
        for (int l = 0, r = (int)a.size() - 1; l < r;)
        {
            if (a[l] + a[r] <= K)
                z += r - l, l++;
            else
                r--;
        }
        return z;
    }
    void solve(int u)
    {
        int c = center(u, -1, size(u, -1));
        dead[c] = 1;
        vector<long long> all(1, 0);
        for (auto e : g[c])
            if (!dead[e.first])
            {
                vector<long long> a;
                collect(e.first, c, e.second, a);
                ans -= count(a);
                all.insert(all.end(), a.begin(), a.end());
            }
        ans += count(all);
        for (auto e : g[c])
            if (!dead[e.first])
                solve(e.first);
    }
}; // 每条树边双向加入；调用solve(0)，ans不包含(u,u)
