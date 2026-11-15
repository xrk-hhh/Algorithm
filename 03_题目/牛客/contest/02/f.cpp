// // #include <bits/stdc++.h>
// // using namespace std;

// // #define ll long long
// // #define endl '\n'
// // #define pr pair<ll, ll>

// // const int mod = 1e9 + 7;

// // ll gcd(ll a, ll b)
// // {
// //     while (b)
// //     {
// //         ll tmp = b;
// //         b = a % b;
// //         a = tmp;
// //     }
// //     return a;
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T;
// //     cin>>T;

// //     while (T--)
// //     {
// //         ll n;
// //         cin>>n;

// //         ll p = 1LL << 32;
// //         ll x = n * p;
// //         ll y = x ^ n;

// //         cout<<x<<' '<<y<<endl;
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'

// const int mod = 1e9 + 7; 

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         ll n;
//         cin>>n;

//         ll L = 1;
//         while (L <= n)
//         {
//             L <<= 1;
//         }

//         ll x = n * L;
//         ll y = n * (L + 1);

//         cout<<x<<' '<<y<<endl;
//     }

//     return 0;
// }