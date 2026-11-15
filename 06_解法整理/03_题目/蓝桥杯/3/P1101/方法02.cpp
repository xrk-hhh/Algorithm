// 原始稿：03_题目/蓝桥杯/3/P1101.cpp
// 原文行号：141-215；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

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
        int n;
        cin>>n;

        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        vector<string> b(n, string(n, '*'));

        string tar = "yizhong";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    bool ok = true;

                    // 检查从(i, j)开始沿方向 k 的 7 个字符是否与目标相同
                    for (int cnt = 0; cnt < 7; cnt++)
                    {
                        int nx = i + dx[k] * cnt;
                        int ny = j + dy[k] * cnt;

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != tar[cnt])
                        {
                            ok = false;
                            break;
                        }
                    }

                    if (ok)
                    {
                        // 将这些满足的更改成目标结果
                        for (int cnt = 0; cnt < 7; cnt++)
                        {
                            int nx = i + dx[k] * cnt;
                            int ny = j + dy[k] * cnt;
                            b[nx][ny] = tar[cnt];
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout<<b[i]<<endl;
        }
    }

    return 0;
}
