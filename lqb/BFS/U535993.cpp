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
//     cin>>T;

//     while (T--)
//     {
//         int n, m;
//         cin>>n>>m;

//         vector<string> g(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>g[i];
//         }

//         // 外层空白
//         vector<vector<bool>> blank(n, vector<bool>(m, false));
//         queue<pair<int, int>> q;
//         // 先标记边界空白
//         for (int i = 0; i < n; i++)
//         {
//             if (g[i][0] == '.')
//             {
//                 blank[i][0] = true;
//                 q.push({i, 0});
//             }

//             if (g[i][m - 1] == '.')
//             {
//                 blank[i][m - 1] = true;
//                 q.push({i, m - 1});
//             }
//         }
//         for (int j = 0; j < m; j++)
//         {
//             if (g[0][j] == '.')
//             {
//                 blank[0][j] = true;
//                 q.push({0, j});
//             }
            
//             if (g[n - 1][j] == '.')
//             {
//                 blank[n - 1][j] = true;
//                 q.push({n - 1, j});
//             }
//         }

//         // 再通过四连通进一步标记空白
//         while (!q.empty())
//         {
//             auto [x, y] = q.front();
//             q.pop();

//             for (int k = 0; k < 4; k++)
//             {
//                 int nx = x + dx[k], ny = y + dy[k];
//                 if (nx >= 0 && nx < n && ny >= 0 && ny < m && !blank[nx][ny] && g[nx][ny] == '.')
//                 {
//                     blank[nx][ny] = true;
//                     q.push({nx, ny});
//                 }
//             }
//         }

//         // 细胞壁
//         vector<vector<bool>> wall(n, vector<bool>(m, false));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (g[i][j] == '*')
//                 {
//                     // 最外层
//                     if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
//                     {
//                         wall[i][j] = true;
//                         continue;
//                     }

//                     // 与外界空白四连通
//                     for (int k = 0; k < 4; k++)
//                     {
//                         int nx = i + dx[k], ny = j + dy[k];
//                         if (nx >= 0 && nx < n && ny >= 0 && ny < m && blank[nx][ny])
//                         {
//                             wall[i][j] = true;
//                             break;
//                         }
//                     }
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 // 内部细胞器
//                 if (g[i][j] == '*' && !wall[i][j])
//                 {
//                     cout<<'*';
//                 }
//                 else
//                 {
//                     cout<<'.';
//                 }
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }