// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int dx[] = {-1, 0, 0, 1};
// const int dy[] = {0, -1, 1, 0};

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m, a, b;
//         cin>>n>>m>>a>>b;

//         // 感染时间，即最短距离（多源）
//         vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
//         queue<pair<int, int>> q;
//         for (int i = 0; i < a; i++)
//         {
//             int x, y;
//             cin>>x>>y;

//             dist[x][y] = 0;
//             q.push({x, y});
//         }
        
//         // 多源BFS
//         while (!q.empty())
//         {
//             auto [x, y] = q.front();
//             q.pop();

//             for (int k = 0; k < 4; k++)
//             {
//                 int nx = x + dx[k], ny = y + dy[k];
//                 if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && dist[nx][ny] == -1)
//                 {
//                     dist[nx][ny] = dist[x][y] + 1;
//                     q.push({nx, ny});
//                 }
//             }
//         }

//         for (int i = 0; i < b; i++)
//         {
//             int x, y;
//             cin>>x>>y;

//             cout<<dist[x][y]<<endl;
//         }
//     }

//     return 0;
// }