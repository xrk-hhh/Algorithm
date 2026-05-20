// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// ll rnum(ll x)
// {
//     ll res = 0;
//     while (x)
//     {
//         res = res * 10 + x % 10;
//         x /= 10;
//     }
//     return res;
// }

// int cnt(ll x)
// {
//     if (x == 0)
//     {
//         return 1;
//     }
//     int ans = 0;
//     while (x)
//     {
//         ans++;
//         x /= 10;
//     }
//     return ans;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin>>T;

//     while(T--)
//     {
//         ll l, r;
//         cin>>l>>r;

//         ll maxx = 0;

//         for (int i = 1; i <= cnt(r); i++)
//         {
//             ll xx = 1;
//             for (int j = 0; j < i; j++)
//             {
//                 xx *= 10;
//             }
//             ll t = xx - 1;

//             ll x1 = ((l + xx - 1 - t) / xx) * xx + t;
//             ll x2 = (r - t) / xx * xx + t;

//             if (x1 > x2 || x2 < l || x2 > r)
//             {
//                 continue;
//             }

//             ll tmp0 = rnum(x2);
//             if (tmp0 > maxx)
//             {
//                 maxx = tmp0;
//             }
//         }

//         ll tmp1 = rnum(r);
//         if (tmp1 > maxx)
//         {
//             maxx = tmp1;
//         }

//         ll tmp2 = rnum(l);
//         if (tmp2 > maxx)
//         {
//             maxx = tmp2;
//         }

//         cout<<maxx<<endl;
//     }

//     return 0;
// }