// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 9901;

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
//     return res % p;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         ll a, b;
//         cin>>a>>b;

//         ll ans = 1;
//         // 求 a ^ b的因子和
//         // 先对 a 进行质因数分解，后面发现因子和公式为 等比数列求和 再相乘 
//         // 对于分母可使用快速幂，分子则使用逆元处理
//         // 但需要注意：分子为 q - 1，当 q - 1为 0 时，即q = 1时无意义，需要特判
//         for (ll i = 2; i * i <= a; i++)
//         {
//             if (a % i == 0)
//             {
//                 // 指数
//                 ll e = 0;
//                 while (a % i == 0)
//                 {
//                     a /= i;
//                     e++;  
//                 }

//                 // 分子
//                 ll num = (ksm(i, b * e + 1, mod) + mod - 1) % mod;
//                 // 分母
//                 ll den = (i - 1) % mod;
                
//                 // 分母为 0，特判
//                 if (den == 0)
//                 {
//                     // 公比 q 为 1
//                     ans = ans * ((b * e + 1) % mod) % mod;
//                 }
//                 else
//                 {
//                     ans = ans * num % mod * ksm(den, mod - 2, mod) % mod;
//                 }
//             }
//         }

//         // 处理剩余质因数（指数为 1）
//         if (a > 1)
//         {
//             ll e = 1;
//             ll num = (ksm(a, b * e + 1, mod) + mod - 1) % mod;
//             ll den = (a - 1) % mod;

//             if (den == 0)
//             {
//                 ans = ans * ((b * e + 1) % mod) % mod;
//             }
//             else
//             {
//                 ans = ans * num % mod * ksm(den, mod - 2, mod) % mod;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }