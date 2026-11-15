// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 马可移动的距离
// const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
// const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m, x, y;
//         cin>>n>>m>>x>>y;

//         queue<pair<int, int>> q;
//         vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
//         q.push({x, y});
//         dist[x][y] = 0;
//         // BFS遍历
//         while (!q.empty())
//         {
//             auto [xx, yy] = q.front();
//             q.pop();

//             for (int k = 0; k < 8; k++)
//             {
//                 int nx = xx + dx[k], ny = yy + dy[k];
//                 // 判断是否合法且未达过
//                 if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1)
//                 {
//                     dist[nx][ny] = dist[xx][yy] + 1;
//                     q.push({nx, ny});
//                 }
//             }
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 cout<<dist[i][j]<<' ';
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }