// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int x, y;
//         cin>>x>>y;

//         // 无解
//         if (y % x != 0)
//         {
//             cout<<0<<endl;
//             return 0;
//         }

//         // 公式推导
//         // P = p * x, Q = q * x
//         // 则有 gcd(P, Q) = x * gcd(p, q) = x, lcm(P, Q) = x * lcm(p, q) = y
//         // 则有 gcd(p, q) = 1, lcm(p, q) = y / x
//         // n = y / x，必须为整数

//         // 由于 gcd(p, q) = 1，则 lcm(p, q) = p * q
//         // 则有 p * q = n, gcd(p, q) = 1
//         int n = y / x;
//         int cnt = 0;

//         // 若 n = 1, 则只有 p = q = 1，共 1 对
//         // 若 n > 1, 将 n 质因数分解 n = p1^e1 * p2^e2 * ... * pk^ek
//         // 由于 gcd(p, q) = 1,  每个质因子 pi 只能完全属于 p 或完全属于 q（不能同时出现，否则公因数包含 pi）
//         // 因此，对于每个质因子，有 2 种分配方式：全部给 p 或全部给 q。
//         // 于是总分配方案数为 2^k，对应 k 个不同的质因子

//         // 质因子个数
//         for (int i = 2; i * i <= n; i++)
//         {
//             if (n % i == 0)
//             {
//                 cnt++;
//                 while (n % i == 0)
//                 {
//                     n /= i;
//                 }
//             }
//         }

//         if (n > 1)
//         {
//             cnt++;
//         }

//         cout<<(1 << cnt)<<endl;
//     }

//     return 0;
// }