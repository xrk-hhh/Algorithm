// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MOD = 998244353;
// const int MAXN = 300010;
// const int LOG = 20;

// int n, m;
// vector<int> adj[MAXN];
// int dep[MAXN], parent[MAXN];
// int f[MAXN][51];
// int fa[MAXN][LOG];

// void bfs()
// {
//     queue<int> q;
//     q.push(1);
//     dep[1] = 0;
//     parent[1] = 0;

//     for (int k = 1; k <= 50; k++)
//     {
//         f[1][k] = 0;
//     }

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         for (int v : adj[u])
//         {
//             if (v == parent[u])
//             {
//                 continue;
//             }

//             parent[v] = u;
//             dep[v] = dep[u] + 1;
//             int d = dep[v];

//             ll pow = 1;
//             for (int k = 1; k <= 50; k++)
//             {
//                 pow = pow * d % MOD;
//                 f[v][k] = (f[u][k] + pow) % MOD;
//             }
//             q.push(v);
//         }
//     }
// }

// void preLCA()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         fa[i][0] = parent[i];
//     }

//     for (int j = 1; j < LOG; j++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             fa[i][j] = fa[fa[i][j - 1]][j - 1];
//         }
//     }
// }

// int lca(int u, int v)
// {
//     if (dep[u] < dep[v])
//     {
//         swap(u, v);
//     }

//     int diff = dep[u] - dep[v];

//     for (int j = 0; j < LOG; j++)
//     {
//         if ((diff >> j) & 1)
//         {
//             u = fa[u][j];
//         }
//     }

//     if (u == v)
//     {
//         return u;
//     }

//     for (int j = LOG - 1; j >= 0; j--)
//     {
//         if (fa[u][j] != fa[v][j])
//         {
//             u = fa[u][j];
//             v = fa[v][j];
//         }
//     }
//     return parent[u];
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n;

//         for (int i = 1; i < n; i++)
//         {
//             int u, v;
//             cin>>u>>v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         bfs();
//         preLCA();

//         cin>>m;

//         while (m--)
//         {
//             int u, v, k;
//             cin>>u>>v>>k;

//             int l = lca(u, v);
//             int pl = parent[l];

//             ll ans = (f[u][k] + f[v][k]) % MOD;
//             if (pl)
//             {
//                 ans = (ans - 2LL * f[pl][k] % MOD + MOD) % MOD;
//             }

//             ll val = 1;
//             int d = dep[l];
//             for (int i = 1; i <= k; i++)
//             {
//                 val = val * d % MOD;
//             }

//             ans = (ans - val + MOD) % MOD;

//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }