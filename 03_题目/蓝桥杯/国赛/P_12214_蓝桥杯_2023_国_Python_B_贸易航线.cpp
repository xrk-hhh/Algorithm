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
//         int n, m, k;
//         cin>>n>>m>>k;

//         vector<vector<int>> p(n + 1, vector<int>(m + 1));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 cin>>p[i][j];
//             }
//         }

//         // dp[i][j]：从第 i 个地点出发，当前持有商品 j（0 表示空仓）时，单位商品的最大收益
//         vector<vector<ll>> dp(n + 2, vector<ll>(m + 1, 0));
//         for (int i = n; i >= 1; i--)
//         {
//             // 空仓：选择不买，或买入一种商品
//             dp[i][0] = dp[i + 1][0];
//             for (int j = 1; j <= m; j++)
//             {
//                 if (p[i][j] != -1)
//                 {
//                     dp[i][0] = max(dp[i][0], dp[i + 1][j] - p[i][j]);
//                 }
//             }

//             // 持有商品 u：选择不卖，或卖出并立即可能买入（利用刚算出的 dp[i][0]）
//             for (int j = 1; j <= m; j++)
//             {
//                 dp[i][j] = dp[i + 1][j];
//                 if (p[i][j] != -1)
//                 {
//                     dp[i][j] = max(dp[i][j], dp[i][0] + p[i][j]);
//                 }
//             }
//         }

//         // 容量为 k，等价于 k 个单位独立交易
//         cout<<dp[1][0] * k<<endl;
//     }

//     return 0;
// }