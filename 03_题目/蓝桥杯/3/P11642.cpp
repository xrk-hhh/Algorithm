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
//         int n, x;
//         cin>>n>>x;

//         // ans = sum - Σ(i = l, r)a[i] + (r - l + 1) * x
//         //     = sum + Σ(i = l, r)(x - a[i])
//         // 问题转化为 求 b数组的最大子段和，如果为正，则加上，否则不操作
//         // ans = sum + max(0, 最大子段和)

//         vector<int> a(n);
//         ll sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             sum += a[i];
//         }

//         ll cur = 0;
//         ll best = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int b = x - a[i];
//             cur = max(0LL, cur + b);
//             best = max(best, cur);
//         }

//         cout<<sum + best<<endl;
//     }

//     return 0;
// }