// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 1e4 + 7;

// vector<int> a, b;
// ll ans = 0;

// // 计算贡献
// void calc(vector<int>& pos)
// {
//     int k = pos.size();
//     if (k < 2)
//     {
//         return;
//     }

//     // 展开式子，可得贡献
//     ll Sa = 0, Sb = 0, Sab = 0;
//     for (int p : pos)
//     {
//         Sa += p;
//         Sb += a[p];
//         Sab += 1LL * p * a[p];
//     }

//     Sa %= mod;
//     Sb %= mod;
//     Sab %= mod;

//     ll t1 = (k - 2)* Sab % mod;
//     ll t2 = Sa * Sb % mod;

//     ans = (ans + t1 + t2) % mod;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m;
//         cin>>n>>m;

//         a.resize(n + 1);
//         b.resize(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>b[i];
//         }

//         // 2 * y = x + z
//         // 而贡献为 (x + z) * (a[x] + a[z])，与 y 无关
//         // 故只需考虑 x与z 同奇偶
//         unordered_map<int, vector<int>> odd, even;
//         for (int i = 1; i <= n; i++)
//         {
//             if (i & 1)
//             {
//                 odd[b[i]].push_back(i);
//             }
//             else
//             {
//                 even[b[i]].push_back(i);
//             }
//         }

//         for (auto& [v, pos] : odd)
//         {
//             calc(pos);
//         }
//         for (auto& [v, pos] : even)
//         {
//             calc(pos);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }