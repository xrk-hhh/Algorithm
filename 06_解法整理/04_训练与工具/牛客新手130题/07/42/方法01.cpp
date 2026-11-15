// 原始稿：04_训练与工具/牛客新手130题/07/42.cpp
// 原文行号：1-30；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int a[110];

int main()
{
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j <= i; j++)
        {
            if (a[j] < a[i])
            {
                k++;
            }
        }
        cout<<k<<' ';
    }

    return 0;
}
