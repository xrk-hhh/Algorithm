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
//         while (cin>>n>>k, n)
//         {
//             vector<double> a(n), b(n), c(n);
//             for (int i = 0; i < n; i++)
//             {
//                 cin>>a[i];
//             }
//             for (int i = 0; i < n; i++)
//             {
//                 cin>>b[i];
//             }

//             auto check = [&](double x) -> bool
//             {
//                 double s = 0;
//                 for (int i = 0; i < n; i++)
//                 {
//                     c[i] = a[i] - b[i] * x;
//                 }

//                 sort(c.begin(), c.end());
                
//                 for (int i = k; i < n; i++)
//                 {
//                     s += c[i];
//                 }
//                 return s >= 0;
//             };

//             double l = 0, r = 1;
//             while (r - l > 1e-5)
//             {
//                 double mid = (l + r) / 2;
//                 if (check(mid))
//                 {
//                     l = mid;
//                 }
//                 else
//                 {
//                     r = mid;
//                 }
//             }
//             cout<<fixed<<setprecision(0)<<100 * l<<endl;
//         }
//     }

//     return 0;
// }