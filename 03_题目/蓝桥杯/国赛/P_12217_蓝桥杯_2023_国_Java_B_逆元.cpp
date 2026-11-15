// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const ll mod = 2146516019;
// const int N = 233333333;


// // 快速幂 + 阶乘求逆元
// // ll fac[MAXX], inv[MAXX];

// // ll ksm(ll a, ll b)
// // {
// //     ll res = 1;
// //     a = a % mod;
// //     while (b)
// //     {
// //         if (b & 1)
// //         {
// //             res = res * a % mod;
// //         }
// //         b >>= 1;
// //         a = a * a % mod;
// //     }
// //     return res;
// // }

// // void init(int n)
// // {
// //     fac[0] = 1;
// //     for (int i = 1; i <= MAXX; i++)
// //     {
// //         fac[i] = fac[i - 1] * i % mod;
// //     }

// //     inv[n] = ksm(fac[n], mod - 2);
// //     for (int i = n - 1; i >= 0; i--)
// //     {
// //         inv[i] = inv[i + 1] * (i + 1) % mod;
// //     }
// // }

// // // 线性递推求逆元
// // vector<ll> inv(N + 1);
 
// // void linear_inv()
// // {
// //     inv[1] = 1;
// //     for (int i = 2; i <= N; i++)
// //     {
// //         inv[i] = (mod - mod / i) * inv[mod % i] % mod;
// //     }
// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         // linear_inv();

//         // ll ans = 0;
//         // for (int i = 1; i <= N; i++)
//         // {
//         //     ans ^= inv[i];
//         // }

//         // cout<<ans<<endl;

//         cout<<"1307261675"<<endl;
//     }

//     return 0;
// }