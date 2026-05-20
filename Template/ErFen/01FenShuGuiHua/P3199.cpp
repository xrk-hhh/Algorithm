// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int N = 3010;
// const double INF = 1e18;

// struct Edge
// {
//     int v;
//     double w;
// };

// vector<Edge> g[N];
// int n, m;

// double Karp()
// {
//     vector<vector<double>> dp(n + 1, vector<double>(n + 1, INF));
//     dp[0][1] = 0;

//     for (int k = 1;  k <= n; k++)
//     {
//         for (int u = 1; u <= n; u++)
//         {
//             if (dp[k - 1][u] < INF)
//             {
//                 for (auto& e : g[u])
//                 {
//                     int v = e.v;
//                     dp[k][v] = min(dp[k][v], dp[k - 1][u] + e.w);
//                 }
//             }
//         }
//     }

//     double ans = INF;

//     for (int v = 1; v <= n; v++)
//     {
//         if (dp[n][v] < INF)
//         {
//             double maxVal = -INF;
//             for (int k = 0; k < n; k++)
//             {
//                 if (dp[k][v] < INF)
//                 {
//                     double val = (dp[n][v] - dp[k][v]) / (n - k);
//                     if (val > maxVal)
//                     {
//                         maxVal = val;
//                     }
//                 }
//             }
//             ans = min(ans, maxVal);
//         }
//     }
//     return ans;
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

//         double l = 1e9, r = -1e9;
//         for (int i = 0; i < m; i++)
//         {
//             int u, v;
//             double w;
//             cin>>u>>v>>w;

//             g[u].push_back({v, w});
//         }

//         double res = Karp();

//         cout<<fixed<<setprecision(8)<<res<<endl;
//     }

//     return 0;
// }