// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         ll x, y, z;
//         cin>>x>>y>>z;

//         ll ans;
//         if (z == 0)
//         {
//             ans = y + (x >= 1 ? 1 : 0);
//         }
//         else
//         {
//             ll t = (y << 1) + (z << 1) - 1;
//             ll maxx = 0, maxk = min(x, z - 1);
//             for (ll k = 0; k <= maxk; k++)
//             {
//                 ll r = x - k;
//                 ll p = 0;
//                 if (r >= 1)
//                 {
//                     p += 2;
//                 }
//                 if (r >= 2)
//                 {
//                     p += 1;
//                 }

//                 maxx = max(maxx, k + p);
//             }

//             ans = t + maxx;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }