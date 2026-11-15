// 原始稿：03_题目/洛谷/Contest/44/F.cpp
// 原文行号：1-89；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, m, d;
        cin>>n>>m>>d;

        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin>>a[i][j];
            }
        }

        vector<pair<int, int>> idx;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
            {
                for (int j = 1; j <= m; j++)
                {
                    idx.emplace_back(i, j);
                }
            }
            else
            {
                for (int j = m; j >= 1; j--)
                {
                    idx.emplace_back(i, j);
                }
            }
        }

        int total = n * m;
        int pos = 0;
        int ans = 0;

        while (pos < total)
        {
            int cnt = min(d, total - pos);

            for (int i = 0; i < cnt; i++)
            {
                auto binding_value_01 = idx[pos + i];
                auto x = binding_value_01.first;
                auto y = binding_value_01.second;
                if (a[x][y] == 1)
                {
                    ans++;
                }
            }
            pos += cnt;

            if (pos == total)
            {
                break;
            }

            if (cnt == d)
            {
                auto binding_value_02 = idx[pos];
                auto nx = binding_value_02.first;
                auto ny = binding_value_02.second;
                if (a[nx][ny] == 0)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
