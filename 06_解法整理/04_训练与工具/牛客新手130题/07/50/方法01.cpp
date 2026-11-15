// 原始稿：04_训练与工具/牛客新手130题/07/50.cpp
// 原文行号：1-38；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int a[15][15];
int b[15][15];

int main()
{
    int n, m;
    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[j][i];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
