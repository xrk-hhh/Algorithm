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

//         vector<vector<int>> minw(n + 1, vector<int>(n + 1, INT_MAX));
//         for (int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             // 只保留最小权值，忽略其他边
//             if (w < minw[u][v])
//             {
//                 minw[u][v] = w;
//             }
//         }

//         vector<vector<pair<int, int>>> g(n + 1);
//         for (int u = 1; u <= n; u++)
//         {
//             for (int v = 1; v <= n; v++)
//             {
//                 if (minw[u][v] != INT_MAX)
//                 {
//                     g[u].push_back({v, minw[u][v]});
//                 }
//             }
//         }

//         vector<ll> dist(n + 1, INF);
//         vector<ll> cnt(n + 1, 0);
//         dist[1] = 0;
//         cnt[1] = 1;
//         priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
//         pq.push({0, 1});
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
//                     cnt[v] = cnt[u];
//                     pq.push({dist[v], v});
//                 }
//                 else if (dist[v] == dist[u] + w)
//                 {
//                     cnt[v] += cnt[u];
//                 }
//             }
//         }

//         if (dist[n] == INF)
//         {
//             cout<<"No answer"<<endl;
//         }
//         else
//         {
//             cout<<dist[n]<<' '<<cnt[n]<<endl;
//         }
//     }

//     return 0;
// }