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

//         // 建图
//         vector<vector<int>> g(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             if (i - 1 >= 1)
//             {
//                 g[i].push_back(i - 1);
//             }
//             if (i + 1 <= n)
//             {
//                 g[i].push_back(i + 1);
//             }
//             if (2 * i <= n)
//             {
//                 g[i].push_back(2 * i);
//             }
//         }

//         queue<int> q;
//         vector<int> dist(n + 1, -1);
//         q.push(1);
//         dist[1] = 0;
//         // BFS搜最短路径
//         while (!q.empty())
//         {
//             int u = q.front();
//             q.pop();

//             for (int v : g[u])
//             {
//                 if (dist[v] == -1)
//                 {
//                     dist[v] = dist[u] + 1;
//                     q.push(v);
//                 }
//             }
//         }

//         cout<<dist[n]<<endl;
//     }

//     return 0;
// }