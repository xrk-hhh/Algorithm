// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MOD = 1e9 + 7;

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

//         if (m < 2)
//         {
//             cout<<0<<endl;
//             continue;
//         }

//         vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
//         dp[0][0][2] = 1;

//         for (int i = 0; i <= n; i++)
//         {
//             for (int j = 0; j <= m; j++)
//             {
//                 for (int k = 0; k <= m; k++)
//                 {
//                     if (dp[i][j][k] == 0)
//                     {
//                         continue;
//                     }

//                     if (i < n && k * 2 <= m)
//                     {
//                         dp[i + 1][j][k * 2] = (dp[i + 1][j][k * 2] + dp[i][j][k]) % MOD;
//                     }

//                     if (j < m && k > 0)
//                     {
//                         dp[i][j + 1][k - 1] = (dp[i][j + 1][k - 1] + dp[i][j][k]) % MOD;
//                     }
//                 }
//             }
//         }

//         cout<<dp[n][m - 1][1] % MOD<<endl;
//     }

//     return 0;
// }