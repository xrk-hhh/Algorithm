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
//         int n, m;
//         cin>>n>>m;

//         vector<string> g(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>g[i];
//         }

//         ll ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (i + 1 < n && j + 1 < m)
//                 {
//                     if (g[i][j] != g[i][j + 1] && g[i][j] != g[i + 1][j] && g[i][j + 1] != g[i + 1][j])
//                     {
//                         ans++;
//                     }
//                     if (g[i][j] != g[i][j + 1] && g[i][j] != g[i + 1][j + 1] && g[i][j + 1] != g[i + 1][j + 1])
//                     {
//                         ans++;
//                     }
//                     if (g[i][j] != g[i + 1][j] && g[i][j] != g[i + 1][j + 1] && g[i + 1][j] != g[i + 1][j + 1])
//                     {
//                         ans++;
//                     }
//                     if (g[i][j + 1] != g[i + 1][j] && g[i][j + 1] != g[i + 1][j + 1] && g[i + 1][j] != g[i + 1][j + 1])
//                     {
//                         ans++;
//                     }
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }