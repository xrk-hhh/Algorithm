// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 注意不能写 1 << 31 - 1，这样相当于 1 << (31 - 1)
// const int INF = (1 << 31) - 1;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m, s;
//         cin>>n>>m>>s;

//         vector<vector<pair<int, int>>> g(n + 1);
//         for (int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             // 有向边
//             g[u].push_back({v, w});
//         }

//         // Dijkstra板子
//         vector<int> dist(n + 1, INF);
//         dist[s] = 0;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         pq.push({0, s});
//         while (!pq.empty())
//         {
//             auto [d, u] = pq.top();
//             pq.pop();

//             if (d != dist[u])
//             {
//                 continue;
//             }

//             for (auto [v, w] : g[u])
//             {
//                 if (dist[v] > dist[u] + w)
//                 {
//                     dist[v] = dist[u] + w;
//                     pq.push({dist[v], v});
//                 }
//             }
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             cout<<dist[i]<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }