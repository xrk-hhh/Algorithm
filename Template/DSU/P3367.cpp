// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 并查集模板
// struct DSU
// {
//     vector<int> parent, sz;
//     // 初始化
//     DSU(int n)
//     {
//         parent.resize(n + 1);
//         sz.resize(n + 1, 1);
//         for (int i = 1; i <= n; i++)
//         {
//             parent[i] = i;
//         }
//     }

//     // 查找
//     int find(int x)
//     {
//         return parent[x] == x ? x : parent[x] = find(parent[x]);
//     }

//     // 合并
//     void unite(int x, int y)
//     {
//         x = find(x), y = find(y);
//         if (x == y)
//         {
//             return;
//         }

//         if (sz[x] < sz[y])
//         {
//             swap(x, y);
//         }

//         parent[y] = x;
//         sz[x] += sz[y];
//     }

//     // // 获得集合大小
//     // int size(int x)
//     // {
//     //     return sz[find(x)];
//     // }

//     // 判断是否在同一个集合内
//     bool same(int x, int y)
//     {
//         return find(x) == find(y);
//     }
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

//         DSU dsu(n);

//         while (m--)
//         {
//             int z, x ,y;
//             cin>>z>>x>>y;

//             if (z == 1)
//             {
//                 dsu.unite(x, y);
//             }
//             else if (z == 2)
//             {
//                 if (dsu.same(x, y))
//                 {
//                     cout<<'Y'<<endl;
//                 }
//                 else
//                 {
//                     cout<<'N'<<endl;
//                 }
//             }
//         }
//     }

//     return 0;
// }