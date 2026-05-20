// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int INF = 0x3f3f3f3f;

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

//         vector<int> m(n + 1);
//         // 前缀和
//         vector<int> sum(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>m[i];
//             sum[i] = sum[i - 1] + m[i];
//         }

//         // 将区间[i, j]的石子合并成一堆的最小代价
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//         // 枚举区间长度
//         for (int len = 2; len <= n; len++)
//         {
//             for (int i = 1; i + len - 1 <= n; i++)
//             {
//                 int j = i + len - 1;
//                 dp[i][j] = INF;

//                 int tot = sum[j] - sum[i - 1];
//                 // 枚举最后一次合并分界点
//                 for (int k = i; k < j; k++)
//                 {
//                     dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + tot);
//                 }
//             }
//         }

//         cout<<dp[1][n]<<endl;
//     }

//     return 0;
// }