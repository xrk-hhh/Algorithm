// 原始稿：04_训练与工具/牛客新手130题/07/49.CPP
// 原文行号：1-34；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int a[15][15];

int main()
{
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            cin>>a[i][j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i][j] != 0)
            {
                cout<<"NO";
                return 0;
            }
        }
    }

    cout<<"YES";

    return 0;
}
