// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

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

//         double ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             int s = 1;
//             int t = i;
//             while (t < k)
//             {
//                 t *= 2;
//                 s *= 2;
//             }

//             double sum = 1.0 / s;
//             ans += sum;
//         }

//         double tt = 1.0 / n;
//         ans *= tt;
//         cout<<fixed<<setprecision(15)<<ans<<endl;
//     }

//     return 0;
// }