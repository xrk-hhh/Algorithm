// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define fi first
// #define se second

// struct DSU
// {
//     vector<int> par, sz;
//     int cnt;
//     int d;

//     DSU(int n, int d1) : par(n), sz(n, 0), cnt(0), d(d1)
//     {
//         iota(par.begin(), par.end(), 0);
//     }

//     int find(int x)
//     {
//         while (par[x] != x)
//         {
//             par[x] = par[par[x]];
//             x = par[x];
//         }
//         return x;
//     }

//     void unit(int x, int y)
//     {
//         x = find(x);
//         y = find(y);

//         if (x == y)
//         {
//             return;
//         }

//         if (sz[x] < sz[y])
//         {
//             swap(x, y);
//         }

//         int c1, c2;
//         if (sz[x] >= d)
//         {
//             c1 = 1;
//         }
//         else
//         {
//             c1 = 0;
//         }

//         if (sz[y] >= d)
//         {
//             c2 = 1;
//         }
//         else
//         {
//             c2 = 0;
//         }

//         par[y] = x;
//         sz[x] += sz[y];

//         int c;
//         if (sz[x] >= d)
//         {
//             c = 1;
//         }
//         else
//         {
//             c = 0;
//         }

//         cnt = cnt - c1 - c2 + c;
//     }

//     void add(int u)
//     {
//         sz[u] = 1;
//         if (d <= 1)
//         {
//             cnt++;
//         }
//     }

//     bool act(int u) const 
//     {
//         return sz[u] != 0;
//     }
// };

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m, x, d;
//         cin>>n>>m>>x>>d;

//         vector<int> h(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>h[i];
//         }

//         vector<vector<int>> adj(n);
//         for (int i = 0; i < m; i++)
//         {
//             int u, v;
//             cin>>u>>v;

//             adj[u - 1].push_back(v - 1);
//             adj[v - 1].push_back(u - 1);
//         }

//         vector<int> H(x);
//         for (int i = 0; i < x; i++)
//         {
//             cin>>H[i];
//         }

//         vector<pair<int, int>> ct;
//         for (int i = 0; i < n; i++)
//         {
//             ct.emplace_back(h[i], i);
//         }

//         sort(ct.begin(), ct.end(), greater<>());

//         vector<pair<int, int>> qs;
//         for (int i = 0; i < x; i++)
//         {
//             qs.emplace_back(H[i], i);
//         }

//         sort(qs.begin(), qs.end(), greater<>());

//         DSU dsu(n, d);
//         vector<int> ans(x);
//         int ptr = 0;

//         for (auto [cur, idx] : qs)
//         {
//             while (ptr < n && ct[ptr].fi > cur)
//             {
//                 int u = ct[ptr].se;
//                 dsu.add(u);

//                 for (int v : adj[u])
//                 {
//                     if (dsu.act(v))
//                     {
//                         dsu.unit(u, v);
//                     }
//                 }

//                 ptr++;
//             }

//             ans[idx] = dsu.cnt;
//         }

//         for (int v : ans)
//         {
//             cout<<v<<endl;
//         }
//     }

//     return 0;
// }