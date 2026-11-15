// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;

// vector<pair<int, int>> g[N];
// int xr[N];

// // 异或前缀计算
// void dfs(int u, int fa)
// {
//     for (auto [v, w] : g[u])
//     {
//         if (v == fa)
//         {
//             continue;
//         }

//         xr[v] = xr[u] ^ w;
//         dfs(v, u);
//     }
// }

// // 0-1 Trie
// struct Trie
// {
//     // ch[p][0/1] 表示节点 p 的左/右子节点索引（0 表示不存在）
//     int ch[N * 31][2];
//     // 当前使用节点数
//     int idx = 0;

//     // 插入
//     void insert(int x)
//     {
//         int p = 0;
//         // 从根节点 0 开始，逐位取出 x 的二进制位（从最高位 30 到最低位 0）
//         for (int i = 30; i >= 0; i--)
//         {
//             int b = (x >> i) & 1;
//             // 如果该位对应的子节点不存在就新建一个节点
//             if (!ch[p][b])
//             {
//                 ch[p][b] = ++idx;
//             }

//             // 最后 p 停留在叶节点（实际不需要额外标记，因为只查找路径）
//             p = ch[p][b];
//         }
//     }

//     // 查询最大异或值
//     int query(int x)
//     {
//         int p = 0, res = 0;
//         for (int i = 30; i >= 0; i--)
//         {
//             int b = (x >> i) & 1;
//             // 存在相反位
//             if (ch[p][b ^ 1])
//             {
//                 // 该位异或结果为 1，累加到答案
//                 res |= (1 << i);
//                 p = ch[p][b ^ 1];
//             }
//             // 否则只能走相同位，该位结果为 0
//             else
//             {
//                 p = ch[p][b];
//             }
//         }
//         return res;
//     }
// } trie;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         for (int i = 0; i < n - 1; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             g[u].push_back({v, w});
//             g[v].push_back({u, w});
//         }

//         dfs(1, 0);
//         int ans = 0;
//         // 先插入第一个节点的前缀值
//         trie.insert(xr[1]);
//         for (int i = 2; i <= n; i++)
//         {
//             // 和已有节点配对
//             ans = max(ans, trie.query(xr[i]));
//             // 再插入自己，供后面节点查询
//             trie.insert(xr[i]);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }