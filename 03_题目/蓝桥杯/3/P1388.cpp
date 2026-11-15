// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n, k;
// vector<int> a;
// vector<int> sum;

// // 转移：考虑整个表达式的最后一步运算是加法还是乘法，
// // 枚举分割点 m 将区间分成左右两部分，并分配乘号个数。
// // 若最后一步是加法，则左右两部分使用的乘号个数之和为 cnt，结果相加。
// // 若最后一步是乘法，则左右两部分使用的乘号个数之和为 cnt-1，结果相乘。

// // 边界：当 cnt=0 时，区间内全是加法，结果就是区间和。
// // 复杂度：区间个数 O(n²)，每个区间枚举分割点 O(n)，再枚举乘号分配 O(k²)
// // 则总复杂度约为 O(n³k)

// // 当然，本题思路适用于 num >= 0
// // 当 num > 0时，可以直接按照： dp[i][t] 表示前 i 个数分成 t 段（即用了 t-1 个乘号）
// // 因为此时有 (a+b)*c >= a+b*c

// // 而如果 c=0且a>0时，显然上式不成立

// // 故需按照 区间dp 解决

// // dp[l][r][cnt] 表示区间 [l,r] 内使用 cnt 个乘号的最大值
// ll dp[20][20][20];

// ll dfs(int l, int r, int cnt)
// {
//     if (dp[l][r][cnt] != -1)
//     {
//         return dp[l][r][cnt];
//     }

//     // 没有乘号，全部相加
//     if (cnt == 0)
//     {
//         return dp[l][r][cnt] = sum[r] - sum[l - 1];
//     }

//     ll res = 0;
//     // 枚举最后一步是加法
//     for (int m = l; m < r; m++)
//     {
//         for (int left = 0; left <= cnt; left++)
//         {
//             int right = cnt - left;
//             // 左边最多有 m-l 个乘号，右边最多有 r-m-1 个
//             if (left <= m - l && right <= r - m - 1)
//             {
//                 ll left_val = dfs(l, m, left);
//                 ll right_val = dfs(m + 1, r, right);

//                 res = max(res, left_val + right_val);
//             }
//         }
//     }

//     // 枚举最后一步是乘法
//     if (cnt > 0)
//     {
//         for (int m = l; m < r; m++)
//         {
//             for (int left = 0; left <= cnt - 1; left++)
//             {
//                 int right = cnt - 1 - left;
//                 if (left <= m - l && right <= r - m - 1)
//                 {
//                     ll left_val = dfs(l, m, left);
//                     ll right_val = dfs(m + 1, r, right);

//                     res = max(res, left_val * right_val);
//                 }
//             }
//         }
//     }

//     return dp[l][r][cnt] = res;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n>>k;

//         a.resize(n + 1, 0);
//         sum.resize(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//             sum[i] = sum[i - 1] + a[i];
//         }

//         memset(dp, -1, sizeof(dp));

//         ll ans = dfs(1, n, k);

//         cout<<ans<<endl;
//     }

//     return 0;
// }