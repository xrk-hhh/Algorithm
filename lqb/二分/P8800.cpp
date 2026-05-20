// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n;
// ll m;
// vector<int> a(n), b(n);

// bool check(ll x)
// {
//     ll cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] < x)
//         {
//             ll t = x - a[i];
//             if (b[i] >= t)
//             {
//                 cnt += t;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         if (cnt > m)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n>>m;

//         a.resize(n);
//         b.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin>>b[i];
//         }

//         ll l = 0, r = n + m + 1;
//         while (l < r)
//         {
//             ll mid = (l + r + 1) >> 1;
//             if (check(mid))
//             {
//                 l = mid;
//             }
//             else
//             {
//                 r = mid - 1;
//             }
//         }

//         cout<<r<<endl;
//     }

//     return 0;
// }