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

//         vector<int> len(n + 1);
//         // 拓扑排序，有向无环图（DAG）
//         vector<vector<int>> g(n + 1);
//         vector<int> indeg(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             int t, x;
//             cin>>t>>len[i];

//             while (cin>>x && x != 0)
//             {
//                 g[x].push_back(i);
//                 indeg[i]++;
//             }
//         }

//         queue<int> q;
//         // 完成第 i 个任务的最早时间
//         vector<int> dp(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             if (indeg[i] == 0)
//             {
//                 q.push(i);
//                 dp[i] = len[i];
//             }
//         }

//         while (!q.empty())
//         {
//             int u =q.front();
//             q.pop();

//             for (int v : g[u])
//             {
//                 dp[v] = max(dp[v], dp[u] + len[v]);
//                 if (--indeg[v] == 0)
//                 {
//                     q.push(v);
//                 }
//             }
//         }

//         // 最后一个完成的任务时间就是总耗时
//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             ans = max(ans, dp[i]);
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }