// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, p;
//         cin>>n>>p;

//         vector<ll> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         vector<ll> sum(n + 1, 0);
//         for (int i = 0; i < n; i++)
//         {
//             sum[i + 1] = (sum[i] + a[i]) % p;
//         }

//         set<pair<ll, int>> s;
//         s.insert({sum[0], 0});

//         ll ans = -1;
//         int al = 0, ar = 0;
//         for (int r = 1; r <= n  ; r++)
//         {
//             ll cur = sum[r];

//             if ((!s.empty()) && (s.begin()->first <= cur))
//             {
//                 ll cand = cur - s.begin()->first;
//                 if (cand > ans)
//                 {
//                     ans = cand;
//                     al = s.begin()->second;
//                     ar = r - 1;
//                 }
//             }

//             auto it = s.lower_bound({cur + 1, 0});
//             if (it != s.end())
//             {
//                 ll cand = p - (it->first - cur);
//                 if (cand > ans)
//                 {
//                     ans = cand;
//                     al = it->second;
//                     ar = r - 1;
//                 }
//             }

//             s.insert({cur, r});
//         }

//         cout<<al<<' '<<ar<<' '<<ans<<endl;
//     }

//     return 0;
// }