// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 1e9 + 7;
// const int MAXX = sqrt(mod) + 10;

// vector<bool> is_prime;
// vector<int> prime;
// map<ll, int> mp;
// vector<pair<ll, int>> fac;
// ll ans = 0;

// void pre(ll x)
// {
//     for (int p : prime)
//     {
//         if (1LL * p * p > x)
//         {
//             break;
//         }

//         while (x % p == 0)
//         {
//             mp[p]++;
//             x /= p;
//         }
//     }

//     if (x > 1)
//     {
//         mp[x]++;
//     }
// }

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

// void dfs(int idx, ll d)
// {
//     if (idx == fac.size())
//     {
//         ans = (ans + ksm(d, d, mod)) % mod;
//         return;
//     }

//     auto& [p, cnt] = fac[idx];
//     ll res = 1;
//     for (int i = 0; i <= cnt; i++)
//     {
//         dfs(idx + 1, d * res);

//         res *= p;
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
//         ll x, y;
//         cin>>x>>y;

//         is_prime.resize(MAXX, true);

//         for (int i = 2; i <= MAXX; i++)
//         {
//             if (is_prime[i])
//             {
//                 prime.push_back(i);

//                 for (int j = 2 * i; j <= MAXX; j += i)
//                 {
//                     is_prime[j] = false;
//                 }
//             }
//         }

//         pre(x);
//         pre(y);

//         fac.assign(mp.begin(), mp.end());

//         dfs(0, 1);

//         cout<<ans<<endl;
//     }

//     return 0;
// }