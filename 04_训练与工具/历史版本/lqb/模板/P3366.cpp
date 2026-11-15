// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // using ll = long long;

// // struct Edge
// // {
// //     int u, v, w;
// // };

// // bool cmp(const Edge& a, const Edge& b)
// // {
// //     return a.w < b.w;
// // }

// // // 并查集模板
// // struct DSU
// // {
// //     vector<int> fa, sz;
// //     DSU(int n)
// //     {
// //         fa.resize(n + 1);
// //         sz.resize(n + 1, 1);
// //         for (int i = 1; i <= n; i++)
// //         {
// //             fa[i] = i;
// //         }
// //     }

// //     int find(int x)
// //     {
// //         return fa[x] == x ? x : fa[x] = find(fa[x]);
// //     }

// //     bool unite(int x, int y)
// //     {
// //         x = find(x), y = find(y);
// //         if (x == y)
// //         {
// //             return false;
// //         }
// //         if (sz[x] < sz[y])
// //         {
// //             swap(x, y);
// //         }
// //         fa[y] = x;
// //         sz[x] += sz[y];
// //         return true;
// //     }
// // };

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
// //         int n, m;
// //         cin>>n>>m;

// //         // 最小生成树（Kruskal算法（基于边））
// //         vector<Edge> edges(m);
// //         for (int i = 0; i < m; i++)
// //         {
// //             cin>>edges[i].u>>edges[i].v>>edges[i].w;
// //         }

// //         // 按权值升序排序
// //         sort(edges.begin(), edges.end(), cmp);

// //         DSU dsu(n);

// //         ll ans = 0;
// //         int cnt = 0;
// //         // 遍历排序后的边
// //         for (auto& e : edges)
// //         {
// //             // 边的两端点不在同一集合，则将该边加入最小生成树
// //             if (dsu.unite(e.u, e.v))
// //             {
// //                 // 累加权值
// //                 ans += e.w;
// //                 // 边数加一
// //                 cnt++;
// //                 // 图连通
// //                 if (cnt == n - 1)
// //                 {
// //                     break;
// //                 }
// //             }
// //         }

// //         // 图连通
// //         if (cnt == n - 1)
// //         {
// //             cout<<ans<<endl;
// //         }
// //         // 图不连通
// //         else
// //         {
// //             cout<<"orz"<<endl;
// //         }
// //     }

// //     return 0;
// // }


// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

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

//         // Prim 算法（基于点，优先队列优化）
//         vector<vector<pair<int, int>>> g(n + 1);
//         for (int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             g[u].push_back({v, w});
//             g[v].push_back({u, w});
//         }

//         // 每个点到当前已选集合的最小边权
//         vector<ll> dist(n + 1, 1e18);
//         vector<bool> vis(n + 1, false);
//         priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
//         dist[1] = 0;
//         pq.push({0, 1});
//         ll ans = 0;
//         int cnt = 0;
//         while (!pq.empty())
//         {
//             auto [d, u] = pq.top();
//             pq.pop();

//             if (vis[u])
//             {
//                 continue;
//             }
//             vis[u] = true;
//             // 累加边权
//             ans += d;
//             // 点数加一
//             cnt++;
//             for (auto [v, w] : g[u])
//             {
//                 if (!vis[v] && dist[v] > w)
//                 {
//                     dist[v] = w;
//                     pq.push({dist[v], v});
//                 }
//             }
//         }

//         // 图连通
//         if (cnt == n)
//         {
//             cout<<ans<<endl;
//         }
//         // 图不连通
//         else
//         {
//             cout<<"orz"<<endl;
//         }
//     }

//     // 通常，如果边数小于 10^5，Kruskal 足够；
//     // 如果边数接近完全图（如 10^5 个点，边数 10^7），则应使用 Prim（或使用 Kruskal 加快速读入，但排序可能成为瓶颈）。

//     return 0;
// }