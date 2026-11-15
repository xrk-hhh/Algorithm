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
//         int n, m;
//         cin>>n>>m;

//         // 该数字能否选择
//         vector<bool> vis(n + 1, false);
//         for (int i = 0; i < m; i++)
//         {
//             int a;
//             cin>>a;

//             vis[a] = true;
//         }

//         // 相邻项不能选，因此考虑动态规划
//         // dp[i] 表示前 i 个灯塔能点亮的最大数量
//         // dp[0] = 0
//         vector<int> dp(n + 1, 0);
//         // dp[1] 取决于 1 能否选
//         dp[1] = vis[1] ? 1 : 0;
//         for (int i = 2; i <= n; i++)
//         {
//             // i 可选
//             if (vis[i])
//             {
//                 dp[i] = max(dp[i - 1], dp[i - 2] + 1);
//             }
//             // i 不可选
//             else
//             {
//                 dp[i] = dp[i - 1];
//             }
//         }

//         cout<<dp[n]<<endl;
//     }

//     return 0;
// }