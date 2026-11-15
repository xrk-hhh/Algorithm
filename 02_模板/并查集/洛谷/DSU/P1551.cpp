// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;


// // 并查集板子
// struct DSU
// {
//     vector<int> parent, sz;
//     DSU(int n)
//     {
//         parent.resize(n + 1);
//         sz.resize(n + 1, 1);
//         for (int i = 1; i <= n; i++)
//         {
//             parent[i] = i;
//         }
//     }

//     int find(int x)
//     {
//         return parent[x] == x ? x : parent[x] = find(parent[x]);
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

//         parent[y] = x;
//         sz[x] += sz[y];
//     }

//     // int size(int x)
//     // {
//     //     return sz[find(x)];
//     // }

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
//         int n, m, p;
//         cin>>n>>m>>p;

//         DSU dsu(n);

//         // 合并
//         while (m--)
//         {
//             int m1, m2;
//             cin>>m1>>m2;

//             dsu.unite(m1, m2);
//         }

//         // 查询是否在同一集合内
//         while (p--)
//         {
//             int p1, p2;
//             cin>>p1>>p2;

//             if (dsu.same(p1, p2))
//             {
//                 cout<<"Yes"<<endl;
//             }
//             else
//             {
//                 cout<<"No"<<endl;
//             }
//         }
//     }

//     return 0;
// }