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
//         int n, W;
//         cin>>n>>W;
//         vector<int> w(n + 1), t(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>w[i]>>t[i];
//         }

        
//         auto check = [&](double x) -> bool
//         {
//             vector<double> f(W + 1, -1e9);
//             f[0] = 0;

//             for (int i = 1; i <= n; i++)
//             {
//                 for (int j = W; j >= 0; j--)
//                 {
//                     int k = min(W, j + w[i]);

//                     f[k] = max(f[k], f[j] + t[i] - w[i] * x);
//                 }
//             }

//             return f[W] >= 0;
//         };
        

//         double l = 0, r = 1000;
//         while (r - l > 1e-5)
//         {
//             double mid = (l + r) / 2;
//             if (check(mid))
//             {
//                 l = mid;
//             }
//             else
//             {
//                 r = mid;
//             }
//         }

//         cout<<floor(1000 * r + 1e-8)<<endl;
//     }

//     return 0;
// }