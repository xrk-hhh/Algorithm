// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define ld long double
// #define fi first
// #define se second

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, w;
//         cin>>n>>w;

//         vector<ll> x(n), y(n), t(n, 0);
//         vector<ld> cur(n);
//         priority_queue<pair<ld, int>> pq;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>x[i]>>y[i];
//             cur[i] = sqrtl((ld)(x[i] * x[i]) + (ld)(y[i] * y[i]));
//             ld tmp = sqrtl((ld)(x[i] * x[i]) + (ld)((y[i] - 1) * (y[i] - 1)));
//             pq.emplace(cur[i] - tmp, i);
//         }

//         int cnt = 0;
//         while (cnt < w && !pq.empty())
//         {
//             auto [m0, i] = pq.top();
//             pq.pop();

//             if (t[i] >= y[i])
//             {
//                 continue;
//             }

//             t[i]++;
//             cnt++;

//             cur[i] = sqrtl((ld)(x[i] * x[i]) + (ld)((y[i] - t[i]) * (y[i] - t[i])));

//             if (t[i] < y[i])
//             {
//                 ld tmp = sqrtl((ld)(x[i] * x[i]) + (ld)((y[i] - t[i] - 1) * (y[i] - t[i] - 1)));
//                 pq.emplace(cur[i] - tmp, i);
//             }
//         }

//         ld total = 0.0;
//         for (int i = 0; i < n; i++)
//         {
//             total += cur[i];
//         }

//         cout<<fixed<<setprecision(10)<<total<<endl;
//     }

//     return 0;
// }