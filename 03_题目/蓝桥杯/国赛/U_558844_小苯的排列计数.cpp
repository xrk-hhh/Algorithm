// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 998244353;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         // 前 i 个元素中的最小值
//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         // 因为是 1-n 的排列，所以 a[n]必须为 1
//         if (a[n] != 1)
//         {
//             cout<<0<<endl;
//             continue;
//         }

//         // 显然，前缀最小值必然是非增的
//         bool ok = true;
//         for (int i = 2; i <= n; i++)
//         {
//             if (a[i] > a[i - 1])
//             {
//                 ok = false;
//                 break;
//             }
//         }
//         if (!ok)
//         {
//             cout<<0<<endl;
//             continue;
//         }

//         ll ans = 1;
//         // 比最小值大的数的个数（候选）
//         int k = n - a[1];
//         for (int i = 2; i <= n; i++)
//         {
//             // 从候选中任选
//             if (a[i] == a[i - 1])
//             {
//                 if (k <= 0)
//                 {
//                     ans = 0;
//                     break;
//                 }

//                 ans = ans * k % mod;
//                 k--;
//             }
//             // 当前数只能为 a[i]，此时候选多了 (a[i] + 1) ~ (a[i - 1] - 1)
//             else
//             {
//                 k += (a[i - 1] - a[i] - 1);
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }