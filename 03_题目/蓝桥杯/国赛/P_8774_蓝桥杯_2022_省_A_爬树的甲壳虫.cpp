// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const ll mod = 998244353;

// // 快速幂
// ll ksm(ll a, ll b, ll p)
// {
//     ll res = 1;
//     a %= p;
//     while (b)
//     {
//         if (b & 1)
//         {
//             res = res * a % p; 
//         }
//         b >>= 1;
//         a = a * a % p;
//     }
//     return res;
// }

// // 逆元
// ll inv(ll x)
// {
//     return ksm(x, mod - 2, mod);
// }

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

//         vector<int> P(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             ll x, y;
//             cin>>x>>y;

//             P[i] = x * inv(y) % mod;
//         }

//         // 系数递推
//         ll A = 0, B = 0;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             ll p = P[i + 1];
//             ll subP = (1 - p + mod) % mod;

//             ll nA = (subP * A + p) % mod;
//             ll nB = (1 + subP * B) % mod;

//             A = nA;
//             B = nB;
//         }

//         ll ans = B * inv((1 - A + mod) % mod) % mod;

//         cout<<ans<<endl;
//     }

//     return 0;
// }