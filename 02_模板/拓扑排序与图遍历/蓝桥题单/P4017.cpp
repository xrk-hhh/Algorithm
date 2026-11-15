// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int MOD = 80112002;

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
//         vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);
//         for (int i = 0; i < m; i++)
//         {
//             int u, v;
//             cin>>u>>v;

//             g[u].push_back(v);
//             indeg[v]++;
//             outdeg[u]++;
//         }

//         queue<int> q;
//         // 从某个生产者出发，到达节点 i 的路径数量。
//         vector<ll> dp(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             // 生产者
//             if (indeg[i] == 0)
//             {
//                 // 表示以自身为起点的路径
//                 dp[i] = 1;
//                 q.push(i);
//             }
//         }

//         while (!q.empty())
//         {
//             int u = q.front();
//             q.pop();

//             for (int v : g[u])
//             {
//                 dp[v] = (dp[v] + dp[u]) % MOD;
//                 if (--indeg[v] == 0)
//                 {
//                     q.push(v);
//                 }
//             }
//         }

//         ll ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             // 顶级消费者
//             if (outdeg[i] == 0)
//             {
//                 ans = (ans + dp[i]) % MOD;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }