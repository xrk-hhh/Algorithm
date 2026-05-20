// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

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

//         vector<string> g(n);
//         for (int i = 0;i < n; i++)
//         {
//             cin>>g[i];
//         }

//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         // 记录每种星系大小出现的次数
//         unordered_map<int, int> freq;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (g[i][j] == '*' && !vis[i][j])
//                 {
//                     queue<pair<int, int>> q;
//                     q.push({i, j});
//                     vis[i][j] = true;
//                     int cnt = 0;
//                     // BFS
//                     while (!q.empty())
//                     {
//                         auto [x, y] = q.front();
//                         q.pop();
//                         cnt++;
//                         for (int k = 0; k < 8; k++)
//                         {
//                             int nx = x + dx[k];
//                             int ny = y + dy[k];
//                             if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '*' && !vis[nx][ny])
//                             {
//                                 vis[nx][ny] = true;
//                                 q.push({nx, ny});
//                             }
//                         }
//                     }

//                     freq[cnt]++;
//                 }
//             }
//         }

//         int maxx = 0;
//         for (auto& p : freq)
//         {
//             // 星系大小 = 每个星座中星星数 * 星座数
//             maxx = max(maxx, p.first * p.second);
//         }

//         cout<<freq.size()<<' '<<maxx<<endl;
//     }

//     return 0;
// }