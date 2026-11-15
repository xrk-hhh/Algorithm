// 原始稿：02_模板/基础专题/蓝桥题单/P1162.cpp
// 原文行号：1-96；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

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

        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>g[i][j];
            }
        }

        // 填涂颜色
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            if (g[i][0] == 0 && !vis[i][0])
            {
                vis[i][0] = true;
                q.push({i, 0});
            }
            if (g[i][n - 1] == 0 && !vis[i][n - 1])
            {
                vis[i][n - 1] = true;
                q.push({i, n - 1});
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (g[0][j] == 0 && !vis[0][j])
            {
                vis[0][j] = true;
                q.push({0, j});
            }
            if (g[n - 1][j] == 0 && !vis[n - 1][j])
            {
                vis[n - 1][j] = true;
                q.push({n - 1, j});
            }
        }

        while (!q.empty())
        {
            auto binding_value_01 = q.front();
            auto x = binding_value_01.first;
            auto y = binding_value_01.second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && g[nx][ny] == 0 && !vis[nx][ny])
                {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] == 0 && !vis[i][j])
                {
                    cout<<2<<' ';
                }
                else
                {
                    cout<<g[i][j]<<' ';
                }
            }
            cout<<endl;
        }
    }

    return 0;
}
