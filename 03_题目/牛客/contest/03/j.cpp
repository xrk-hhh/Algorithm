// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int log2(ll x)
// {
//     return 63 - __builtin_clzll(x);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         ll n, q;
//         cin>>n>>q;

//         int h = log2(n) + 1;

//         while (q--)
//         {
//             ll x;
//             cin>>x;

//             int dp = log2(x);

//             ll ans = 0;
//             if (dp < h - 1)
//             {
//                 ans = 1LL << dp;
//             }
//             else
//             {
//                 ll tmp = 1LL << dp;

//                 ans = n - tmp + 1;
//             }

//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }