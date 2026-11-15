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

//         vector<int> rel(n - 1);
//         for (int i = 0; i < n - 1; i++)
//         {
//             cin>>rel[i];
//         }

//         // n <= 15，可考虑状压 dp

//         int full = (1 << n) - 1;
//         // dp[mask][last]：已经使用了 mask 中的数字，且最后一个数字是 last 的方案数
//         vector<vector<ll>> dp(1 << n, vector<ll>(n + 1, 0));
//         // 初始化：第一个数字可以是 1..n 中的任意一个
//         for (int i = 1; i <= n; i++)
//         {
//             dp[1 << (i - 1)][i] = 1;
//         }

//         for (int mask = 1; mask <= full; mask++)
//         {
//             int cnt = __builtin_popcount(mask);
//             // 已填满，无需转移 
//             if (cnt == n)
//             {
//                 continue;
//             }

//             // 当前应满足的关系索引 (0‑based)
//             int idx = cnt - 1;
//             for (int last = 1; last <= n; last++)
//             {
//                 // last 不在 mask 中，非法
//                 if (!(mask & (1 << (last - 1))))
//                 {
//                     continue;
//                 }

//                 if (dp[mask][last] == 0)
//                 {
//                     continue;
//                 }

//                 for (int nxt = 1; nxt <= n; nxt++)
//                 {
//                     // nxt 已经使用过
//                     if (mask & (1 << (nxt - 1)))
//                     {
//                         continue;
//                     }

//                     bool ok = false;
//                     if (rel[idx] == 1)
//                     {
//                         if (nxt == last + 1)
//                         {
//                             ok = true;
//                         }
//                     }
//                     else
//                     {
//                         if (nxt != last + 1)
//                         {
//                             ok = true;
//                         }
//                     }

//                     if (ok)
//                     {
//                         dp[mask | (1 << (nxt - 1))][nxt] += dp[mask][last];
//                     }
//                 }
//             }
//         }

//         ll ans = 0;
//         for (int last = 1; last <= n; last++)
//         {
//             ans += dp[full][last];
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }