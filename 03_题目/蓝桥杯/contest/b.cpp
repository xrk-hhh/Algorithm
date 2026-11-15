// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 998244353;

// ll ksm(ll a, ll b, ll p)
// {
//     ll res = 1;
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

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         // int n = 2026;
//         // cin>>n;

//         // vector<int> s(n);
//         // queue<vector<int>> q;
//         // map<vector<int>, int> d;
//         // q.push(s);
//         // d[s] = 0;
//         // while (!q.empty())
//         // {
//         //     auto u = q.front();
//         //     q.pop();

//         //     for (int i = 0; i < n; i++)
//         //     {
//         //         auto v = u;
//         //         if (d[u] & 1)
//         //         {
//         //             for (int j = 0; j <= i; j++)
//         //             {
//         //                 v[j] ^= 1;
//         //             }
//         //         }
//         //         else
//         //         {
//         //             for (int j = i; j < n; j++)
//         //             {
//         //                 v[j] ^= 1;
//         //             }
//         //         }

//         //         if (!d.count(v))
//         //         {
//         //             d[v] = d[u] + 1;
//         //             q.push(v);
//         //         }
//         //     }
//         // }

//         // ll ans = 0;
//         // for (auto& [v, dist] : d)
//         // {
//         //     cout<<"状态：";
//         //     for (auto& x : v)
//         //     {
//         //         cout<<x<<' ';
//         //     }
//         //     cout<<"，步数："<<dist<<endl;
//         //     ans += dist;
//         // }

//         // cout<<"ans："<<ans<<endl;


//         // /*
//         //     当 n = 3 时，结果为
//         //     1个0，3个1，3个2，1个3 ———— 12
//         //     即：1 3 3 1

//         //     当 n = 4 时，结果为
//         //     1个0，4个1，6个2，4个3，1个4 ———— 32
//         //     即：1 4 6 4 1
        
//         //     显然，杨辉三角
//         //     1
//         //     1 1
//         //     1 2 1
//         //     1 3 3 1
//         //     1 4 6 4 1
//         //     1 5 10 10 5 1

//         //     故答案为：∑ C(n, i) * i
        
//         // */


//         // int n = 2026;
//         // cin>>n;

//         // vector<ll> f(n + 1, 1), g(n + 1, 1);
//         // for (int i = 1; i <= n; i++)
//         // {
//         //     f[i] = f[i - 1] * i % mod;
//         //     g[i] = g[i - 1] * ksm(i, mod - 2, mod) % mod;
//         // }
//         // // C(n, m) = n! / (m! * (n - m)!) 
//         // // f[n] * g[m] * g[n - m]

//         // ll ans = 0;
//         // for (int i = 0; i <= n; i++)
//         // {
//         //     ll C = f[n] * g[i] % mod * g[n - i] % mod;

//         //     ans = (ans + C * i % mod) % mod;
//         // }

//         // cout<<ans<<endl;

//         // cout<<"792264670"<<endl;
//     }

//     return 0;
// }