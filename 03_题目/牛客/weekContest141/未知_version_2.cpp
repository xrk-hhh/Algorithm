// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

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

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         map<ll, int> mp;
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin>>x;

//             mp[x]++;
//         }

//         bool ok = false;
//         if (mp.count(1))
//         {
//             for (auto& [x, cnt] : mp)
//             {
//                 if (cnt >= 2)
//                 {
//                     ok = true;
//                     break;
//                 }
//             }
//         }

//         if (ok)
//         {
//             cout<<"YES"<<endl;
//             continue;
//         }

//         vector<ll> a;
//         for (auto& [x, cnt] : mp)
//         {
//             if (x == 1)
//             {
//                 continue;
//             }

//             cnt = min(cnt, 2);
//             for (int i = 0; i < cnt; i++)
//             {
//                 a.push_back(x);
//             }
//         }

//         for (auto& x : a)
//         {
//             for (auto& y : a)
//             {
//                 if (y >= 31)
//                 {
//                     break;
//                 }

//                 ll p = (ll)ceil(log(1e9) / log(x));
//                 if (y > p)
//                 {
//                     break;
//                 }

//                 ll cur = ksm(x, y, 1e18);
//                 if (mp.count(cur))
//                 {
//                     ok = true;
//                     break;
//                 }
//             }
//             if (ok)
//             {
//                 break;
//             }
//         }

//         if (ok)
//         {
//             cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//     }

//     return 0;
// }