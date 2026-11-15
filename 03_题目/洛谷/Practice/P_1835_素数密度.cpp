// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // sqrt(r)
// const int MAXN = 1e5 + 10;

// vector<int> primes;
// bool is_composite[MAXN];

// // 线性筛素数(<= sqrt(r))
// void sieve(int n)
// {
//     for (int i = 2; i <= n; i++)
//     {
//         if (!is_composite[i])
//         {
//             primes.push_back(i);
//         }

//         for (int p : primes)
//         {
//             if (i * p > n)
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
//         int l, r;
//         cin>>l>>r;
//         // 预处理小于等于 sqrt(r)的素数
//         int n = sqrt(r);
//         sieve(n);

//         // 区间筛素数个数
//         int len = r - l + 1;
//         vector<bool> is_prime(len, true);
//         // 对于每个质数p
//         for (int p: primes)
//         {
//             // 找到区间[l, r]中第一个 p 的倍数
//             // 从 p² 开始标记可以避免重复标记更小的倍数（因为这些倍数已经被更小的质因子标记过了）
//             ll start = max(1LL * p * p, 1LL * (l + p - 1) / p * p);
//             // 将其所有倍数标记为合数
//             for (ll j = start; j <= r; j += p)
//             {
//                 is_prime[j - l] = false;
//             }
//         }

//         // 当 l 为 1 时，注意 1 不是质数
//         if (l == 1)
//         {
//             is_prime[0] = false;
//         }

//         int ans = 0;
//         // 统计区间中素数个数
//         for (int i = 0; i < len; i++)
//         {
//             if (is_prime[i])
//             {
//                 ans++;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }