// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define pii pair<ll, ll>

// const int mod = 1e9 + 7;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         ll n;
//         cin>>n;

//         map<ll, ll> cnt;
//         for (int i = 0; i < n; i++)
//         {
//             ll c, w;
//             cin>>c>>w;
//             cnt[w] += c;
//         }

//         ll ans = 0;
//         while ((cnt.size() > 1) || (cnt.begin()->second >1))
//         {
//             auto it = cnt.begin();
//             ll w = it->first;
//             ll c = it->second;

//             cnt.erase(it);

//             if (c >= 2)
//             {
//                 ll t = c / 2;
//                 ans = (ans + (2 * w % mod) * t) % mod;
//                 cnt[2 * w] += t;
//                 c %= 2;
//             }

//             if (c == 1)
//             {
//                 auto it1 = cnt.begin();
//                 ll w1 = it1->first;

//                 ans = (ans + w + w1) % mod;
//                 if (--cnt[w1] == 0)
//                 {
//                     cnt.erase(it1);
//                 }
//                 cnt[w + w1]++;
//             }
//         }

//         cout<<ans % mod<<endl;
//     }

//     return 0;
// }