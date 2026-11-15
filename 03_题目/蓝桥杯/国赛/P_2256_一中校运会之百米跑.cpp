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
//         // map存 名字和编号
//         unordered_map<string, int> mp;
//         for (int i = 1; i <= n; i++)
//         {
//             string s;
//             cin>>s;

//             mp[s] = i;
//         }

//         for (int i = 0; i < m; i++)
//         {
//             string s1, s2;
//             cin>>s1>>s2;

//             dsu.unite(mp[s1], mp[s2]);
//         }

//         int k;
//         cin>>k;

//         while (k--)
//         {
//             string s1, s2;
//             cin>>s1>>s2;

//             // 看是否在同一个环中
//             if (dsu.same(mp[s1], mp[s2]))
//             {
//                 cout<<"Yes."<<endl;
//             }
//             else
//             {
//                 cout<<"No."<<endl;
//             }
//         }
//     }

//     return 0;
// }