// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int MAXV = 60;

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

//         // [i, dp[i][v]]能合并出 v
//         vector<vector<int>> dp(n, vector<int>(MAXV + 1, -1));
//         for (int i = 0; i < n; i++)
//         {
//             dp[i][a[i]] = i;
//         }

//         int ans = 0;
//         // 枚举可能合并出的值
//         for (int v = 1; v <= MAXV; v++)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 if (dp[i][v] != -1)
//                 {
//                     int j = dp[i][v];
//                     if (j + 1 < n && dp[j + 1][v] != -1)
//                     {
//                         int k = dp[j + 1][v];
//                         // 取最远右端点
//                         if (k > dp[i][v + 1])
//                         {
//                             dp[i][v + 1] = k;
//                             ans = max(ans, v + 1);
//                         }
//                     }
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }