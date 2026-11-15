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
//         int n;
//         cin>>n;

//         vector<vector<ll>> a(n, vector<ll>(n));

//         ll total = 0;
//         vector<ll> rsum(n, 0), csum(n, 0);
//         ll sum1 = 0, sum2 = 0;

//         for (int i = 0 ; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cin>>a[i][j];
//                 total += a[i][j];
//                 rsum[i] += a[i][j];
//                 csum[j] += a[i][j];

//                 if (!((i + j) & 1))
//                 {
//                     sum1 += a[i][j];
//                 }
//                 else
//                 {
//                     sum2 += a[i][j];
//                 }
//             }
//         }

//         if (total % (1LL * n * n) != 0)
//         {
//             cout<<"No"<<endl;
//             return 0;
//         }

//         ll c = total / (1LL * n * n);

//         for (int i = 0; i < n; i++)
//         {
//             if ((rsum[i] - n * c) & 1)
//             {
//                 cout<<"No"<<endl;
//                 return 0;
//             }
//         }
//         for (int j = 0; j < n; j++)
//         {
//             if ((csum[j] - n * c) & 1)
//             {
//                 cout<<"No"<<endl;
//                 return 0;
//             }
//         }

//         if (!(n & 1))
//         {
//             if (sum1 != sum2)
//             {
//                 cout<<"No"<<endl;
//                 return 0;
//             }
//         }
//         else
//         {
//             ll cnt1 = (1LL * n * n + 1) / 2;
//             ll cnt2 = (1LL * n * n - 1) / 2;
            
//             if (sum1 * cnt2 != sum2 * cnt1)
//             {
//                 cout<<"No"<<endl;
//                 return 0;
//             }
//         }

//         cout<<"Yes"<<endl;
//     }

//     return 0;
// }