// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // #define ll long long

// // int n;
// // vector<int> a;
// // int maxx = 0;

// // // 判断是否满足条件

// // // bool check(vector<int> b)
// // // {
// // //     for (int i = 1; i < b.size(); i++)
// // //     {
// // //         if ((b[i] & b[i - 1]) == 0)
// // //         {
// // //             return false;
// // //         }
// // //     }
// // //     return true;
// // // }

// // // DFS得部分分， 核心：选/不选

// // // void dfs(int idx, vector<int> b, int cnt)
// // // {
// // //     if (idx == n)
// // //     {
// // //         maxx = max(maxx, cnt);
// // //         return;
// // //     }

// // //     dfs(idx + 1, b, cnt);

// // //     b.push_back(a[idx]);
// // //     if (check(b))
// // //     {
// // //         dfs(idx + 1, b, cnt + 1);
// // //     }
// // // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
        
// //         cin>>n;

// //         a.resize(n);
// //         for (int i = 0; i < n; i++)
// //         {
// //             cin>>a[i];
// //         }

// //         // 位掩码得部分分，核心：选/不选
// //         // int maxx = 0;
// //         // for (int mask = 1; mask < (1 << n); mask++)
// //         // {
// //         //     int cnt = 0;
// //         //     vector<int> b;
// //         //     bool ok = true;
// //         //     for (int i = 0; i < n; i++)
// //         //     {
// //         //         if ((mask >> i) & 1)
// //         //         {
// //         //             b.push_back(a[i]);
// //         //             if (check(b))
// //         //             {
// //         //                 cnt++;
// //         //             }
// //         //             else
// //         //             {
// //         //                 b.pop_back();
// //         //                 ok = false;
// //         //                 break;
// //         //             }
// //         //         }
// //         //     }
// //         //     if (ok)
// //         //     {
// //         //         maxx = max(maxx, cnt);
// //         //     }
// //         // }

// //         // vector<int> b;

// //         // dfs(0, b, 0);

// //         cout<<maxx<<endl;
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         // 正确性说明：
//         // 若两个数 x 和 y 满足 x & y ≠ 0，则存在至少一位 b 使得两者在该位均为1。
//         // 因此，x 可以接在任何一个以某位为1结尾的序列后面，只要该位也在 x 中为1。

//         // dp[i] 表示当前已遍历的所有数字中，以某个数字结尾且该数字的第 b 位为 1 的最长子序列的长度。

//         int n;
//         cin>>n;

//         // 1e9 < 2^30
//         vector<int> dp(31, 0);
//         int maxx = 0;
//         // 遍历每个数
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin>>x;
            
//             // 计算以x结尾的最长长度 cur
//             int cur = 0;
//             for (int b = 0; b < 31; b++)
//             {
//                 if ((x >> b) & 1)
//                 {
//                     cur = max(cur, dp[b]);
//                 }
//             }
//             // 加上当前数
//             cur++;

//             // 更新 dp 数组
//             for (int b = 0; b < 31; b++)
//             {
//                 if ((x >> b) & 1)
//                 {
//                     dp[b] = max(dp[b], cur);
//                 }
//             }
            
//             // 更新全局答案
//             maxx = max(maxx, cur);
//         }

//         cout<<maxx<<endl;
//     }

//     return 0;
// }