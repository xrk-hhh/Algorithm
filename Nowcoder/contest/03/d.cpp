// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define pr pair<int, int>
// #define fi first
// #define se second

// int dx[] = {-1, 1, 0, 0};
// int dy[] = {0, 0, -1, 1};

// bool check(int n, int m, vector<string> s, pr st, pr t, char c)
// {
//     vector<vector<bool>> vis(n, vector<bool>(m, false));

//     queue<pr> q;
//     q.push(st);
//     vis[st.fi][st.se] = true;

//     while (!q.empty())
//     {
//         pr cur = q.front();
//         q.pop();
//         if (cur == t)
//         {
//             return true;
//         }

//         for (int k = 0; k < 4; k++)
//         {
//             int nx = cur.fi + dx[k];
//             int ny = cur.se + dy[k];

//             if (nx < 0 || nx >= n || ny < 0 || ny >= m)
//             {
//                 continue;
//             }
//             if (vis[nx][ny] || s[nx][ny] == c)
//             {
//                 continue;
//             }

//             vis[nx][ny] = true;
//             q.push({nx, ny});
//         }
//     }
//     return false;
// }

// vector<pr> bfs(int n, int m, vector<string> s, pr st, pr t, char c)
// {
//     vector<vector<bool>> vis(n, vector<bool>(m, false));
//     vector<vector<pr>> pre(n, vector<pr>(m, {-1, -1}));

//     queue<pr> q;
//     q.push(st);

//     vis[st.fi][st.se] = true;
//     while (!q.empty())
//     {
//         pr cur = q.front();
//         q.pop();
//         if (cur == t)
//         {
//             vector<pr> p;
//             pr tmp = t;
//             while (tmp != st)
//             {
//                 p.push_back(tmp);
//                 tmp = pre[tmp.fi][tmp.se];
//             }
//             p.push_back(st);
//             reverse(p.begin(), p.end());
//             return p;
//         }
//         for (int k = 0; k < 4; k++)
//         {
//             int nx = cur.fi + dx[k];
//             int ny = cur.se + dy[k];

//             if (nx < 0 || nx >= n || ny < 0 || ny >= m)
//             {
//                 continue;
//             }
//             if (vis[nx][ny] || s[nx][ny] == c)
//             {
//                 continue;
//             }

//             vis[nx][ny] = true;
//             pre[nx][ny] = cur;
//             q.push({nx, ny});
//         }
//     }
//     return {};
// }

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

//         vector<string> s(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>s[i];
//         }

//         vector<pr> one, two;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (s[i][j] == '1')
//                 {
//                     one.push_back({i, j});
//                 }
//                 else if (s[i][j] == '2')
//                 {
//                     two.push_back({i, j});
//                 }
//             }
//         }

//         pr st1 = one[0], t1 = one[1];
//         pr st2 = two[0], t2 = two[1];

//         if (!check(n, m, s, st1, t1, '2') || !check(n, m, s, st2, t2, '1'))
//         {
//             cout<<"NO"<<endl;
//             continue;
//         }

//         auto p1 = bfs(n, m, s, st1, t1, '2');
//         set<pr> ocp;
//         for (auto& p : p1)
//         {
//             if (s[p.fi][p.se] == '0')
//             {
//                 ocp.insert(p);
//             }
//         }

//         vector<string> tmp = s;
//         for (auto& p : ocp)
//         {
//             tmp[p.fi][p.se] = 'x';
//         }

//         if (check(n, m, tmp, st2, t2, '1'))
//         {
//             cout<<"YES"<<endl;
//             continue;
//         }

//         ocp.clear();

//         auto p2 = bfs(n, m, s, st2, t2, '1');
//         for (auto& p : p2)
//         {
//             if (s[p.fi][p.se] == '0')
//             {
//                 ocp.insert(p);
//             }
//         }

//         tmp = s;
//         for (auto& p : ocp)
//         {
//             tmp[p.fi][p.se] = 'x';
//         }

//         if (check(n, m, tmp, st1, t1, '2'))
//         {
//             cout<<"YES"<<endl;
//             continue;
//         }

//         cout<<"NO"<<endl;
//     }

//     return 0;
// }