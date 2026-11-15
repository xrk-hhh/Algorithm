// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

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

//         // 地雷数
//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         // 邻接矩阵，g[i][j] 表示 i 到 j 是否有路径 (i < j)
//         vector<vector<bool>> g(n + 1, vector<bool>(n + 1, false));
//         for (int i = 1; i <= n - 1; i++)
//         {
//             for (int j = i + 1; j <= n; j++)
//             {
//                 int x;
//                 cin>>x;
//                 g[i][j] = (x == 1);
//             }
//         }

//         // dp[i] 表示以 i 为终点的最大地雷数
//         vector<int> dp(n + 1, 0);
//         // 前驱节点
//         vector<int> pre(n + 1, 0);
//         // 最大值和对应的终点
//         int ans = 0, end = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             // 从 i 开始
//             dp[i] = a[i];
//             for (int j = 1; j < i; j++)
//             {
//                 if (g[j][i] && dp[j] + a[i] > dp[i])
//                 {
//                     dp[i] = dp[j] + a[i];
//                     pre[i] = j;
//                 }
//             }
//             if (dp[i] > ans)
//             {
//                 ans = dp[i];
//                 end = i;
//             }
//         }

//         // 回溯路径
//         vector<int> path;
//         for (int p = end; p != 0; p = pre[p])
//         {
//             path.push_back(p);
//         }

//         reverse(path.begin(), path.end());

//         for (int i = 0; i < path.size(); i++)
//         {
//             if (i)
//             {
//                 cout<<' ';
//             }
//             cout<<path[i];
//         }
//         cout<<endl<<ans<<endl;
//     }

//     return 0;
// }