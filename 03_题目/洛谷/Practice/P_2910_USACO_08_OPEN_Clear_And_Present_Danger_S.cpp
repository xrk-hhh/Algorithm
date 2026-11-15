// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const ll INF = 1e18;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m;
//         cin>>n>>m;

//         vector<int> a(m);
//         for (int i = 0; i < m; i++)
//         {
//             cin>>a[i];
//         }

//         vector<vector<ll>> d(n + 1, vector<ll>(n + 1, INF));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 cin>>d[i][j];
//             }
//         }

//         // Floyd-Warshall 求任意两点最短路
//         for (int k = 1; k <= n; k++)
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 for (int j = 1; j <= n; j++)
//                 {
//                     if (d[i][k] + d[k][j] < d[i][j])
//                     {
//                         d[i][j] = d[i][k] + d[k][j];
//                     }
//                 }
//             }
//         }

//         ll ans = 0;
//         for (int i = 0; i < m - 1; i++)
//         {
//             ans += d[a[i]][a[i + 1]];
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }