// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

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

//         // 拓扑排序（Kahn 算法（基于入度））
//         // 有向无环图（DAG）
//         vector<vector<int>> g(n + 1);
//         // 统计每个点的入度
//         vector<int> indeg(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             int x;
//             while (cin>>x && x != 0)
//             {
//                 g[i].push_back(x);
//                 indeg[x]++;
//             }
//         }

//         // 将所有入度为 0 的节点加入队列（这些人是“祖先”，没有长辈）
//         queue<int> q;
//         for (int i = 1; i <= n; i++)
//         {
//             if (indeg[i] == 0)
//             {
//                 q.push(i);
//             }
//         }

//         // 不断从队列中取出节点，将其加入答案序列，并将其所有后继节点的入度减 1；
//         // 若某个后继节点入度变为 0，则将其加入队列。
//         vector<int> ans;
//         while (!q.empty())
//         {
//             int u = q.front();
//             q.pop();

//             ans.push_back(u);
//             for (int v : g[u])
//             {
//                 if (--indeg[v] == 0)
//                 {
//                     q.push(v);
//                 }
//             }
//         }

//         // if (ans.size() != n)
//         // {
//         //     // 存在环
//         // }

//         for (int i = 0; i < ans.size(); i++)
//         {
//             cout<<ans[i]<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }