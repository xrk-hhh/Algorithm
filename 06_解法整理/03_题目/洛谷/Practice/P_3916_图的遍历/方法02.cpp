// 原始稿：03_题目/洛谷/Practice/P_3916_图的遍历.cpp
// 原文行号：64-130；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

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

        // 反向建图
        vector<vector<int>> rev(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin>>u>>v;

            rev[v].push_back(u);
        }

        // 各点能达到的最大点
        vector<int> ans(n + 1, 0);
        for (int i = n; i >= 1; i--)
        {
            if (ans[i])
            {
                continue;
            }

            // 模拟栈迭代
            stack<int> st;
            st.push(i);
            ans[i] = i;
            while (!st.empty())
            {
                int u = st.top();
                st.pop();

                for (int v : rev[u])
                {
                    if (!ans[v])
                    {
                        ans[v] = i;
                        st.push(v);
                    }
                }
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
