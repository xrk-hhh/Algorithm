// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int dx[] = {-2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 2};
// int dy[] = {0, -1, 0, 1, -2, -1, 0, 1, 2, -1, 0, 1, 0};

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

//         vector<vector<ll>> a(n, vector<ll>(m));

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 cin>>a[i][j];
//             }
//         }

//         vector<vector<ll>> sum(n, vector<ll>(m));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 int cnt = 0;
//                 for (int k = 0; k < 13; k++)
//                 {
//                     int nx = i + dx[k];
//                     int ny = j + dy[k];
//                     if (nx >= 0 && nx < n && ny >= 0 && ny < m)
//                     {
//                         cnt += a[nx][ny];
//                     }
//                 }
//                 sum[i][j] = cnt;
//             }
//         }

//         ll maxx = -1;
//         int xx = 0, yy = 0;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (sum[i][j] > maxx)
//                 {
//                     maxx = sum[i][j];
//                     xx = i;
//                     yy = j;
//                 }
//             }
//         }

//         while (q--)
//         {
//             int x, y, z;
//             cin>>x>>y>>z;

//             for (int k = 0; k < 13; k++)
//             {
//                 int nx = x - 1 + dx[k];
//                 int ny = y - 1 + dy[k];
//                 if (nx >= 0 && nx < n && ny >= 0 && ny < m)
//                 {
//                     sum[nx][ny] += z;

//                     if (sum[nx][ny] > maxx)
//                     {
//                         maxx = sum[nx][ny];
//                         xx = nx;
//                         yy = ny;
//                     }
//                 }
//             }

//             cout<<xx + 1<<' '<<yy + 1<<endl;
//         }
//     }

//     return 0;
// }