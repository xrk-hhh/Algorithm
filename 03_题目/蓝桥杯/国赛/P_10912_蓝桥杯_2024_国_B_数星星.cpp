// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 1e9 + 7;
// const int MAXN = 1e5 + 10;

// ll fac[MAXN], inv[MAXN];

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

// // 预处理阶乘和逆元
// void init(int n)
// {
//     fac[0] = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         fac[i] = fac[i - 1] * i % mod;
//     }

//     inv[n] = ksm(fac[n], mod - 2, mod);
//     for (int i = n - 1; i >= 0; i--)
//     {
//         inv[i] = inv[i + 1] * (i + 1) % mod;
//     }
// }

// // 组合数C(n, m) = n! / (m! * (n - m)!)
// ll C(int n, int m)
// {
//     if (m < 0 || m > n)
//     {
//         return 0;
//     }

//     return fac[n] * inv[m] % mod * inv[n - m] % mod;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, l, r;
//         cin>>n;

//         // 度数
//         vector<int> deg(n + 1, 0);
//         for (int i = 0; i < n - 1; i++)
//         {
//             int u, v;
//             cin>>u>>v;

//             deg[u]++;
//             deg[v]++;
//         }
//         cin>>l>>r;

//         // 最大度数
//         int maxx = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             maxx = max(maxx, deg[i]);
//         }

//         init(maxx);

//         ll ans = 0;
//         for (int u = 1; u <= n; u++)
//         {
//             int d = deg[u];
//             int L = max(0, l - 1);
//             int R = min(d, r - 1);

//             // 邻居个数为 k，星星大小为 k + 1
//             for (int k = L; k <= R; k++)
//             {
//                 ans = (ans + C(d, k)) % mod;
//             }
//         }

//         // 减去重复计数：所有大小为 2 的星星被每条边的两个端点各计算了一次，需减去边数 n−1
//         if (l <= 2 && r >= 2)
//         {
//             ans = (ans - (n - 1) + mod) % mod;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }