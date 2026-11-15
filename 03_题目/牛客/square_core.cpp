// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// // https://ac.nowcoder.com/acm/contest/128678/C

// // 计算 x 的平方核（所有指数为奇数的质因子的乘积）
// ll core(ll x)
// {
//     ll res = 1;
//     // 因子 2
//     if (!(x & 1))
//     {
//         int cnt = 0;
//         while (!(x & 1))
//         {
//             x >>= 1;
//             cnt++;
//         }
//         if (cnt & 1)
//         {
//             res <<= 1;
//         }
//     }
    
//     // 奇数因子
//     for (ll i = 3; i * i <= x; i += 2)
//     {
//         if (x % i == 0)
//         {
//             int cnt = 0;
//             while (x % i == 0)
//             {
//                 x /= i;
//                 cnt++;
//             }
//             if (cnt & 1)
//             {
//                 res *= i;
//             }
//         }
//     }
    
//     // 剩余的大质数（指数为 1）
//     if (x > 1)
//     {
//         res *= x;
//     }
//     return res;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {

//         // x * y 为完全平方数，x = s * t^2
//         // 其中，s为 x 中所有指数为奇数的质因子的乘积（即无平方因子部分）
//         // 现在要让 x * y = s * t^2 * y 为完全平方数
//         // 只需 s * y 为完全平方数 k^2
//         // 又 y 为整数，且 s 为无平方因子数（每个质因子最多一次）
//         // 则 s 必须整除 k^2
//         // 对于 s 的每个质因子 p，p 在 k^2 中指数至少为 1
//         // 而 k^2 中每个质因子指数为偶数
//         // 所以 p 在 k 中的指数至少为 1
//         // 可设 k = s * m
//         // 则 y = k^2 / s = s * m^2
//         // 即 y 必须是 s 乘以一个完全平方数
//         // 故只需在[l，r]中枚举 y 即可

//         int x, l, r;
//         cin>>x>>l>>r;
        
//         // x = s * t^2
//         ll s = core(x);
//         int MAXK = sqrt(r);
        
//         // 枚举 k，使得 s * k^2 落在 [l, r] 内
//         for (int k = 1; k <= MAXK; k++)
//         {
//             ll val = s * k * k;
//             // 超过右边界，停止
//             if (val > r)
//             {
//                 break;
//             }
            
//             if (val >= l)
//             {
//                 cout<<val<<endl;
//                 return 0;
//             }
//         }
        
//         cout<<-1<<endl;
//     }

//     return 0;
// }