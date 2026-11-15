// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n;
// vector<vector<int>> g;
// vector<int> bfs(int start)
// {
//     vector<int> dist(n + 1, -1);
//     queue<int> q;
//     dist[start] = 0;
//     q.push(start);
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         for (int v : g[u])
//         {
//             if (dist[v] == - 1)
//             {
//                 dist[v] = dist[u] + 1;
//                 q.push(v);
//             }
//         }
//     }
//     return dist;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n;
//         g.resize(n + 1);
//         for (int i = 0; i < n - 1; i++)
//         {
//             int u, v;
//             cin>>u>>v;

//             g[u].push_back(v);
//             g[v].push_back(u);
//         }

//         // 两次BFS，先找到离随便一个点最远的点
//         auto dist1 = bfs(1);
//         int maxx = 0, idx = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             if (dist1[i] != -1)
//             {
//                 if (dist1[i] > maxx)
//                 {
//                     maxx = dist1[i];
//                     idx = i;
//                 }
//             }
//         }

//         // 再找到距离这个点最远的点
//         auto dist2 = bfs(idx);
//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             if (dist2[i] != -1)
//             {
//                 ans = max(ans, dist2[i]);
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

vector<vector<int>> g;
int ans = 0;

int dfs(int u, int fa)
{
    // 最大深度，次大深度
    int max1 = 0, max2 = 0;
    // 遍历子节点
    for (int v : g[u])
    {
        if (v == fa)
        {
            continue;
        }

        // 边权为 1
        int d = dfs(v, u) + 1;
        if (d > max1)
        {
            max2 = max1;
            max1 = d;
        }
        else if (d > max2)
        {
            max2 = d;
        }
    }

    // 从 u 的一个子节点的最深叶子到另一个子节点的最深叶子
    ans = max(ans, max1 + max2);
    return max1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n;
        cin>>n;
        g.resize(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin>>u>>v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        // 树形 DP:一次 DFS 遍历树
        // 对于每个节点，计算其向下延伸到叶子的最长路径（即“深度”），
        // 并记录经过该节点的最长路径（即该节点两个最深的子节点路径之和）

        // 任选一个点为根
        dfs(1, 0);

        cout<<ans<<endl;
    }

    return 0;
}