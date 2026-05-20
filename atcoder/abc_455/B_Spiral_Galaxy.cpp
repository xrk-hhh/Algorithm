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

//         int ans = 0;
//         for (int i1 = 0; i1 < n; i1++)
//         {
//             for (int j1 = 0; j1 < m; j1++)
//             {
//                 for (int i2 = i1; i2 < n; i2++)
//                 {
//                     for (int j2 = j1; j2 < m; j2++)
//                     {
//                         bool ok = true;
//                         for (int i = i1; i <= i2; i++)
//                         {
//                             for (int j = j1; j <= j2; j++)
//                             {
//                                 if (g[i][j] != g[i1 + i2 - i][j1 + j2 - j])
//                                 {
//                                     ok = false;
//                                     break;
//                                 }
//                             }
//                         }

//                         if (ok)
//                         {
//                             ans++;
//                         }
//                     }
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }