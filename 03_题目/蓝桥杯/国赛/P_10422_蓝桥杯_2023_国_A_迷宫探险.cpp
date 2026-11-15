// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;
// using uc = unsigned char;

// const int INF = 0x3f3f3f3f;
// // 三维 dp，为压缩空间大小，使用 uc
// const uc UCINF = 0xFF;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m, tot;
//         cin>>n>>m>>tot;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         vector<vector<int>> dist(n, vector<int>(n, INF));
//         vector<vector<bool>> adj(n, vector<bool>(n, false));
//         for (int i = 0; i < n; i++)
//         {
//             dist[i][i] = 0;
//         }
//         for (int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             // 忽略自环
//             if (u == v)
//             {
//                 continue;
//             }

//             dist[u][v] = dist[v][u] = min(dist[u][v], w);
//             // 标记邻接关系
//             adj[u][v] = adj[v][u] = true;
//         }

//         // Floyd先求出两点间最短路
//         for (int k = 0; k < n; k++)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 for (int j = 0; j < n; j++)
//                 {
//                     if (dist[i][k] + dist[k][j] < dist[i][j])
//                     {
//                         dist[i][j] = dist[i][k] + dist[k][j];
//                     }
//                 }
//             }
//         }

//         // damage[mask][v]：已击杀集合 mask，再杀 v 时受到的额外伤害
//         vector<vector<int>> damage(1 << n, vector<int>(n, 0));
//         for (int v = 0; v < n; v++)
//         {
//             for (int mask = 0; mask < (1 << n); mask++)
//             {
//                 if (mask & (1 << v))
//                 {
//                     continue;
//                 }

//                 int dmg = 0;
//                 for (int u = 0; u < n; u++)
//                 {
//                     // 忽略自环
//                     if (u == v)
//                     {
//                         continue;
//                     }

//                     // 直接相邻且存活
//                     if (adj[v][u] && !(mask & (1 << u)))
//                     {
//                         dmg += a[u];
//                     }
//                 }

//                 damage[mask][v] = dmg;
//             }
//         }

//         // dp[mask][last][t]：已杀集合 mask，最后在 last，已受伤害 t 的最短时间
//         vector<vector<vector<uc>>> dp(1 << n, vector<vector<uc>>(n, vector<uc>(tot + 1, UCINF)));

//         // 注意：
//         // 小蓝可以先移动到其他节点击杀，之后再返回杀0 
        
//         // 初始化：选择第一个击杀的节点
//         for (int i = 0; i < n; i++)
//         {
//             if (i != 0 && dist[0][i] == INF)
//             {
//                 continue;
//             }

//             int dmg = damage[0][i];
//             if (dmg < tot)
//             {
//                 int t = (i == 0) ? 0 : dist[0][i];

//                 dp[1 << i][i][dmg] = t;
//             }
//         }

//         int full = (1 << n) - 1;
//         // 更新 dp
//         for (int mask = 1; mask <= full; mask++)
//         {
//             for (int last = 0; last < n; last++)
//             {
//                 if (!(mask & (1 << last)))
//                 {
//                     continue;
//                 }

//                 for (int t = 0; t < tot; t++)
//                 {
//                     uc cur_time = dp[mask][last][t];

//                     if (cur_time == UCINF)
//                     {
//                         continue;
//                     }

//                     for (int nxt = 0; nxt < n; nxt++)
//                     {
//                         if (mask & (1 << nxt))
//                         {
//                             continue;
//                         }

//                         if (dist[last][nxt] == INF)
//                         {
//                             continue;
//                         }

//                         int nt = t + damage[mask][nxt];
//                         if (nt >= tot)
//                         {
//                             continue;
//                         }

//                         uc n_time = cur_time + dist[last][nxt];
//                         if (n_time < dp[mask | (1 << nxt)][nxt][nt])
//                         {
//                             dp[mask | (1 << nxt)][nxt][nt] = n_time;
//                         }
//                     }
//                 }
//             }
//         }

//         int ans = INF;
//         // 注意：
//         // 小蓝击杀完所有怪物后，不一定正好在 N−1 号节点
//         // 他可以从最后击杀的节点移动到 N−1（此时所有怪物已死，移动不再受伤害）
//         for (int last = 0; last < n; last++)
//         {
//             if (dist[last][n - 1] == INF)
//             {
//                 continue;
//             }

//             for (int t = 0; t < tot; t++)
//             {
//                 if (dp[full][last][t] != UCINF)
//                 {
//                     ans = min(ans, (int)dp[full][last][t] + dist[last][n - 1]);
//                 }
//             }
//         }

//         if (ans == INF)
//         {
//             cout<<-1<<endl;
//         }
//         else
//         {
//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }