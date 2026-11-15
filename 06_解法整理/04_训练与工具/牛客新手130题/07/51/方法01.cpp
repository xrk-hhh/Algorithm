// 原始稿：04_训练与工具/牛客新手130题/07/51.cpp
// 原文行号：1-35；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int a[40][40];

int main()
{
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
