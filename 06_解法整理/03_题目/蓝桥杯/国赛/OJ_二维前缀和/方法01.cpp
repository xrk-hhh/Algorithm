// 原始稿：03_题目/蓝桥杯/国赛/OJ_二维前缀和.cpp
// 原文行号：1-49；恢复外层注释 1 层；保留方法内部注释。
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
        int n, m, q;
        cin>>n>>m>>q;

        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for (int i = 1 ;i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin>>a[i][j];
            }
        }

        // 经典二维前缀和
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1]  - pre[i - 1][j - 1] + a[i][j];
            }
        }

        while (q--)
        {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;

            cout<<pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1]<<endl;
        }
    }

    return 0;
}
