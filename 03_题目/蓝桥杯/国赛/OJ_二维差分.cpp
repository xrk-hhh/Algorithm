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
//         int n, m, q;
//         cin>>n>>m>>q;

//         vector<vector<int>> a(n + 1, vector<int>(m + 1));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 cin>>a[i][j];
//             }
//         }

//         // 二维差分
//         vector<vector<ll>> t(n + 2, vector<ll>(m + 2, 0));
//         while (q--)
//         {
//             int x1, y1, x2, y2, d;
//             cin>>x1>>y1>>x2>>y2>>d;

//             t[x1][y1] += d;
//             t[x1][y2 + 1] -= d;
//             t[x2 + 1][y1] -= d;
//             t[x2 + 1][y2 + 1] += d;
//         }

//         // 还原,即二维前缀和
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 t[i][j] += t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1];

//                 cout<<a[i][j] + t[i][j]<<' ';
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }