// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define pii pair<int, int>
// #define fi first
// #define se second

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, q, s;
//         cin>>n>>q>>s;

//         vector<int> cnt(n);
//         int tmp = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (i == 0)
//             {
//                 cnt[i] = s;
//             }
//             else
//             {
//                 cnt[i] = cnt[i - 1] + tmp;
//             }
//             int t;
//             cin>>t;
//             tmp = t;
//         }

//         vector<pii> p(q);
//         for (int i = 0; i < q; i++)
//         {
//             int x, y;
//             cin>>x>>y;
//             p[i].fi = x;
//             p[i].se = y; 
//         }

//         for (int i = 0; i < q; i++)
//         {
//             int ans = cnt[p[i].fi - 1] + p[i].se - 1;
//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }