// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<vector<int>> g(n + 1);
//         vector<int> w(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             int u, v;
//             cin>>w[i]>>u>>v;

//             // 无向建边
//             if (u != 0)
//             {
//                 g[i].push_back(u);
//                 g[u].push_back(i);
//             }
//             if (v != 0)
//             {
//                 g[i].push_back(v);
//                 g[v].push_back(i);
//             }
//         }

//         int ans = 1e9;
//         // 多源BFS
//         for (int i = 1; i <= n; i++)
//         {
//             // 最短路
//             vector<int> dist(n + 1, -1);
//             queue<int> q;
//             q.push(i);
//             dist[i] = 0;
//             while (!q.empty())
//             {
//                 int u = q.front();
//                 q.pop();

//                 for (int v : g[u])
//                 {
//                     if (dist[v] == -1)
//                     {
//                         dist[v] = dist[u] + 1;
//                         q.push(v);
//                     }
//                 }
//             }

//             // 计算距离和
//             int sum = 0;
//             for (int i = 1; i <= n; i++)
//             {
//                 sum += dist[i] * w[i];
//             }

//             ans = min(ans, sum);
//         }
        
//         cout<<ans<<endl;
//     }

//     return 0;
// }