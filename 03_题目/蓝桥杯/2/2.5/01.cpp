// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int dx[] = {-1, 1, 0, 0};
// int dy[] = {0, 0, -1, 1};

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<vector<int>> g(n, vector<int>(n));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cin>>g[i][j];
//             }
//         }

//         vector<vector<bool>> vis(n, vector<bool>(n, false));
//         queue<pair<int, int>> q;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
//                 {
//                     if (g[i][j] == 0 && !vis[i][j])
//                     {
//                         vis[i][j] = true;
//                         q.push({i, j});
//                     }
//                 }
//             }
//         }

//         while (!q.empty())
//         {
//             auto [x, y] = q.front();
//             q.pop();

//             for (int k = 0; k < 4; k++)
//             {
//                 int nx = x + dx[k];
//                 int ny = y + dy[k];
//                 if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && g[nx][ny] == 0)
//                 {
//                     vis[nx][ny] = true;
//                     q.push({nx, ny});
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (g[i][j] == 0 && !vis[i][j])
//                 {
//                     cout<<2<<' ';
//                 }
//                 else
//                 {
//                     cout<<g[i][j]<<' ';
//                 }
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }