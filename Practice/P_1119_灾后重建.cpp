// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int INF = 1e9;

// vector<int> t;

// bool cmp(const int& a, const int& b)
// {
//     return t[a] < t[b];
// }

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

//         t.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>t[i];
//         }

//         vector<vector<int>> dist(n, vector<int>(n, INF));
//         for (int i = 0; i < n; i++)
//         {
//             dist[i][i] = 0;
//         }
//         for (int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             dist[u][v] = dist[v][u] = w;
//         }

//         // 村庄按重建时间排序，并记录原始索引
//         vector<int> order(n);
//         iota(order.begin(), order.end(), 0);
//         sort(order.begin(), order.end(), cmp);

//         int q;
//         cin>>q;

//         // 当前已加入的村庄索引
//         int idx = 0;
//         while (q--)
//         {
//             int x, y, tt;
//             cin>>x>>y>>tt;

//             // 将重建时间 <= tt 的村庄加入作为中间点
//             while (idx < n && t[order[idx]] <= tt)
//             {
//                 int k = order[idx];
//                 // 用 k 作为中间点更新最短路径
//                 for (int i = 0; i < n; i++)
//                 {
//                     for (int j = 0; j < n; j++)
//                     {
//                         if (dist[i][k] + dist[k][j] < dist[i][j])
//                         {
//                             dist[i][j] = dist[i][k] + dist[k][j];
//                         }
//                     }
//                 }
//                 idx++;
//             }

//             // 检查起点和终点是否已重建
//             if (t[x] > tt || t[y] > tt || dist[x][y] == INF)
//             {
//                 cout<<-1<<endl;
//             }
//             else
//             {
//                 cout<<dist[x][y]<<endl;
//             }
//         }
//     }

//     return 0;
// }