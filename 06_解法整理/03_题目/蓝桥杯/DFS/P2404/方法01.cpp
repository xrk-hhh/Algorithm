// 原始稿：03_题目/蓝桥杯/DFS/P2404.cpp
// 原文行号：1-54；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n;
vector<int> ans;

// last：当前可选的最小数字
// sum：当前选的数字之和
void dfs(int last, int sum)
{
    if (sum == n)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if (i != 0)
            {
                cout<<'+';
            }
            cout<<ans[i];
        }
        cout<<endl;
    }

    // 从可选最小数字开始，保证序列中数字升序
    // 同时限制 i 不超过剩余和，减少搜索量
    // 同时避免取到 n 本身
    for (int i = last; i <= n - sum && i < n; i++)
    {
        ans.push_back(i);
        dfs(i, sum + i);
        ans.pop_back();
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
        cin>>n;

        dfs(1, 0);
    }

    return 0;
}
