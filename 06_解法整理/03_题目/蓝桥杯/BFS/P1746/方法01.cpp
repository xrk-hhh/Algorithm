// 原始稿：03_题目/蓝桥杯/BFS/P1746.cpp
// 原文行号：1-64；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// 方向数组
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

        vector<string> g(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>g[i];
        }

        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        // 基础求最短路径问题
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
        dist[x1][y1] = 0;
        q.push({x1, y1});
        // BFS
        while (!q.empty())
        {
            auto binding_value_01 = q.front();
            auto x = binding_value_01.first;
            auto y = binding_value_01.second;
            q.pop();
            if (x == x2 && y == y2)
            {
                break;
            }

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                // 注意读入的是字符串，下标是从 0 开始
                if (nx >= 1 && nx <= n && ny >= 1 && ny <=n && g[nx][ny - 1] == '0' && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        cout<<dist[x2][y2]<<endl;
    }

    return 0;
}
