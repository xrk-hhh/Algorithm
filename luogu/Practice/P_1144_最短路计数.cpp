// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 1e5 + 3;

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

//         vector<vector<int>> g(n + 1);
//         for (int i = 0; i < m; i++)
//         {
//             int u, v;
//             cin>>u>>v;

//             g[u].push_back(v);
//             g[v].push_back(u);
//         }

//         // 最短路距离
//         vector<int> dist(n + 1, -1);
//         // 最短路条数
//         vector<int> cnt(n + 1, 0);
//         queue<int> q;
//         dist[1] = 0;
//         cnt[1] = 1;
//         q.push(1);
//         while (!q.empty())
//         {
//             int u = q.front();
//             q.pop();

//             for (int v : g[u])
//             {
//                 // 未达过，更新距离和条数
//                 if (dist[v] == -1)
//                 {
//                     dist[v] = dist[u] + 1;
//                     cnt[v] = cnt[u];
//                     q.push(v);
//                 }
//                 // 距离相等，则累加条数
//                 else if (dist[v] == dist[u] + 1)
//                 {
//                     cnt[v] = (cnt[v] + cnt[u]) % mod;
//                 }
//             }
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             cout<<cnt[i]<<endl;
//         }
//     }

//     return 0;
// }