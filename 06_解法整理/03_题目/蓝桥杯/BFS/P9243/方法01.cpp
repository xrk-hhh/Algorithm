// 原始稿：03_题目/蓝桥杯/BFS/P9243.cpp
// 原文行号：1-142；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// 八连通
const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// 四连通
const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        vector<string> g(n);
        for (int i = 0; i < n; i++)
        {
            cin>>g[i];
        }

        // 扩展边界（周围加 '0'）
        int N = n + 2, M = m + 2;
        vector<string> ng(N, string(M, '0'));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ng[i][j] = g[i - 1][j - 1];
            }
        }

        // 外部海水标记（八连通）
        vector<vector<bool>> out(N, vector<bool>(M, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++)
        {
            if (ng[i][0] == '0')
            {
                out[i][0] = true;
                q.push({i, 0});
            }

            if (ng[i][M - 1] == '0')
            {
                out[i][M - 1] = true;
                q.push({i, M - 1});
            }
        }
        for (int j = 0; j < M; j++)
        {
            if (ng[0][j] == '0')
            {
                out[0][j] = true;
                q.push({0, j});
            }

            if (ng[N - 1][j] == '0')
            {
                out[N - 1][j] = true;
                q.push({N - 1, j});
            }
        }

        while (!q.empty())
        {
            auto binding_value_01 = q.front();
            auto x = binding_value_01.first;
            auto y = binding_value_01.second;
            q.pop();

            for (int k = 0; k < 8; k++)
            {
                int nx = x + dx8[k], ny = y + dy8[k];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && ng[nx][ny] == '0' && !out[nx][ny])
                {
                    out[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // 统计岛屿（四连通）
        vector<vector<bool>> vis(N, vector<bool>(M, false));
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (ng[i][j] == '1' && !vis[i][j])
                {
                    // 是否接触到外部海水
                    bool ok = false;
                    queue<pair<int, int>> qq;
                    qq.push({i, j});
                    vis[i][j] = true;
                    while (!qq.empty())
                    {
                        auto binding_value_02 = qq.front();
                        auto x = binding_value_02.first;
                        auto y = binding_value_02.second;
                        qq.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + dx4[k], ny = y + dy4[k];
                            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                            {
                                if (ng[nx][ny] == '0' && out[nx][ny])
                                {
                                    ok = true;
                                }

                                if (ng[nx][ny] == '1' && !vis[nx][ny])
                                {
                                    vis[nx][ny] = true;
                                    qq.push({nx, ny});
                                }
                            }
                        }
                    }

                    if (ok)
                    {
                        ans++;
                    }
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
