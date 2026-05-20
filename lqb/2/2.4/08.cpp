// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // #define ll long long

// // int n;
// // int ans = 0;
// // vector<string> a;

// // // 判断当前数列是否为接龙数列

// // // bool check(vector<string> b)
// // // {
// // //     for (int i = 1; i < b.size(); i++)
// // //     {
// // //         if (*(b[i].begin()) != *(b[i - 1].end() - 1))
// // //         {
// // //             return false;
// // //         }
// // //     }
// // //     return true;
// // // }

// // // DFS得部分分，核心：选/不选

// // // void dfs(int idx, vector<string> b, int cnt)
// // // {
// // //     if (idx == n)
// // //     {
// // //         ans = max(ans, cnt);
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

        
// //         // dfs(0, b, 0);

// //         // 位掩码得部分分，核心：选/不选

// //         // for (int mask = 1; mask < (1 << n); mask++)
// //         // {
// //         //     int cnt = 0;
// //         //     bool ok = true;
// //         //     vector<string> b;
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
// //         //                 ok = false;
// //         //                 b.pop_back();
// //         //                 break;
// //         //             }
// //         //         }
// //         //     }
// //         //     if (ok)
// //         //     {
// //         //         ans = max(ans, cnt);
// //         //     }
// //         // }

// //         cout<<n - ans<<endl;
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
//         // dp得全部分，核心：选/不选
//         // 主要围绕该数的 首尾数字 进行转移
//         // dp[i] 表示以末尾数字i结尾的最长接龙子序列的长度
//         // 对于一个数 num, 首位数字为 first，末尾数字为 last
//         // 则以 num 为结尾的序列长度为 dp[first] + 1
//         //                      选num      不选num
//         // 则 dp[last] = max(dp[last], dp[first] + 1)

//         int n;
//         cin>>n;

//         vector<int> dp(10, 0);
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin>>x;

//             int last = x % 10;
//             int first = x;
//             while (first >= 10)
//             {
//                 first /= 10;
//             }
//             dp[last] = max(dp[last], dp[first] + 1);
//             // 也可以用字符串解决
//         }

//         int maxx = 0;
//         for (int i = 0; i < 10; i++)
//         {
//             maxx = max(maxx, dp[i]);
//         }
//         cout<<n - maxx<<endl;
//     }

//     return 0;
// }