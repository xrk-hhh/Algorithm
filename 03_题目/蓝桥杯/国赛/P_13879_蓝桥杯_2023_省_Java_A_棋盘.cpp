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

//         // 二维差分
//         vector<vector<int>> d(n + 2, vector<int>(n + 2, 0));
//         for (int i = 0; i < m; i++)
//         {
//             int x1, y1, x2, y2;
//             cin>>x1>>y1>>x2>>y2;

//             d[x1][y1]++;
//             d[x1][y2 + 1]--;
//             d[x2 + 1][y1]--;
//             d[x2 + 1][y2 + 1]++;
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];

//                 if (d[i][j] & 1)
//                 {
//                     cout<<1;
//                 }
//                 else
//                 {
//                     cout<<0;
//                 }
//             }
//             cout<<endl;
//         }

//         // // 取反，也可直接用 异或1
//         // vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
//         // vector<vector<int>> d(n + 2, vector<int>(n + 2, 0));
//         // for (int i = 0; i < m; i++)
//         // {
//         //     int x1, y1, x2, y2;
//         //     cin>>x1>>y1>>x2>>y2;

//         //     d[x1][y1] ^= 1;
//         //     d[x1][y2 + 1] ^= 1;
//         //     d[x2 + 1][y1] ^= 1;
//         //     d[x2 + 1][y2 + 1] ^= 1;
//         // }

//         // for (int i = 1; i <= n; i++)
//         // {
//         //     for (int j = 1; j <= n; j++)
//         //     {
//         //         g[i][j] = d[i][j] ^ g[i - 1][j - 1] ^ g[i - 1][j] ^ g[i][j - 1];
//         //     }
//         // }

//         // for (int i = 1; i <= n; i++)
//         // {
//         //     for (int j = 1; j <= n; j++)
//         //     {
//         //         cout<<g[i][j];
//         //     }
//         //     cout<<endl;
//         // }
//     }

//     return 0;
// }