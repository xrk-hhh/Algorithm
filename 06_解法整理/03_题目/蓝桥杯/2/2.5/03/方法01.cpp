// 原始稿：03_题目/蓝桥杯/2/2.5/03.cpp
// 原文行号：1-94；恢复外层注释 2 层；保留方法内部注释。
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
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>g[i][j];
            }
        }

        // 9个灯，即9个按钮，每个按钮按偶数次相当于没按，故只需考虑按 0/1 次
        // 转化为 按/不按 问题
        // 可使用 位掩码 解决

        // 最多按9个按钮，故设初始最大值为10
        int ans = 10;
        for (int mask = 0; mask < (1 << (n * n)); mask++)
        {
            vector<vector<int>> cur(n, vector<int>(n));
            cur = g;

            // 掩码中 1 的个数，即操作次数
            int steps = __builtin_popcount(mask);
            // 只处理需要操作次数更少的
            if (steps >= ans)
            {
                continue;
            }

            // 枚举
            for (int i = 0;  i < (n * n); i++)
            {
                if ((mask >> i) & 1)
                {
                    // 一维转二维
                    int x = i / n;
                    int y = i % n;

                    for (int k = 0; k < 5; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                        {
                            // 0/1 转置 相当于 异或(xor) ^1
                            cur[nx][ny] ^= 1;
                        }
                    }
                }
            }

            // 判断是否达到目标状态（全1）
            bool ok = true;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (cur[i][j] != 1)
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok)
            {
                ans = steps;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
