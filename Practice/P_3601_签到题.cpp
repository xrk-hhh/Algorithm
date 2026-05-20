// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 666623333;
// const int MAXP = 1e6 + 10;

// vector<int> primes;
// bool is_composite[MAXP];

// // 线性筛求素数
// void sieve()
// {
//     for (int i = 2; i < MAXP; i++)
//     {
//         if (!is_composite[i])
//         {
//             primes.push_back(i);
//         }

//         for (int p : primes)
//         {
//             if (i * p >= MAXP)
//             {
//                 break;
//             }

//             is_composite[i * p] = true;
//             if (i % p == 0)
//             {
//                 break;
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         sieve();

//         ll l, r;
//         cin>>l>>r;

//         int len = r - l + 1;
//         // val：当前剩余的数，phi：累积的欧拉函数值
//         vector<ll> val(len), phi(len);
//         for (int i = 0; i < len; i++)
//         {
//             val[i] = l + i;
//             phi[i] = val[i];
//         }

//         // 用素数筛法计算区间内每个数的欧拉函数
//         for (int p : primes)
//         {
//             // 只用到 sqrt(r)
//             if (1LL * p * p > r)
//             {
//                 break;
//             }

//             // 找到区间内第一个 p 的倍数
//             ll start = (l + p - 1) / p * p;
//             for (ll x = start; x <= r; x += p)
//             {
//                 int idx = x - l;

//                 // 除去 x 中的所有因子 p
//                 while (val[idx] % p == 0)
//                 {
//                     val[idx] /= p;
//                 }

//                 phi[idx] = phi[idx] / p * (p - 1);
//             }
//         }

//         // 处理剩余的大质数
//         for (int i = 0; i < len; i++)
//         {
//             if (val[i] > 1)
//             {
//                 phi[i] = phi[i] / val[i] * (val[i] - 1);
//             }
//         }

//         // 计算区间和
//         ll sum1 = ((l + r) * len >> 1) % mod;
//         ll sum2 = 0;
//         for (int i = 0; i < len; i++)
//         {
//             sum2 = (sum2 + phi[i]) % mod;
//         }

//         ll ans = (sum1 - sum2 + mod) % mod;

//         cout<<ans<<endl;
//     }

//     return 0;
// }