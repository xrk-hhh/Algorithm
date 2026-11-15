// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // #define ll long long

// // int n;
// // vector<int> path;
// // vector<bool> vis;
// // bool ok = false;

// // // DFS深搜，但搜索空间太大

// // void dfs(int cur, int cnt)
// // {
// //     // 所有状态都访问了
// //     if (cnt == (1 << n))
// //     {
// //         // 当前状态与起点相比只有 1 位不同，即找到答案
// //         if (__builtin_popcount(cur ^ 0) == 1)
// //         {
// //             ok = true;
// //         }
// //         return;
// //     }

// //     // 尝试翻转每一位
// //     for (int i = 0; i < n; i++)
// //     {
// //         // 翻转第 i 位
// //         int nxt = cur ^ (1 << i);
// //         if (!vis[nxt])
// //         {
// //             vis[nxt] = true;
// //             path.push_back(nxt);
// //             dfs(nxt, cnt + 1);
// //             // 找到解立刻返回
// //             if (ok)
// //             {
// //                 return;
// //             }
// //             vis[nxt] = false;
// //             path.pop_back();
// //         }
// //     }
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
// //         cin>>n;

// //         vis.assign((1 << n), false);
// //         vis[0] = true;
// //         path.push_back(0);
// //         // 从起点开始，全 O
// //         dfs(0, 1);

// //         if (ok)
// //         {
// //             for (int state : path)
// //             {
// //                 for (int i = 0; i < n; i++)
// //                 {
// //                     if ((state >> i) & 1)
// //                     {
// //                         cout<<'X';
// //                     }
// //                     else
// //                     {
// //                         cout<<"O";
// //                     }
// //                 }
// //                 cout<<endl;
// //             }

// //             for (int i = 0; i < n; i++)
// //             {
// //                 cout<<'O';
// //             }
// //             cout<<endl;
// //         }
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
//         int n;
//         cin>>n;

//         // 反射法 构造格雷码

//         vector<string> gray;
//         // 当 n = 1时，格雷码为 ["0", "1"]
//         gray.push_back("0");
//         gray.push_back("1");

//         // 当 n > 1时，先得到 n - 1位的格雷码列表
//         // 然后前半部分每个前面加 "0"
//         // 后半部分每个前面加 "1" 并逆序
        
//         for (int i = 2; i <= n; i++)
//         {
//             vector<string> next;
//             // 前半部分加 0
//             for (const string s : gray)
//             {
//                 next.push_back("0" + s);
//             }

//             // 后半部分加 1 并逆序
//             for (int j = gray.size() - 1; j >= 0; j--)
//             {
//                 next.push_back("1" + gray[j]);
//             }
//             gray = move(next);
//         }

//         // // 二进制 转 格雷码 公式
//         // // g(i) = i 异或 (i >> 1)

//         // for (int i = 0; i < (1 << n); i++)
//         // {
//         //     int g = i ^ (i >> 1);
//         //     for (int bit = n - 1; bit >= 0; bit--)
//         //     {
//         //         if ((g >> bit) & 1)
//         //         {
//         //             cout<<'X';
//         //         }
//         //         else
//         //         {
//         //             cout<<'O';
//         //         }
//         //     }
//         //     cout<<endl;
//         // }


//         for (const string s : gray)
//         {
//             for (char c : s)
//             {
//                 if (c == '0')
//                 {
//                     cout<<'O';
//                 }
//                 else if (c == '1')
//                 {
//                     cout<<'X';
//                 }
//             }
//             cout<<endl;
//         }

//         cout<<string(n, 'O')<<endl;
//     }

//     return 0;
// }