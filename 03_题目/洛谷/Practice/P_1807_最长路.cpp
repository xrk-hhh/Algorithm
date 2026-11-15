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
//         // 入度
//         vector<int> indeg(n + 1, 0);
//         for (int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             g[u].push_back({v, w});
//             indeg[v]++;
//         }

//         // 拓扑排序
//         queue<int> q;
//         for (int i = 1; i <= n; i++)
//         {
//             if (indeg[i] == 0)
//             {
//                 q.push(i);
//             }
//         }
//         vector<int> topo;
//         while (!q.empty())
//         {
//             int u = q.front();
//             q.pop();

//             topo.push_back(u);
//             for (auto [v, w] : g[u])
//             {
//                 if (--indeg[v] == 0)
//                 {
//                     q.push(v);
//                 }
//             }
//         }

//         // 动态规划求最长路径
//         vector<ll> dist(n + 1, -INF);
//         dist[1] = 0;
//         for (int u : topo)
//         {
//             // 不可达，跳过
//             if (dist[u] == -INF)
//             {
//                 continue;
//             }

//             for (auto [v, w] : g[u])
//             {
//                 if (dist[v] < dist[u] + w)
//                 {
//                     dist[v] = dist[u] + w;
//                 }
//             }
//         }

//         if (dist[n] == -INF)
//         {
//             cout<<-1<<endl;
//         }
//         else
//         {
//             cout<<dist[n]<<endl;
//         }
//     }

//     return 0;
// }