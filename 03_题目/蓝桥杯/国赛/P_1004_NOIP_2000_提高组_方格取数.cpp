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
// //         int n;
// //         cin>>n;

// //         vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));

// //         int x, y, v;
// //         while (cin>>x>>y>>v)
// //         {
// //             if (x == 0 && y == 0 && v == 0)
// //             {
// //                 break;
// //             }

// //             a[x][y] = v;
// //         }

// //         // dp[k][x1][x2]：两条路径走到步数 k，第一人所在行 x1，第二人所在行 x2 时，已获得的最大数字和
// //         vector<vector<vector<int>>> dp(2 * n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
// //         dp[2][1][1] = a[1][1];
// //         for (int k = 3; k <= 2 * n; k++)
// //         {
// //             for (int x1 = 1; x1 <= n; x1++)
// //             {
// //                 int y1 = k - x1;
// //                 if (y1 < 1 || y1 > n)
// //                 {
// //                     continue;;
// //                 }

// //                 for (int x2 = 1; x2 <= n; x2++)
// //                 {
// //                     int y2 = k - x2;
// //                     if (y2 < 1 || y2 > n)
// //                     {
// //                         continue;
// //                     }

// //                     int maxx = -1;
// //                     // 0: 下, 1: 右
// //                     for (int d1 = 0; d1 < 2; d1++)
// //                     {
// //                         int px1 = (d1 == 0) ? x1 - 1 : x1;
// //                         int py1 = (d1 == 0) ? y1 : y1 - 1;
// //                         if (px1 < 1 || py1 < 1)
// //                         {
// //                             continue;
// //                         }

// //                         for (int d2 = 0; d2 < 2 ; d2++)
// //                         {
// //                             int px2 = (d2 == 0) ? x2 - 1 : x2;
// //                             int py2 = (d2 == 0) ? y2 : y2 - 1;
// //                             if (px2 < 1 || py2 < 1)
// //                             {
// //                                 continue;
// //                             }

// //                             if (dp[k - 1][px1][px2] != -1)
// //                             {
// //                                 maxx = max(maxx, dp[k - 1][px1][px2]);
// //                             }
// //                         }
// //                     }

// //                     if (maxx != -1)
// //                     {
// //                         int add = a[x1][y1];
// //                         // 两人在不同格子，就加两个格子的数字；反之则只加一次
// //                         if (x1 != x2 || y1 != y2)
// //                         {
// //                             add += a[x2][y2];
// //                         }

// //                         dp[k][x1][x2] = maxx + add;
// //                     }
// //                 }
// //             }
// //         }

// //         cout<<dp[2 * n][n][n]<<endl;
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n;
// vector<vector<int>> a;
// vector<vector<bool>> vis;
// int ans = 0;

// // dp 第二个人
// int Second()
// {
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             int val = vis[i][j] ? 0 : a[i][j];
//             if (i == 1 && j == 1)
//             {
//                 dp[i][j] = val;
//             }
//             else if (i == 1)
//             {
//                 dp[i][j] = dp[i][j - 1] + val;
//             }
//             else if (j == 1)
//             {
//                 dp[i][j] = dp[i - 1][j] + val;
//             }
//             else
//             {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + val;
//             }
//         }
//     }

//     return dp[n][n];
// }

// // DFS 第一个人
// void dfs(int x, int y, int sum)
// {
//     if (x == n && y == n)
//     {
//         ans = max(ans, sum + Second());
//         return;
//     }

//     vis[x][y] = true;
//     sum += a[x][y];
//     // 向下
//     if (x < n)
//     {
//         dfs(x + 1, y, sum);
//     }
//     // 向右
//     if (y < n)
//     {
//         dfs(x, y + 1, sum);
//     }

//     vis[x][y] = false;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         // 也可以一个 dp + 一个 DFS
//         cin>>n;
//         vis.resize(n + 1, vector<bool>(n + 1, false));
//         a.resize(n + 1, vector<int>(n + 1));

//         int x, y, v;
//         while (cin>>x>>y>>v)
//         {
//             if (x == 0 && y == 0 && v == 0)
//             {
//                 break;
//             }

//             a[x][y] = v;
//         }

//         dfs(1, 1, 0);

//         cout<<ans<<endl;
//     }

//     return 0;
// }