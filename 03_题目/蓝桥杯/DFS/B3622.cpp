// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n;
// // string ans;

// // 指数型枚举

// // // 枚举位置
// // void dfs(int pos)
// // {
// //     // 超出限制，则输出结果
// //     if (pos == n + 1)
// //     {
// //         cout<<ans<<endl;
// //         return;
// //     }

// //     // 选 'N'
// //     ans.push_back('N');
// //     dfs(pos + 1);
// //     ans.pop_back();
// //     // 选 'Y'
// //     ans.push_back('Y');
// //     dfs(pos + 1);
// //     ans.pop_back();
// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n;
//         // dfs(1);

//         // 看成二进制掩码
//         for (int mask = 0; mask < (1 << n); mask++)
//         {
//             string ans;
//             // 从高位到低位构建字符串，才能保证按数值递增的顺序输出时，字符串也是字典序递增的
//             for (int i = n - 1; i >= 0; i--)
//             {
//                 // 该位为 1，则输出'Y'
//                 if (mask >> i & 1)
//                 {
//                     ans.push_back('Y');
//                 }
//                 // 该位为 0，则输出 'N'
//                 else
//                 {
//                     ans.push_back('N');
//                 }
//             }
//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }