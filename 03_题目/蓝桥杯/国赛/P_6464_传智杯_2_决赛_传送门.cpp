// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

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

//         vector<vector<ll>> d(n + 1, vector<ll>(n + 1, INF));
//         for (int i = 1; i <= n; i++)
//         {
//             d[i][i] = 0;
//         }
//         for (int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             d[u][v] = d[v][u] = w;
//         }

//         // Floyd
//         for (int k = 1; k <= n; k++)
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 for (int j = 1; j <= n; j++)
//                 {
//                     if (d[i][j] > d[i][k] + d[k][j])
//                     {
//                         d[i][j] = d[i][k] + d[k][j];
//                     }
//                 }
//             }
//         }

//         // 原始总和
//         ll base = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = i + 1; j <= n; j++)
//             {
//                 base += d[i][j];
//             }
//         }

//         ll ans = base;
//         // 枚举传送门
//         for (int u = 1; u <= n; u++)
//         {
//             for (int v = u + 1; v <= n; v++)
//             {
//                 ll cur = 0;
//                 for (int i = 1; i <= n; i++)
//                 {
//                     for (int j = i + 1; j <= n; j++)
//                     {
//                         ll dd = d[i][j];
//                         dd = min(dd, d[i][u] + d[v][j]);
//                         dd = min(dd, d[i][v] + d[u][j]);

//                         cur += dd;
//                     }
//                 }

//                 ans = min(ans, cur);
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }