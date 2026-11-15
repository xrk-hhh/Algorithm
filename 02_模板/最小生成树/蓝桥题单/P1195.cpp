// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// struct Edge
// {
//     int u, v, w;
// };

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

// bool cmp(const Edge& a, const Edge& b)
// {
//     return a.w < b.w;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m, k;
//         cin>>n>>m>>k;

//         vector<Edge> edge(m);
//         for (int i = 0; i < m; i++)
//         {
//             cin>>edge[i].u>>edge[i].v>>edge[i].w;
//         }

//         sort(edge.begin(), edge.end(), cmp);

//         DSU dsu(n);
//         int cnt = n;
//         int ans = 0;
//         for (auto& e : edge)
//         {
//             // 注意需要特判：n == k时，即不需要合并
//             if (cnt == k)
//             {
//                 break;
//             }
//             if (dsu.unite(e.u, e.v))
//             {
//                 ans += e.w;
//                 cnt--;
//             }
//         }

//         if (cnt == k)
//         {
//             cout<<ans<<endl;
//         }
//         else
//         {
//             cout<<"No Answer"<<endl;
//         }
//     }

//     return 0;
// }