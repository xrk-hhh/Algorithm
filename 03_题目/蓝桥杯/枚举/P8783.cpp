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
//         int n, m, K;
//         cin>>n>>m>>K;

//         vector<vector<int>> a(n + 1, vector<int>(m + 1));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 cin>>a[i][j];
//             }
//         }

//         vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
//         // 二维前缀和
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
//             }
//         }

//         ll ans = 0;
//         // 第一条线（行）
//         for (int i = 1; i <= n; i++)
//         {
//             // 第二条线（行）
//             for (int j = i; j <= n; j++)
//             {
//                 // 枚举列
//                 for (int l = 1, r = 1; r <= m; r++)
//                 {
//                     // 双指针优化枚举满足条件的列数
//                     while (l <= r && pre[j][r] - pre[i - 1][r] - pre[j][l - 1] + pre[i - 1][l - 1] > K)
//                     {
//                         l++;
//                     }
//                     ans += r - l + 1;
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }