// 原始稿：02_模板/搜索与回溯/蓝桥题单/B3623.cpp
// 原文行号：1-53；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int n, k;
vector<int> ans;
vector<bool> vis;

void dfs(int pos)
{
    if (pos == k)
    {
        for (int i = 0; i < k; i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }

    // 枚举排列（递归实现排列型枚举）
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            ans.push_back(i);
            dfs(pos + 1);
            ans.pop_back();
            vis[i] = false;
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
        cin>>n>>k;
        vis.resize(n + 1, false);

        dfs(0);
    }

    return 0;
}
