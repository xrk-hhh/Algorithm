// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

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

//     int size(int x)
//     {
//         return sz[find(x)];
//     }

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
//         int n, m, p, q;
//         cin>>n>>m>>p>>q;

//         DSU dsu1(n);
//         DSU dsu2(m);

//         for (int i = 0; i < p; i++)
//         {
//             int x, y;
//             cin>>x>>y;

//             dsu1.unite(x, y);
//         }
//         for (int i = 0; i < q; i++)
//         {
//             int x, y;
//             cin>>x>>y;

//             // 此时 x 和 y 为负数，需要转为正数
//             dsu2.unite(-x, -y);
//         }
        
//         // 看 P 公司的小明（编号为 1）的朋友数量 和 Q 公司的小红(编号为 -1)的朋友数量
//         // 要求配成情侣（异性一一配对），即两者最小值
//         int ans = min(dsu1.size(1), dsu2.size(1));

//         cout<<ans<<endl;
//     }

//     return 0;
// }