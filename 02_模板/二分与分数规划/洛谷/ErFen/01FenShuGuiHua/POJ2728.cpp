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

//         while (cin>>n && n)
//         {
//             vector<int> x(n + 1), y(n + 1), z(n + 1);
//             for (int i = 1; i <= n; i++)
//             {
//                 cin>>x[i]>>y[i]>>z[i];
//             }

//             auto cost = [&](int i, int j) -> double
//             {
//                 return abs(z[i] - z[j]);
//             };

//             auto len = [&](int i, int j) -> double
//             {
//                 return sqrt(1.0 * (x[i] - x[j]) * (x[i] - x[j]) + 1.0 * (y[i] - y[j]) * (y[i] - y[j]));
//             };

//             auto prim = [&](double res) -> bool
//             {
//                 vector<bool> vis(n + 1, false);
//                 vector<double> d(n + 1, 1e9);

//                 d[1] = 0;
//                 double sum = 0;

//                 for (int i = 1; i <= n; i++)
//                 {
//                     int t = -1;
//                     for (int j = 1; j <= n; j++)
//                     {
//                         if (!vis[j] && (t == -1 || d[j] < d[t]))
//                         {
//                             t = j;
//                         }
//                     }
//                     sum += d[t];
//                     vis[t] = true;

//                     for (int j= 1; j <= n; j++)
//                     {
//                         if (!vis[j] && cost(t, j) - res * len(t, j) < d[j])
//                         {
//                             d[j] = cost(t, j) - res * len(t, j);
//                         }
//                     }
//                 }
//                 return sum <= 0;
//             };

//             double l = 0, r = 1e6;
//             while (r - l > 1e-6)
//             {
//                 double mid = (l + r) / 2;
//                 if (prim(mid))
//                 {
//                     r = mid;
//                 }
//                 else
//                 {
//                     l = mid;
//                 }
//             }

//             cout<<fixed<<setprecision(3)<<r<<endl;
//         }
//     }

//     return 0;
// }