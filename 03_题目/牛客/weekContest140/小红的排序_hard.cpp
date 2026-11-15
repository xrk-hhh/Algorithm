// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

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
//     cin>>T;

//     while (T--)
//     {
//         int n, x, y;
//         cin>>n>>x>>y;

//         vector<int> p(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>p[i];
//         }

//         DSU dsu(n);
//         for (int i = 1; i <= n; i++)
//         {
//             if (i + x <= n)
//             {
//                 dsu.unite(i, i + x);
//             }
//             if (i + y <= n)
//             {
//                 dsu.unite(i, i + y);
//             }
//         }

//         bool ok = true;
//         for (int i = 1; i <= n; i++)
//         {
//             if (dsu.find(i) != dsu.find(p[i]))
//             {
//                 ok = false;
//                 break;
//             }
//         }
        
//         if (!ok)
//         {
//             cout<<"No"<<endl;
//             continue;
//         }
//         else
//         {
//             cout<<"Yes"<<endl;
//         }
//     }

//     return 0;
// }