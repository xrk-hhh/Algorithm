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

//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         // 方法一：暴力做法，得部分分(92分)

//         // 先算前缀和
//         // vector<ll> sum(n + 1, 0);
//         // for (int i = 1; i <= n; i++)
//         // {
//         //     sum[i] = sum[i - 1] + a[i];
//         // }

//         // int ans = 0;
//         // for (int l = 1; l <= n; l++)
//         // {
//                 // 从后枚举区间和右端点
//         //     int r = n;
//         //     while ((r >= l) && ((sum[r] - sum[l - 1]) % 7 != 0))
//         //     {
//         //         r--;
//         //     }
//         //     if (r < l)
//         //     {
//         //         continue;
//         //     }
//         //     int cnt = r - l + 1;
//         //     ans = max(ans, cnt);
//         // }

//         // cout<<ans<<endl;

//         // 方法二：数学性质，满分做法
//         // 如果两个前缀和（包括 sum[0]=0）模 7 相等，那么它们之间的区间和就是 7 的倍数。
//         // sr == sl-1(mod7) -> sr - sl-1 == 0(mod7)
//         // 则[l, r]区间和为 7 的倍数

//         // 先算前缀和模 7
//         vector<int> sum(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             sum[i] = (sum[i - 1] + a[i]) % 7;
//         }

//         // 每种余数(r)第一次出现和最后一次出现的下标
//         vector<int> first(7, -1), last(7, -1);
//         // sum[0] = 0，所以余数0第一次出现下标为0
//         first[0] = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             int r = sum[i];
//             // 第一次出现，更新余数 r 第一次出现下标
//             if (first[r] == -1)
//             {
//                 first[r] = i;
//             }
//             // 不断更新余数 r 最后一次出现下标
//             last[r] = i;
//         }

//         int ans = 0;
//         for (int r = 0; r < 7; r++)
//         {
//             // 余数出现过
//             if (first[r] != -1 && last[r] != -1)
//             {
//                 //           r         l-1
//                 int cnt = last[r] - first[r];
//                 ans = max(ans, cnt);
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }