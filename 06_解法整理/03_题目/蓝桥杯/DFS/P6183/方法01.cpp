// 原始稿：03_题目/蓝桥杯/DFS/P6183.cpp
// 原文行号：1-94；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n;
vector<int> path;
vector<bool> vis;
bool ok = false;

// DFS深搜，但搜索空间太大

void dfs(int cur, int cnt)
{
    // 所有状态都访问了
    if (cnt == (1 << n))
    {
        // 当前状态与起点相比只有 1 位不同，即找到答案
        if (__builtin_popcount(cur ^ 0) == 1)
        {
            ok = true;
        }
        return;
    }

    // 尝试翻转每一位
    for (int i = 0; i < n; i++)
    {
        // 翻转第 i 位
        int nxt = cur ^ (1 << i);
        if (!vis[nxt])
        {
            vis[nxt] = true;
            path.push_back(nxt);
            dfs(nxt, cnt + 1);
            // 找到解立刻返回
            if (ok)
            {
                return;
            }
            vis[nxt] = false;
            path.pop_back();
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
        cin>>n;

        vis.assign((1 << n), false);
        vis[0] = true;
        path.push_back(0);
        // 从起点开始，全 O
        dfs(0, 1);

        if (ok)
        {
            for (int state : path)
            {
                for (int i = 0; i < n; i++)
                {
                    if ((state >> i) & 1)
                    {
                        cout<<'X';
                    }
                    else
                    {
                        cout<<"O";
                    }
                }
                cout<<endl;
            }

            for (int i = 0; i < n; i++)
            {
                cout<<'O';
            }
            cout<<endl;
        }
    }

    return 0;
}
