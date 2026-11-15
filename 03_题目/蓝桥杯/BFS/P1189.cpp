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
//         int r, c;
//         cin>>r>>c;

//         vector<string> g(r);
//         for (int i = 0; i < r; i++)
//         {
//             cin>>g[i];
//         }

//         int n;
//         cin>>n;

//         // 方向
//         vector<string> way(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>way[i];
//         }

//         // 当前位置
//         vector<pair<int, int>> cur;
//         for (int i = 0; i < r; i++)
//         {
//             for (int j = 0; j < c; j++)
//             {
//                 if (g[i][j] == '*')
//                 {
//                     cur.push_back({i, j});
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             string s = way[i];
//             // 下一个位置（用集合模拟，自动去重，且无需关心顺序）
//             set<pair<int, int>> nxt;
//             for (int j = 0; j < cur.size(); j++)
//             {
//                 auto [x, y] = cur[j];

//                 // 坐标偏移量
//                 int dx, dy;
//                 if (s == "NORTH")
//                 {
//                     dx = -1, dy = 0;
//                 }
//                 else if (s == "SOUTH")
//                 {
//                     dx = 1, dy = 0;
//                 }
//                 else if (s == "WEST")
//                 {
//                     dx = 0, dy = -1;
//                 }
//                 else if (s == "EAST")
//                 {
//                     dx = 0, dy = 1;
//                 }

//                 int nx = x + dx, ny = y + dy;
//                 while (nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] != 'X')
//                 {
//                     nxt.insert({nx, ny});
//                     nx += dx;
//                     ny += dy;
//                 }
//             }
//             // 位置转移
//             cur.assign(nxt.begin(), nxt.end());
//         }

//         vector<string> ans = g;
//         for (int i = 0; i < r; i++)
//         {
//             for (int j = 0; j < c; j++)
//             {
//                 if (ans[i][j] != 'X')
//                 {
//                     ans[i][j] = '.';
//                 }
//             }
//         }
//         for (int i = 0; i < cur.size(); i++)
//         {
//             auto [x, y] = cur[i];
//             ans[x][y] = '*';
//         }
//         for (int i = 0; i < r; i++)
//         {
//             cout<<ans[i]<<endl;
//         }
//     }

//     return 0;
// }