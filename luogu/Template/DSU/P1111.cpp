// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// struct DSU
// {
//     vector<int> parent, sz;
//     int cnt;
//     DSU(int n)
//     {
//         parent.resize(n + 1);
//         sz.resize(n + 1, 1);
//         cnt = n;
//         for (int i = 1; i <= n; i++)
//         {
//             parent[i] = i;
//         }
//     }

//     int find(int x)
//     {
//         return parent[x] == x ? x : parent[x] = find(parent[x]);
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

//         parent[y] = x;
//         sz[x] += sz[y];

//         cnt--;
//         return true;
//     }

//     bool all_connected()
//     {
//         return cnt == 1;
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

// struct Edge
// {
//     int x, y, t;
// };

// bool cmp(const Edge& a, const Edge& b)
// {
//     return a.t < b.t;
// }

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

//         vector<Edge> edge(m);
//         for (int i = 0; i < m; i++)
//         {
//             cin>>edge[i].x>>edge[i].y>>edge[i].t;
//         }

//         // 按时间排序
//         sort(edge.begin(), edge.end(), cmp);

//         DSU dsu(n);

//         // 按时间先后合并
//         int ans = -1;
//         for (int i = 0; i < m; i++)
//         {
//             auto [x, y, t] = edge[i];
//             dsu.unite(x, y);

//             // 判断是否都已经合并为一个集合
//             if (dsu.all_connected())
//             {
//                 ans = t;
//                 break;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }