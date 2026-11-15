// 原始稿：04_训练与工具/牛客新手130题/07/52.cpp
// 原文行号：1-85；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

char a[1010][1010];

int main()
{
    int n, m;
    cin>>n>>m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
        }
    }

    for (int i = 0; i <= n + 1; i++)
    {
        a[i][0] = '.';
        a[i][m + 1] = '.';
    }
    for (int j = 0; j <= m + 1; j++)
    {
        a[0][j] = '.';
        a[n + 1][j] = '.';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '.')
            {
                int cnt = 0;
                if (a[i - 1][j - 1] == '*')
                {
                    cnt++;
                }
                if (a[i - 1][j] == '*')
                {
                    cnt++;
                }
                if (a[i - 1][j + 1] == '*')
                {
                    cnt++;
                }
                if (a[i][j - 1] == '*')
                {
                    cnt++;
                }
                if (a[i][j + 1] == '*')
                {
                    cnt++;
                }
                if (a[i + 1][j - 1] == '*')
                {
                    cnt++;
                }
                if (a[i + 1][j] == '*')
                {
                    cnt++;
                }
                if (a[i + 1][j + 1] == '*')
                {
                    cnt++;
                }
                a[i][j] = cnt + '0';
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }

    return 0;
}
