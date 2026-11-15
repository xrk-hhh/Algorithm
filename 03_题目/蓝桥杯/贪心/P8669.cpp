// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int MOD = 1e9 + 9;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, k;
//         cin>>n>>k;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         sort(a.begin(), a.end());

//         ll ans = 1;
//         int l = 0, r = n - 1;
//         int flag = 1;
//         // 先判断 k 是否为奇数
//         if (k & 1)
//         {
//             // 如果 k 为奇数，先将最大的数乘上
//             r--;
//             k--;
//             ans *= a[n - 1];
//             // 如果最大数为负数，则标记为全负
//             if (a[n - 1] < 0)
//             {
//                 flag = -1;
//             }
//         }

//         while (k)
//         {
//             // 比较 最左边两个的乘积 和 最右边两个的乘积 大小（同号为正，因此考虑一对对取）
//             ll x = 1LL * a[l] * a[l + 1], y = 1LL * a[r] * a[r - 1];
//             if (x * flag <= y * flag)
//             {
//                 // 注意：需要先对乘积取模再乘答案再取模
//                 ans = y % MOD * ans % MOD;
//                 r -= 2;
//             }
//             else
//             {
//                 ans = x % MOD * ans % MOD;
//                 l += 2;
//             }

//             k -= 2;
//         }

//         cout<<ans % MOD<<endl;
//     }

//     return 0;
// }