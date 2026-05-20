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
//         int n;
//         cin>>n;

//         vector<string> g(n);
//         for (int i = 0 ; i < n; i++)
//         {
//             cin>>g[i];
//         }

//         vector<vector<bool>> vis(n, vector<bool>(n, false));
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 // 当前是陆地且未访问过
//                 if (g[i][j] == '#' && !vis[i][j])
//                 {
//                     queue<pair<int, int>> q;
//                     q.push({i, j});
//                     vis[i][j] = true;
//                     // 看看是否能被淹没
//                     bool ok = true;
//                     // BFS遍历
//                     while (!q.empty())
//                     {
//                         auto [x, y] = q.front();
//                         q.pop();

//                         // 看看是否安全
//                         bool safe = true;
//                         for (int k = 0; k < 4; k++)
//                         {
//                             int nx = x + dx[k], ny = y + dy[k];
//                             // 四周是边界或者有海洋
//                             if (nx < 0 || nx >= n || ny < 0 || ny >= n || g[nx][ny] == '.')
//                             {
//                                 safe = false;
//                                 break;
//                             }
//                         }

//                         // 安全，即不会被淹没
//                         if (safe)
//                         {
//                             ok = false;
//                         }

//                         // 标记一下连通块
//                         for (int k = 0; k < 4; k++)
//                         {
//                             int nx = x + dx[k], ny = y + dy[k];
//                             if (nx >= 0 && nx < n && ny >= 0 && ny < n && g[nx][ny] == '#' && !vis[nx][ny])
//                             {
//                                 vis[nx][ny] = true;
//                                 q.push({nx, ny});
//                             }
//                         }
//                     }
                    
//                     // 能被淹没，答案加一
//                     if (ok)
//                     {
//                         ans++;
//                     }
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }