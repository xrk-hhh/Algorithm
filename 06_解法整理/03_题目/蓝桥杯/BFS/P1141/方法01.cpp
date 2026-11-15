// 原始稿：03_题目/蓝桥杯/BFS/P1141.cpp
// 原文行号：1-83；恢复外层注释 2 层；保留方法内部注释。
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
        int n, m;
        cin>>n>>m;

        vector<string> g(n);
        for (int i = 0; i < n; i++)
        {
            cin>>g[i];
        }

        vector<vector<int>> comp(n, vector<int>(n, -1));
        vector<int> sz;
        int cur = 0;
        // 预处理每个连通块大小
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (comp[i][j] != -1)
                {
                    continue;
                }

                queue<pair<int, int>> q;
                comp[i][j] = cur;
                q.push({i, j});
                int cnt = 0;
                // BFS遍历标记所有连通块
                while (!q.empty())
                {
                    auto binding_value_01 = q.front();
                    auto x = binding_value_01.first;
                    auto y = binding_value_01.second;
                    q.pop();

                    cnt++;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && comp[nx][ny] == -1 && g[nx][ny] != g[x][y])
                        {
                            comp[nx][ny] = cur;
                            q.push({nx, ny});
                        }
                    }
                }

                sz.push_back(cnt);
                cur++;
            }
        }

        while (m--)
        {
            int i, j;
            cin>>i>>j;

            i--;
            j--;

            cout<<sz[comp[i][j]]<<endl;            
        }
    }

    return 0;
}
