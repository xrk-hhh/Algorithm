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
//         int n, m;
//         cin>>n>>m;

//         vector<ll> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         sort(a.begin(), a.end());

//         // 前缀和
//         vector<ll> pre(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             pre[i] = pre[i - 1] + a[i - 1];
//         }

//         // 一个数需要加上的和
//         ll add = 0;
//         while (m--)
//         {
//             int op;
//             cin>>op;

//             if (op == 1)
//             {
//                 int k;
//                 cin>>k;
//                 add += k;
//             }
//             // 最大子序列和，即为大于0的数之和
//             // 即 每个满足 a[i] + add > 0 的 a[i]之和
//             // 即 a[i] > -add
//             else if (op == 2)
//             {
//                 // 目标
//                 ll tar = -add;

//                 // 第一个大于 -add 的数的位置的索引
//                 int pos = upper_bound(a.begin(),a.end(), tar) - a.begin() + 1;
                
//                 // 如果没有，则选择空序列，最大序列和为0
//                 if (pos == n + 1)
//                 {
//                     cout<<0<<endl;
//                 }
//                 else
//                 {
//                     ll ans = (pre[n] - pre[pos - 1]) + add * (n - pos + 1);
//                     cout<<ans<<endl;
//                 }
//             }
//         }
//     }

//     return 0;
// }