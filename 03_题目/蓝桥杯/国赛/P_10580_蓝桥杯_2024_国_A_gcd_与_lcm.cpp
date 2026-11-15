// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 998244353;

// ll ksm(ll a, ll b)
// {
//     ll res=  1;
//     a %= mod;
//     while (b)
//     {
//         if (b & 1)
//         {
//             res = res * a % mod;
//         }
//         b >>= 1;
//         a = a * a % mod;
//     }
//     return res;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int x, y, n;
//         cin>>x>>y>>n;

//         // x = gcd(a1, a2, ..., an)
//         // y = lcm(a1, a2, ..., an)
//         // 令 bi = ai / x, z = y / x;
//         // 则有 gcd(b1, b2, ..., bn) = 1
//         //      lcm(b1, b2, ..., bn) = z
//         // 且每个 bi 必须是 z 的约数（因为 lcm 是 z，每个元素必须整除 z）

//         // 其中，z可分解为若干质因子
//         // 即 z = p1^e1 * p2^e2 * ... * pk^ek
//         // 记对于 bi，它对质因子 pj 的指数为 ai,j(0<= ai,j <=ej)
//         // 则要求满足题意，只需有
//         // gcd = 1：对每个 j，min(i)ai,j = 0，即所有元素的指数最小值是 0
//         // lcm = z：对每个 j，max(i)ai,j = ej，即所有元素的指数最大值是 ej
        
//         // 然后，只需适当分配质因子指数即可
//         // 先考虑单质因子：
//         // 而解决这个问题，就可以考虑 容斥原理
//         // 即 (全集，共有 ((e + 1)^n)种序列) 
//         // (序列中没有 0，即每个位置只能取 1-e，共有 (e^n)种序列)
//         // (序列中没有 e，即每个位置只能取 0-e-1，共有 (e^n)种序列)
//         // (序列中没有 0 和 e，即每个位置只能取 1-e-1，共有 ((e - 1)^n)种序列)

//         // 则所求即为 (e+1)^n - 2*(e^n) + (e-1)^n
//         // 最后对于所有质因子都按此计算即可
//         if (y % x != 0)
//         {
//             cout<<0<<endl;
//             continue;
//         }

//         ll z = y / x;
//         ll ans = 1;
//         for (ll p = 2; p * p <= z; p++)
//         {
//             if (z % p == 0)
//             {
//                 int e = 0;
//                 while (z % p == 0)
//                 {
//                     z /= p;
//                     e++;
//                 }

//                 ll t = (ksm(e + 1, n) - (ksm(e, n) << 1) + ksm(e - 1, n) % mod);

//                 ans = ans * t % mod;
//             }
//         }

//         // 还剩一个质因数
//         if (z > 1)
//         {
//             ll t = (ksm(2, n) - 2) % mod;
//             ans = ans * t % mod;
//         }

//         cout<<(ans + mod) % mod<<endl;
//     }

//     return 0;
// }