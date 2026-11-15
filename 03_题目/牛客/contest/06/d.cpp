// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define fi first
// #define se second

// const ll INF = 0x3f3f3f3f3f3f3f3f;

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
//         int n, m, a, b;
//         cin>>n>>m>>a>>b;

//         vector<vector<ll>> dist(n, vector<ll>(m, INF));
//         vector<vector<int>> tp(n, vector<int>(m, 0));
//         vector<vector<ll>> t(n, vector<ll>(m, 0));
//         priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> pq;

//         for (int i = 0; i < a; i++)
//         {
//             int x, y;
//             cin>>x>>y;

//             dist[x - 1][y - 1] = 0;
//             tp[x - 1][y - 1] = 1;
//             pq.push({0, {x - 1, y - 1}});
//         }

//         for (int i = 0; i < b; i++)
//         {
//             int x, y;
//             ll time;
//             cin>>x>>y>>time;

//             tp[x - 1][y - 1] = 2;
//             t[x - 1][y - 1] = time;
//         }

//         while (!pq.empty())
//         {
//             auto [d, pos] = pq.top();
//             pq.pop();

//             int x = pos.fi, y = pos.se;

//             if (d != dist[x][y])
//             {
//                 continue;
//             }

//             for (int k = 0; k < 4; k++)
//             {
//                 int nx = x + dx[k];
//                 int ny = y + dy[k];

//                 if (nx < 0 || nx >= n || ny < 0 || ny >= m)
//                 {
//                     continue;
//                 }

//                 if (tp[nx][ny] == 2)
//                 {
//                     ll nd = max(d + 1, t[nx][ny]);

//                     if (nd < dist[nx][ny])
//                     {
//                         dist[nx][ny] = nd;
//                         pq.push({nd, {nx, ny}});
//                     }
//                 }
//                 else
//                 {
//                     ll nd = d + 1;

//                     if (nd < dist[nx][ny])
//                     {
//                         dist[nx][ny] = nd;
//                         pq.push({nd, {nx, ny}});
//                     }
//                 }
//             }
//         }

//         ll ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 ans = max(ans, dist[i][j]);
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }