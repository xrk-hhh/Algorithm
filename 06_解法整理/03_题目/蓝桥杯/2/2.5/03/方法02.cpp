// 原始稿：03_题目/蓝桥杯/2/2.5/03.cpp
// 原文行号：95-183；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int dx[] = {-1, 0, 0, 0, 1};
int dy[] = {0, -1, 0, 1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n = 3;
        // 初始位掩码
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin>>x;

                if (x == 1)
                {
                    // 按位或| 初始化
                    start |= (1 << (i * n + j));
                }
            }
        }

        // 目标掩码
        int target = (1 << (n * n)) - 1;
        // 初始化距离为-1
        vector<int> dist((1 << (n * n)), -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);

        // BFS 求最短路径
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            // 达到目标则输出
            if (cur == target)
            {
                cout<<dist[cur]<<endl;
                return 0;
            }

            // 枚举按钮位置
            for (int pos = 0; pos < (n * n); pos++)
            {
                int x = pos / n;
                int y = pos % n;

                int nxt = cur;
                for (int k = 0; k < 5; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                    {
                        // 0/1 转置
                        int bit = nx * n + ny;
                        nxt ^= (1 << bit);
                    }
                }

                // -1 表示未试过
                if (dist[nxt] == -1)
                {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
    }

    return 0;
}
