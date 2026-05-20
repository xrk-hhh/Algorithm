// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int INF = 1e9;

// // SPFA 判负环
// bool spfa(int n, vector<vector<pair<int, int>>>& g)
// {
//     vector<int> dist(n + 1, INF);
//     // 出现次数
//     vector<int> cnt(n + 1, 0);
//     // 是否在队列内
//     vector<bool> inQueue(n + 1, false);
//     queue<int> q;
//     dist[1] = 0;
//     q.push(1);
//     inQueue[1] = true;

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         inQueue[u] = false;
//         for (auto& [v, w] : g[u])
//         {
//             if (dist[u] + w < dist[v])
//             {
//                 dist[v] = dist[u] + w;
//                 // 更新了dist且不在队内，则入队
//                 if (!inQueue[v])
//                 {
//                     q.push(v);
//                     inQueue[v] = true;
//                     // 出现次数，即边数 >= n，则存在负环
//                     if (++cnt[v] >= n)
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n, m;
//         cin>>n>>m;

//         vector<vector<pair<int, int>>> g(n + 1);
//         for (int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             if (w >= 0)
//             {
//                 g[u].push_back({v, w});
//                 g[v].push_back({u, w});
//             }
//             else
//             {
//                 g[u].push_back({v, w});
//             }
//         }

//         if (spfa(n, g))
//         {
//             cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//     }

//     return 0;
// }