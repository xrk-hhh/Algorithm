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
//         int n, k;
//         cin>>n>>k;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         auto check = [&](int x) -> bool
//         {
//             ll y = 0;
//             for (int i = 0; i < n; i++)
//             {
//                 y += a[i] / x;
//             }
//             return y >= k;
//         };

//         int l = 0, r = 1e8 + 1;
//         while (l + 1 < r)
//         {
//             int mid = (l + r) >> 1;
//             if (check(mid))
//             {
//                 l = mid;
//             }
//             else
//             {
//                 r = mid;
//             }
//         }

//         cout<<l<<endl;
//     }

//     return 0;
// }