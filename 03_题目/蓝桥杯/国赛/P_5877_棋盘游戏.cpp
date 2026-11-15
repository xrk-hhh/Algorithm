// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int dx[] = {-1, 0, 0, 1};
// const int dy[] = {0, -1, 1, 0};

// // 并查集模板
// struct DSU
// {
//     vector<int> fa, sz;
//     DSU(int n)
//     {
//         fa.resize(n + 1);
//         sz.resize(n + 1, 1);
//         for (int i = 1; i <= n; i++)
//         {
//             fa[i] = i;
//         }
//     }

//     int find(int x)
//     {
//         return fa[x] == x ? x : fa[x] = find(fa[x]);
//     }

//     bool unite(int x, int y)
//     {
//         x = find(x), y = find(y);
//         if (x == y)
//         {
//             return false;
//         }

//         if (sz[x] < sz[y])
//         {
//             swap(x, y);
//         }

//         fa[y] = x;
//         sz[x] += sz[y];
//         return true;
//     }

//     // int size(int x)
//     // {
//     //     return sz[find(x)];
//     // }

//     // bool same(int x, int y)
//     // {
//     //     return find(x) == find(y);
//     // }
// };

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

//         DSU dsu(n * n);
//         vector<vector<int>> g(n + 1, vector<int>(n + 1, -1));
//         // 当前棋盘中连通块数
//         int ans = 0;
//         for (int i = 0; i < m; i++)
//         {
//             int c, x, y;
//             cin>>c>>x>>y;
//             // 加入一个棋子，多一个连通块
//             ans++;

//             g[x][y] = c;
//             for (int k = 0; k < 4; k++)
//             {
//                 int nx = x + dx[k], ny = y + dy[k];
//                 if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && g[nx][ny] == g[x][y])
//                 {
//                     // 合并成功，连通块数量减一
//                     if (dsu.unite((nx - 1) * n + ny, (x - 1) * n + y))
//                     {
//                         ans--;
//                     }
//                 }
//             }

//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }