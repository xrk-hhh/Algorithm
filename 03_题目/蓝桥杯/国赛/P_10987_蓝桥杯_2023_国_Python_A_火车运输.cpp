// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // using ll = long long;

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
// //         int n, a, b;
// //         cin>>n>>a>>b;

// //         vector<int> w(n);
// //         for (int i = 0; i < n; i++)
// //         {
// //             cin>>w[i];
// //         }

// //         // 二维费用 01 背包
// //         // 复杂度 O(nab)

// //         // dp[i][j]：第一个背包用容量 i、第二个背包用容量 j 是否可行
// //         vector<vector<bool>> dp(a + 1, vector<bool>(b + 1, false));
// //         dp[0][0] = true;
// //         for (int x : w)
// //         {
// //             // 注意倒序：以防同一物品重复使用
// //             for (int i = a; i >= 0; i--)
// //             {
// //                 for (int j = b; j >= 0; j--)
// //                 {
// //                     if (i >= x && dp[i - x][j])
// //                     {
// //                         dp[i][j] = true;
// //                     }
// //                     if (j >= x && dp[i][j - x])
// //                     {
// //                         dp[i][j] = true;
// //                     }
// //                 }
// //             }
// //         }

// //         int ans = 0;
// //         for (int i = 0; i <= a; i++)
// //         {
// //             for (int j = 0; j <= b; j++)
// //             {
// //                 if (dp[i][j])
// //                 {
// //                     ans = max(ans, i + j);
// //                 }
// //             }
// //         }

// //         cout<<ans<<endl;
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int MAXA = 1e3 + 10;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, a, b;
//         cin>>n>>a>>b;

//         vector<int> w(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>w[i];
//         }

//         // dp[i] 为一个 bitset<B+1>：当 A 背包已用 i 时，B 背包所有可能的已用容量集合
//         vector<bitset<MAXA>> dp(a + 1);
//         dp[0].set(0);
        
//         for (int x : w)
//         {
//             // 不选当前物品
//             auto ndp = dp;
//             // 倒序遍历 A 容量
//             for (int i = a; i >= 0; i--)
//             {
//                 // 放入 A
//                 if (i >= x)
//                 {
//                     ndp[i] |= dp[i - x];
//                 }

//                 // 放入 B（左移 x 位）
//                 ndp[i] |= (dp[i] << x);
//             }

//             dp = move(ndp);
//         }

//         int ans = 0;
//         for (int i = 0; i <= a; i++)
//         {
//             for (int j = 0; j <= b; j++)
//             {
//                 if (dp[i][j])
//                 {
//                     ans = max(ans, i + j);
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }