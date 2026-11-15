// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 并查集模板
// struct DSU
// {
//     vector<int> fa, sz;
//     int cnt;
//     DSU(int n)
//     {
//         fa.resize(n + 1);
//         sz.resize(n + 1, 1);
//         cnt = n;
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
//         cnt--;
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
//         while (cin>>n>>m)
//         {
//             DSU dsu(n);
//             for (int i = 0; i < m; i++)
//             {
//                 int u, v;
//                 cin>>u>>v;

//                 dsu.unite(u, v);
//             }

//             // 需要再修的道路，即：将不相连的环相连
//             cout<<dsu.cnt - 1<<endl;
//         }
//     }

//     return 0;
// }