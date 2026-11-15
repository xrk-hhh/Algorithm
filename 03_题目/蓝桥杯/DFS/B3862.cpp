// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// // 反向图
// vector<vector<int>> rev;
// vector<int> ans;

// void dfs(int u, int root)
// {
//     ans[u] = root;
//     for (int v : rev[u])
//     {
//         if (ans[v] == 0)
//         {
//             dfs(v, root);
//         }
//     }
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

//         rev.resize(n + 1);
//         ans.resize(n + 1, 0);

//         for (int i = 0; i < m; i++)
//         {
//             int u, v;
//             cin>>u>>v;
//             // 反向边
//             rev[v].push_back(u);
//         }

//         // // BFS解决
//         // for (int i = n; i >= 1; i--)
//         // {
//         //     if (ans[i] == 0)
//         //     {
//         //         queue<int> q;
//         //         q.push(i);
//         //         ans[i] = i;
//         //         while (!q.empty())
//         //         {
//         //             int u =q.front();
//         //             q.pop();

//         //             for (int v : rev[u])
//         //             {
//         //                 if (ans[v] == 0)
//         //                 {
//         //                     q.push(v);
//         //                 }
//         //             }
//         //         }
//         //     }
//         // }

//         // 从大到小遍历节点，用 DFS 标记所有能到达当前节点的点
//         for (int i = n; i >= 1; i--)
//         {
//             if (ans[i] == 0)
//             {
//                 dfs(i, i);
//             }
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             cout<<ans[i]<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }