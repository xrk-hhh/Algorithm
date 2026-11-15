// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 并查集
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

//         fa[y] = x;
//         sz[x] += sz[y];
//     }

//     int size(int x)
//     {
//         return sz[find(x)];
//     }

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
//             int z, x, y;
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