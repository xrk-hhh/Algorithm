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
//     // cin>>T;

//     while (T--)
//     {
//         string s;
//         cin>>s;

//         ll dp[3] = {0};
//         for (char c : s)
//         {
//             int idx = c - 'a';
//             ll sum = 0;
//             for (int i = 0; i < 3; i++)
//             {
//                 if (i != idx)
//                 {
//                     sum = (sum + dp[i]) % mod;
//                 }
//             }

//             dp[idx] = (dp[idx] + sum + 1) % mod;
//         }

//         ll ans = (dp[0] + dp[1] + dp[2]) % mod;

//         cout<<ans<<endl;
//     }

//     return 0;
// }