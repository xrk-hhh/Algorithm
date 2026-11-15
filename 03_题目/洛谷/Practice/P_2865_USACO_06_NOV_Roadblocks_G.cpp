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

//         vector<vector<pair<int, int>>> g(n + 1);
//         for (int i = 0; i <= m; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             g[u].push_back({v, w});
//             g[v].push_back({u, w});
//         }

//         // 第二短路问题，使用 Dijkstra变种，同时维护最短路和次短路
//         vector<ll> dist1(n + 1, INF), dist2(n + 1, INF);
//         dist1[1] = 0;
//         priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
//         pq.push({0, 1});
//         while (!pq.empty())
//         {
//             auto [d, u] = pq.top();
//             pq.pop();

//             // 当前距离大于次短路
//             if (d > dist2[u])
//             {
//                 continue;
//             }

//             for (auto [v, w] : g[u])
//             {
//                 ll nd = d + w;
//                 if (nd < dist1[v])
//                 {
//                     dist2[v] = dist1[v];
//                     dist1[v] = nd;
//                     pq.push({nd, v});
//                 }
//                 else if (nd > dist1[v] && nd < dist2[v])
//                 {
//                     dist2[v] = nd;
//                     pq.push({nd, v});
//                 }
//             }
//         }

//         cout<<dist2[n]<<endl;
//     }

//     return 0;
// }