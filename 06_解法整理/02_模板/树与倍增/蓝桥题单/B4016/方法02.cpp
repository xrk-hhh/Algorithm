// 原始稿：02_模板/树与倍增/蓝桥题单/B4016.cpp
// 原文行号：86-158；恢复外层注释 0 层；保留方法内部注释。
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
