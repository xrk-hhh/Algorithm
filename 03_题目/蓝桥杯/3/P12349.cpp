// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MAXN = 1010;

// // 注意到行翻转是全局操作，且只有上下行之间的影响，这提示我们可以用动态规划逐行处理。

// int n, m;
// vector<vector<int>> a;
// // val[i][up][cur][down]：表示当第 i-1 行状态为 up,第 i行状态为 cur，第 i+1 行状态为 down 时，第 i 行所有格子的价值之和、
// // 对于边界行（第一行没有上一行，最后一行没有下一行），相应的状态参数不影响结果，我们可以任意取值（例如取 0）。
// ll val[MAXN][2][2][2];

// void compute()
// {
//     for (int i = 1; i <= n; i++) 
//     {
//         for (int up = 0; up <= 1; up++) 
//         {
//             for (int cur = 0; cur <= 1; cur++) 
//             {
//                 for (int down = 0; down <= 1; down++) 
//                 {
//                     ll sum = 0;
//                     for (int j = 1; j <= m; j++) 
//                     {
//                         int cur_val = a[i][j] ^ cur;
//                         int cnt = 0;
//                         // 左
//                         if (j > 1) 
//                         {
//                             int left_val = a[i][j - 1] ^ cur;
//                             if (left_val == cur_val)
//                             {
//                                 cnt++;
//                             }
//                         }
//                         // 右
//                         if (j < m) 
//                         {
//                             int right_val = a[i][j + 1] ^ cur;
//                             if (right_val == cur_val)
//                             {
//                                 cnt++;
//                             }
//                         }
//                         // 上
//                         if (i > 1) 
//                         {
//                             int up_val = a[i - 1][j] ^ up;
//                             if (up_val == cur_val)
//                             {
//                                 cnt++;
//                             }
//                         }
//                         // 下
//                         if (i < n) 
//                         {
//                             int down_val = a[i + 1][j] ^ down;
//                             if (down_val == cur_val)
//                             {
//                                 cnt++;
//                             }
//                         }
//                         sum += cnt * cnt;
//                     }
//                     val[i][up][cur][down] = sum;
//                 }
//             }
//         }
//     }
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n>>m;

//         a.resize(n + 2, vector<int>(m + 2));
//         for (int i = 1; i <= n; i++)
//         {
//             string s;
//             cin>>s;
//             for (int j = 1; j <= m; j++)
//             {
//                 a[i][j] = s[j - 1] - '0';
//             }
//         }

//         compute();

//         if (n == 1)
//         {
//             ll ans = 0;
//             for (int s = 0; s <= 1; s++) 
//             {
//                 ans = max(ans, val[1][0][s][0]);
//             }
//             cout<<ans<<endl;
//             return 0;
//         }

//         // dp[i][s1][s2]：表示已经处理完前 i 行，且第 i-1 行状态为 s1，第 i 行状态为 s2 时，前 i-1 行的最大总价值
//         // 即 第 1 行到第 i-1 行的贡献之和
//         vector<vector<vector<ll>>> dp(n + 2, vector<vector<ll>>(2, vector<ll>(2, -1e18)));
//         // 初始化 i=2
//         for (int s1 = 0; s1 <= 1; s1++) 
//         {
//             for (int s2 = 0; s2 <= 1; s2++) 
//             {
//                 dp[2][s1][s2] = val[1][0][s1][s2];
//             }
//         }

//         for (int i = 2; i <= n - 1; i++) 
//         {
//             for (int s1 = 0; s1 <= 1; s1++) 
//             {
//                 for (int s2 = 0; s2 <= 1; s2++) 
//                 {
//                     if (dp[i][s1][s2] < -1e17)
//                     {
//                         continue;
//                     }
//                     for (int s3 = 0; s3 <= 1; s3++) 
//                     {
//                         ll add = val[i][s1][s2][s3];
//                         dp[i + 1][s2][s3] = max(dp[i + 1][s2][s3], dp[i][s1][s2] + add);
//                     }
//                 }
//             }
//         }

//         ll ans = -1e18;
//         // 最后，处理完第 n 行后，我们还需要加上最后一行的贡献。
//         for (int s1 = 0; s1 <= 1; s1++) 
//         {
//             for (int s2 = 0; s2 <= 1; s2++) 
//             {
//                 ll total = dp[n][s1][s2] + val[n][s1][s2][0];
//                 ans = max(ans, total);
//             }
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }