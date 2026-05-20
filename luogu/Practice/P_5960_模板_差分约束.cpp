// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int INF = 1e9;

// vector<int> dist;
// vector<int> cnt;
// vector<bool> inQueue;

// // SPFA 判负环
// bool spfa(int n, vector<vector<pair<int, int>>>& g)
// {
//     queue<int> q;
//     dist[0] = 0;
//     q.push(0);
//     inQueue[0] = true;

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         inQueue[u] = false;
//         for (auto& [v, w] : g[u])
//         {
//             // 差分约束与最短路等价（三角不等式）
//             // dist[v] <= dist[u] + w
//             // 对应 v <= u + w
//             if (dist[u] + w < dist[v])
//             {
//                 dist[v] = dist[u] + w;
//                 if (!inQueue[v])
//                 {
//                     q.push(v);
//                     inQueue[v] = true;

//                     // 节点总数 n+1 （含0）
//                     if (++cnt[v] > n)
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
//     // cin>>T;

//     while (T--)
//     {
//         int n, m;
//         cin>>n>>m;

//         dist.resize(n + 1, INF);
//         cnt.resize(n + 1, 0);
//         inQueue.resize(n + 1, false);

//         vector<vector<pair<int, int>>> g(n + 1);
//         for (int i = 0; i < m; i++)
//         {
//             int v, u, w;
//             cin>>v>>u>>w;

//             g[u].push_back({v, w});
//         }

//         // 0为超级源点，且权值为0
//         for (int i = 1; i <= n; i++)
//         {
//             g[0].push_back({i, 0});
//         }

//         // 若存在负环，则不等式组无解（因为沿负环走一圈会得到 0 <= 负数 的矛盾）
//         if (spfa(n, g))
//         {
//             cout<<"NO"<<endl;
//         }
//         else
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 cout<<dist[i]<<' ';
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }