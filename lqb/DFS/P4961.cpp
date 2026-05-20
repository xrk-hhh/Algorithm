// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// int n, m;
// vector<vector<int>> g(n, vector<int>(m));
// vector<vector<bool>> vis;
// // 是否为空格
// vector<vector<bool>> isSpace;

// // DFS 统计连通块个数
// void dfs(int x, int y)
// {
//     vis[x][y] = true;
//     for (int k = 0; k < 8; k++)
//     {
//         int nx = x + dx[k];
//         int ny = y + dy[k];
//         if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && isSpace[nx][ny])
//         {
//             dfs(nx, ny);
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n>>m;

//         g.resize(n, vector<int>(m));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 cin>>g[i][j];
//             }
//         }

//         // 标记空格
//         isSpace.assign(n, vector<bool>(m, false));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 // 跳过雷
//                 if (g[i][j] == 1)
//                 {
//                     continue;
//                 }

//                 bool hasMine = false;
//                 for (int k = 0; k < 8; k++)
//                 {
//                     int nx = i + dx[k];
//                     int ny = j + dy[k];
//                     if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 1)
//                     {
//                         hasMine = true;
//                         break;
//                     }
//                 }

//                 if (!hasMine)
//                 {
//                     isSpace[i][j] = true;
//                 }
//             }
//         }

//         //  DFS 统计空格连通块
//         vis.assign(n, vector<bool>(m, false));
//         int spaceBlocks = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (isSpace[i][j] && !vis[i][j])
//                 {
//                     spaceBlocks++;
//                     dfs(i, j);
//                 }
//             }
//         }

//         // 统计孤立数字（周围无空格）
//         int lonelyDigits = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 // 跳过雷
//                 if (g[i][j] == 1)
//                 {
//                     continue;
//                 }

//                 // 是数字
//                 if (!isSpace[i][j])
//                 {
//                     bool hasSpace = false;
//                     for (int k = 0; k < 8; k++)
//                     {
//                         int nx = i + dx[k];
//                         int ny = j + dy[k];
//                         if (nx >= 0 && nx < n && ny >= 0 && ny < m && isSpace[nx][ny])
//                         {
//                             hasSpace = true;
//                             break;
//                         }
//                     }

//                     if (!hasSpace)
//                     {
//                         lonelyDigits++;
//                     }
//                 }
//             }
//         }

//         cout<<spaceBlocks + lonelyDigits<<endl;
//     }

//     return 0;
// }