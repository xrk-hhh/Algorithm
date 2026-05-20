// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const ll mod = 998244353;
// const int MAXN = 1000000;

// vector<ll> fact, inv_fact;

// ll ksm(ll a, ll b, ll p)
// {
//     ll res = 1 % p;
//     a = a % p;
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

// void precompute()
// {
//     fact.resize(MAXN + 10);
//     inv_fact.resize(MAXN + 10);

//     fact[0] = 1;
//     for (int i = 1; i <= MAXN; i++)
//     {
//         fact[i] = fact[i- 1] * i % mod;
//     }
//     inv_fact[MAXN] = ksm(fact[MAXN], mod - 2, mod);
//     for (int i = MAXN; i >= 1; i--)
//     {
//         inv_fact[i - 1] = inv_fact[i] * i % mod;
//     }
// }

// ll C(int n, int k)
// {
//     if (k < 0 || k > n)
//     {
//         return 0;
//     }

//     return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     precompute();

//     while (T--)
//     {
//         int n, x, t;
//         cin>>n>>x>>t;

//         int k = t + 1;
//         ll ans = 0;

//         int a0 = (k + 1) / 2, b0 = k / 2;
//         int a1 = k / 2,     b1 = (k + 1) / 2;

//         auto cnt = [&](int a, int b) -> ll
//         {
//             if (a == 0)
//             {
//                 if (x != 0)
//                 {
//                     return 0;
//                 }

//                 if (b == 0)
//                 {
//                     if (n == 0)
//                     {
//                         return 1;
//                     }
//                     else
//                     {
//                         return 0;
//                     }
//                 }

//                 if (n - x < b)
//                 {
//                     return 0;
//                 }

//                 return C(n - x - 1, b - 1);
//             }

//             if (b == 0)
//             {
//                 if (n - x != 0)
//                 {
//                     return 0;
//                 }

//                 if (x < a)
//                 {
//                     return 0;
//                 }

//                 return C(x - 1, a - 1);
//             }

//             if (x < a || n - x < b)
//             {
//                 return 0;
//             }

//             return C(x - 1, a - 1) * C(n - x - 1, b - 1) % mod;
//         };

//         ans = (ans + cnt(a0, b0)) % mod;
//         ans = (ans + cnt(a1, b1)) % mod;

//         cout<<ans<<endl;
//     }

//     return 0;
// }