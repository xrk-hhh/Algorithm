// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 5e5 + 10;
// const int LOG = 20;

// vector<int> g[N];
// // 记录节点深度
// int depth[N];
// int up[N][LOG];

// void dfs(int u, int p)
// {
//     depth[u] = depth[p] + 1;
//     // 节点 u 的父节点，根节点的父节点为 0。
//     up[u][0] = p;
//     for (int i = 1; i < LOG; i++)
//     {
//         up[u][i] = up[up[u][i - 1]][i - 1];
//     }
//     for (int v : g[u])
//     {
//         if (v != p)
//         {
//             dfs(v, u);
//         }
//     }
// }

// // 最近公共祖先（LCA）
// int lca(int u, int v)
// {
//     if (depth[u] < depth[v])
//     {
//         swap(u, v);
//     }

//     int dif = depth[u] - depth[v];
//     for (int i = 0; i < LOG; i++)
//     {
//         if (dif & (1 << i))
//         {
//             u = up[u][i];
//         }
//     }

//     if (u == v)
//     {
//         return u;
//     }

//     // 从大到小尝试，如果跳后祖先不同，则跳过去，最终两节点的父节点相同，即为 LCA
//     for (int i = LOG - 1; i >= 0; i--)
//     {
//         if (up[u][i] != up[v][i])
//         {
//             u = up[u][i];
//             v = up[v][i];
//         }
//     }
//     return up[u][0];
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m, s;
//         cin>>n>>m>>s;

//         for (int i = 0; i < n - 1; i++)
//         {
//             int u, v;
//             cin>>u>>v;

//             g[u].push_back(v);
//             g[v].push_back(u);
//         }

//         // 根节点深度设为 0
//         depth[s] = 0;
//         dfs(s, 0);

//         while (m--)
//         {
//             int a, b;
//             cin>>a>>b;

//             cout<<lca(a, b)<<endl;
//         } 
//     }

//     return 0;
// }