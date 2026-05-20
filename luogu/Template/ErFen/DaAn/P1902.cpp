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
//         int n, m;
//         cin>>n>>m;

//         vector<vector<int>> p(n + 1, vector<int>(m + 1));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 cin>>p[i][j];
//             }
//         }

//         auto check = [&](int limit) -> bool
//         {
//             vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
//             queue<pair<int, int>> q;

//             for (int j = 1; j <= m; j++)
//             {
//                 vis[1][j] = true;
//                 q.push({1, j});
//             }

//             while (!q.empty())
//             {
//                 auto [x, y] = q.front();
//                 q.pop();

//                 for (int k = 0; k < 4; k++)
//                 {
//                     int nx = x + dx[k];
//                     int ny = y + dy[k];

//                     if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && p[nx][ny] <= limit)
//                     {
//                         vis[nx][ny] = true;
//                         q.push({nx, ny});
//                     }
//                 }
//             }

//             for (int j = 1; j <= m; j++)
//             {
//                 if (!vis[n][j])
//                 {
//                     return false;
//                 }
//             }
//             return true;
//         };

//         int l = -1, r = 1001;
//         while (l + 1 < r)
//         {
//             int mid = (l + r) >> 1;
            
//             if (check(mid))
//             {
//                 r = mid;
//             }
//             else
//             {
//                 l = mid;
//             }
//         }

//         cout<<r<<endl;
//     }

//     return 0;
// }