// 原始稿：04_训练与工具/牛客新手130题/07/52.cpp
// 原文行号：86-146；恢复外层注释 1 层；保留方法内部注释。
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

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '*')
            {
                cout<<'*';
            }
            else
            {
                int cnt = 0;
                for (int k = 0; k < 8; k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (a[ni][nj] == '*')
                    {
                        cnt++;
                    } 
                }
                cout<<cnt;
            }
        }
        cout<<endl;
    }

    return 0;
}
