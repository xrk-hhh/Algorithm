// 原始稿：03_题目/蓝桥杯/BFS/P1596.cpp
// 原文行号：1-68；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// 八连通块
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

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

        vector<string> g(n);
        for (int i = 0; i < n; i++)
        {
            cin>>g[i];
        }

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        // 对每个位置遍历
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == 'W' && !vis[i][j])
                {
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    while (!q.empty())
                    {
                        auto binding_value_01 = q.front();
                        auto x = binding_value_01.first;
                        auto y = binding_value_01.second;
                        q.pop();

                        // 八连通块遍历
                        for (int k = 0; k < 8; k++)
                        {
                            int nx = x + dx[k], ny = y + dy[k];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 'W' && !vis[nx][ny])
                            {
                                vis[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                
            }
        }
        
        cout<<ans<<endl;
    }

    return 0;
}
