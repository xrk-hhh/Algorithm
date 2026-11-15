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
//         cout<<fixed<<setprecision(2);
//         double a, b, c, d;
//         cin>>a>>b>>c>>d;

//         auto f = [&](double x) -> double
//         {
//             return a * x * x * x + b * x * x + c * x + d;
//         };

//         for (int i = -100; i < 100; i++)
//         {
//             double y1 = f(1.0 * i), y2 = f(1.0 * (i + 1));

//             if (!y1)
//             {
//                 cout<<1.0 * i<<' ';
//             }

//             if (y1 * y2 < 0)
//             {
//                 double l = 1.0 * i, r = 1.0 * (i + 1);
//                 while (r - l > 1e-5)
//                 {
//                     double mid = (l + r) / 2;
//                     if (f(mid) * f(r) < 0)
//                     {
//                         l = mid;
//                     }
//                     else
//                     {
//                         r = mid;
//                     }
//                 }

//                 cout<<l<<' ';
//             }
//         }
//         cout<<endl;
//     }

//     return 0;
// }