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

//     // int size(int x)
//     // {
//     //     return sz[find(x)];
//     // }

//     // bool same(int x, int y)
//     // {
//     //     return find(x) == find(y);
//     // }
// };

// struct Edge
// {
//     int u, v, w;
//     bool operator<(const Edge& other) const
//     {
//         return w < other.w;
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
//         int n, m, l, r;
//         cin>>n>>m>>l>>r;

//         DSU dsu(n);
//         vector<Edge> edge(m);
//         for (int i = 0; i < m; i++)
//         {
//             cin>>edge[i].u>>edge[i].v>>edge[i].w;
//         }

//         sort(edge.begin(), edge.end());

//         ll ans = 0;
//         for (int i = 0; i < m; i++)
//         {
//             int u = edge[i].u, v = edge[i].v, w = edge[i].w;
//             // 基础边，直接合并
//             if (w < l)
//             {
//                 dsu.unite(u, v);
//             }
//             else if (w <= r)
//             {
//                 int uu = dsu.find(u), vv = dsu.find(v);
//                 if (uu != vv)
//                 {
//                     // 这些点对的最小路径最大值恰好为 w
//                     ans += 1LL * dsu.sz[uu] * dsu.sz[vv];
//                     dsu.unite(uu, vv);
//                 }
//             }
//             // 之后的边权都大于R，不会产生满足条件的点对
//             else
//             {
//                 break;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }