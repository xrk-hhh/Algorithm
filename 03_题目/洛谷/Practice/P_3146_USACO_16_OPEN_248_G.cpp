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

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         // 区间[l, r]能完全合并成的最大的数
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         // 单元素本身
//         for (int i = 0; i < n; i++)
//         {
//             dp[i][i] = a[i];
//         }

//         int ans = 0;
//         // 枚举区间长度
//         for (int len = 2; len <= n; len++)
//         {
//             for (int l = 0; l + len - 1 < n; l++)
//             {
//                 int r = l + len - 1;
//                 for (int k = l; k < r; k++)
//                 {
//                     // 只有相邻且相等才能合并，合并后数值加一
//                     if (dp[l][k] != 0 && dp[l][k] == dp[k + 1][r])
//                     {
//                         dp[l][r] = max(dp[l][r], dp[l][k] + 1);
//                     }
//                 }

//                 ans = max(ans, dp[l][r]);
//             }
//         }

//         // 单元素也可以成为最大值
//         for (int i = 0; i < n; i++)
//         {
//             ans = max(ans, a[i]);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }