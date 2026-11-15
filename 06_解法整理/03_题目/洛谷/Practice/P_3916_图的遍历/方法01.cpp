// 原始稿：03_题目/洛谷/Practice/P_3916_图的遍历.cpp
// 原文行号：1-63；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

vector<vector<int>> rev;
vector<int> ans;

// DFS递归
void dfs(int u, int root)
{
    ans[u] = root;
    for (int v : rev[u])
    {
        if (ans[v] == 0)
        {
            dfs(v, root);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        rev.resize(n + 1);
        ans.resize(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin>>u>>v;

            rev[v].push_back(u);
        }

        for (int i = n; i >= 1; i--)
        {
            if (ans[i] == 0)
            {
                dfs(i, i);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
