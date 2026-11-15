// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const ll INF = 1e18;

// // 二进制翻转
// int f(int x)
// {
//     if (x == 0)
//     {
//         return 0;
//     }

//     int bits = 0, t = x;
//     while (t)
//     {
//         bits++;
//         t >>= 1;
//     }

//     int res = 0;
//     for (int i = 0; i < bits; i++)
//     {
//         res = (res << 1) | (x & 1);
//         x >>= 1;
//     }

//     return res;
// }

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

//         vector<int> a(n + 1);
//         // d[i]：翻转a[i]后的增益
//         // pre[i]：前 i 个a[i]翻转后的增益
//         vector<ll> d(n + 1), pre(n + 1);
//         ll sum = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];

//             sum += a[i];
//             int b = f(a[i]);
//             d[i] = b - a[i];
//             pre[i] = pre[i - 1] + d[i];
//         }

//         if (m == 0)
//         {
//             cout<<sum<<endl;
//             return 0;
//         }

//         // dp[i][j] 前i个数选j个区间的最大增益
//         // dp[i][j] = max(dp[i−1][j], pre[i]+ (1≤k≤i)max(dp[k−1][j−1] − pre[k−1]))
//         vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -INF));
//         // 不选区间，增益0
//         for (int i = 0; i <= n; i++)
//         {
//             dp[i][0] = 0;
//         }

//         for (int j = 1; j <= m; j++)
//         {
//             // 初始 k=1 的候选
//             ll maxx = dp[0][j - 1] - pre[0];
//             for (int i = 1; i <= n; i++)
//             {
//                 // 不放第 i 个元素
//                 dp[i][j] = dp[i - 1][j];
//                 // 以 i 结尾选一个区间
//                 if (maxx > -INF)
//                 {
//                     dp[i][j] = max(dp[i][j], pre[i] + maxx);
//                 }

//                 // 更新 maxx 以包含 k=i+1 的情况（下一个 i 的候选）
//                 maxx = max(maxx, dp[i][j - 1] - pre[i]);
//             }
//         }

//         ll add = 0;
//         for (int j = 0; j <= m; j++)
//         {
//             add = max(add, dp[n][j]);
//         }

//         cout<<sum + add<<endl;
//     }

//     return 0;
// }