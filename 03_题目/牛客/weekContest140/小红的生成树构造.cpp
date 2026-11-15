// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 并查集模板
// struct DSU
// {
//     vector<int> fa, sz;
//     DSU(int n)
//     {
//         fa.resize(n + 1);
//         sz.resize(n + 1, 1);
//         for (int i = 1; i <= n; i++)
//         {
//             fa[i] = i;
//         }
//     }

//     int find(int x)
//     {
//         return fa[x] == x ? x : fa[x] = find(fa[x]);
//     }

//     bool unite(int x, int y)
//     {
//         x = find(x), y = find(y);
//         if (x == y)
//         {
//             return false;
//         }

//         if (sz[x] < sz[y])
//         {
//             swap(x, y);
//         }
//         fa[y] = x;
//         sz[x] += sz[y];
//         return true;
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
//         int n, m;
//         cin>>n>>m;

//         string s;
//         cin>>s;

//         vector<vector<int>> g(n + 1);
//         for (int i = 0; i < m; i++)
//         {
//             int u, v;
//             cin>>u>>v;

//             g[u].push_back(v);
//             g[v].push_back(u);
//         }

//         // 检查 A/B 子图的连通分量是否都包含 A 和 B
//         vector<int> comp(n + 1, -1);
//         int cnt = 0;
//         vector<bool> hasA, hasB;
//         for (int i = 1; i <= n; i++)
//         {
//             if ((s[i - 1] == 'A' || s[i - 1] == 'B') && comp[i] == -1)
//             {
//                 queue<int> q;
//                 q.push(i);
//                 comp[i] = cnt;
//                 bool a = false, b = false;
//                 while (!q.empty())
//                 {
//                     int u = q.front();
//                     q.pop();

//                     if (s[u - 1] == 'A')
//                     {
//                         a = true;
//                     }
//                     if (s[u - 1] == 'B')
//                     {
//                         b = true;
//                     }

//                     for (int v : g[u])
//                     {
//                         if ((s[v - 1] == 'A' || s[v - 1] == 'B') && comp[v] == -1)
//                         {
//                             comp[v] = cnt;
//                             q.push(v);
//                         }
//                     }
//                 }
//                 hasA.push_back(a);
//                 hasB.push_back(b);
//                 cnt++;
//             }
//         }

//         for (int i = 0; i < cnt; i++)
//         {
//             if (!hasA[i] || !hasB[i])
//             {
//                 cout<<"No"<<endl;
//                 return 0;
//             }
//         }

//         // 检查 C/D 子图的连通分量是否都包含 C 和 D
//         comp.assign(n + 1, -1);
//         cnt = 0;
//         vector<bool> hasC, hasD;
//         for (int i = 1; i <= n; i++)
//         {
//             if ((s[i - 1] == 'C' || s[i - 1] == 'D') && comp[i] == -1)
//             {
//                 queue<int> q;
//                 q.push(i);
//                 comp[i] = cnt;
//                 bool c = false, d = false;
//                 while (!q.empty())
//                 {
//                     int u = q.front();
//                     q.pop();

//                     if (s[u - 1] == 'C')
//                     {
//                         c = true;
//                     }
//                     if (s[u - 1] == 'D')
//                     {
//                         d = true;
//                     }

//                     for (int v : g[u])
//                     {
//                         if ((s[v - 1] == 'C' || s[v - 1] == 'D') && comp[v] == -1)
//                         {
//                             comp[v] = cnt;
//                             q.push(v);
//                         }
//                     }
//                 }
//                 hasC.push_back(c);
//                 hasD.push_back(d);
//                 cnt++;
//             }
//         }

//         for (int i = 0; i < cnt; i++)
//         {
//             if (!hasC[i] || !hasD[i])
//             {
//                 cout<<"No"<<endl;
//                 return 0;
//             }
//         }

//         // 构造生成树
//         DSU dsu(n);
//         vector<pair<int, int>> edges;
//         // 首先在 A/B 子图中添加边，使每个分量内连通
//         vector<bool> vis(n + 1, false);
//         for (int i = 1; i <= n; i++)
//         {
//             if (s[i - 1] == 'A' || s[i - 1] == 'B')
//             {
//                 if (vis[i])
//                 {
//                     continue;
//                 }

//                 queue<int> q;
//                 q.push(i);
//                 vis[i] = true;
//                 while (!q.empty())
//                 {
//                     int u = q.front();
//                     q.pop();

//                     for (int v : g[u])
//                     {
//                         if ((s[v - 1] == 'A' || s[v - 1] == 'B') && !vis[v])
//                         {
//                             vis[v] = true;
//                             q.push(v);
//                             if (dsu.unite(u, v))
//                             {
//                                 edges.push_back({u, v});
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         // 然后在 C/D 子图中添加边，使每个分量内连通
//         for (int i = 1; i <= n; i++)
//         {
//             if (s[i - 1] == 'C' || s[i - 1] == 'D')
//             {
//                 if (vis[i])
//                 {
//                     continue;
//                 }

//                 queue<int> q;
//                 q.push(i);
//                 vis[i] = true;
//                 while (!q.empty())
//                 {
//                     int u = q.front();
//                     q.pop();

//                     for (int v : g[u])
//                     {
//                         if ((s[v - 1] == 'C' || s[v - 1] == 'D') && !vis[v])
//                         {
//                             vis[v] = true;
//                             q.push(v);
//                             if (dsu.unite(u, v))
//                             {
//                                 edges.push_back({u, v});
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         // 最后添加剩余的边（包括跨类型边）直到形成生成树
//         for (int u = 1; u <= n; u++)
//         {
//             for (int v : g[u])
//             {
//                 if (u < v && dsu.unite(u, v))
//                 {
//                     edges.push_back({u, v});
//                 }
//             }
//         }

//         cout<<"Yes"<<endl;
//         for (auto [u, v] : edges)
//         {
//             cout<<u<<' '<<v<<endl;
//         }
//     }

//     return 0;
// }