// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int mod = 998244353;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<ll> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         if (n == 1)
//         {
//             cout<<1<<endl;
//             continue;
//         }

//         vector<ll> dp(n + 1, 0);
//         vector<ll> pre(n + 1, 0);
//         dp[0] = 1;
//         pre[0] = dp[0];

//         ll cur = 0;
//         int l = 0;
//         for (int r = 0; r < n; r++)
//         {
//             while (l <= r && (cur & a[r]) != 0)
//             {
//                 cur ^= a[l];
//                 l++;
//             }
//             cur |= a[r];

//             dp[r + 1] = (pre[r] - (l > 0 ? pre[l - 1] : 0) + mod) % mod;

//             pre[r + 1] = (pre[r] + dp[r + 1]) % mod;
//         }

//         cout<<dp[n]<<endl;
//     }

//     return 0;
// }