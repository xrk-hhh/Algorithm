// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

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
//         a = a * a % p;
//         b >>= 1;
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
//         ll a, b, p;
//         cin>>a>>b>>p;

//         ll ans = ksm(a, b, p);

//         cout<<a<<"^"<<b<<" "<<"mod "<<p<<"="<<ans<<endl;
//     }

//     return 0;
// }