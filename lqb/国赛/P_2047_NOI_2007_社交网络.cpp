// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;
// // ld 提高精度
// using ld = long double;
// // 1e10 * 1e10会爆 ll，故此处用 i128
// using i128 = __int128;

// const ll INF = 1e18;

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

//         // 最短距离
//         vector<vector<ll>> d(n + 1, vector<ll>(n + 1, INF));
//         // 最短路径条数
//         vector<vector<i128>> cnt(n + 1, vector<i128>(n + 1, 0));
//         for (int i = 1; i <= n; i++)
//         {
//             d[i][i] = 0;
//         }
//         for (int i = 0; i < m; i++)
//         {
//             int u, v;
//             ll w;
//             cin>>u>>v>>w;

//             d[u][v] = d[v][u] = w;
//             cnt[u][v] = cnt[v][u] = 1;
//         }

//         // Floyd 同时计算最短距离和最短路径条数
//         for (int k = 1; k <= n; k++)
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 for (int j = 1; j <= n; j++)
//                 {
//                     if (d[i][k] != INF && d[k][j] != INF)
//                     {
//                         ll nd = d[i][k] + d[k][j];
//                         if (nd < d[i][j])
//                         {
//                             d[i][j] = nd;
//                             cnt[i][j] = cnt[i][k] * cnt[k][j];
//                         }
//                         else if (nd == d[i][j])
//                         {
//                             cnt[i][j] += cnt[i][k] * cnt[k][j];
//                         }
//                     }
//                 }
//             }
//         }

//         // 计算每个节点的重要程度
//         for (int v = 1; v <= n; v++)
//         {
//             ld ans = 0.0;
//             for (int s = 1; s <= n; s++)
//             {
//                 if (s == v)
//                 {
//                     continue;
//                 }

//                 for (int t = 1; t <= n; t++)
//                 {
//                     if (t == v || t == s)
//                     {
//                         continue;
//                     }

//                     if (d[s][v] + d[v][t] == d[s][t])
//                     {
//                         i128 tot = cnt[s][v] * cnt[v][t];
//                         ans += (ld)tot / (ld)cnt[s][t];
//                     }
//                 }
//             }

//             cout<<fixed<<setprecision(3)<<ans<<endl;
//         }
//     }

//     return 0;
// }