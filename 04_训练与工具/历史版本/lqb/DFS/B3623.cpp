#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n, k;
vector<int> ans;
vector<bool> vis;

// 排列型枚举

// 枚举位置
void dfs(int pos)
{
    // 达到 第 k-1 个，输出答案
    if (pos == k)
    {
        for (int i = 0; i < k; i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        // 没有枚举过
        if (!vis[i])
        {
            // 选
            ans.push_back(i);
            vis[i] = true;
            dfs(pos + 1);
            // 不选
            vis[i] = false;
            ans.pop_back();
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
        // 初始化
        vis.assign(n + 1, false);
        dfs(0);
    }

    return 0;
}