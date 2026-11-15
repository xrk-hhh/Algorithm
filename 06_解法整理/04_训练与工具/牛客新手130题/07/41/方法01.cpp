// 原始稿：04_训练与工具/牛客新手130题/07/41.cpp
// 原文行号：1-25；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int a[110];

int main()
{
    int k = 0;
    for (int i = 0;; i++)
    {
        cin>>a[i];
        if (a[i] == 0)
        {
            k = i;
            break;
        }
    }

    for (int i = k - 1; i >= 0; i--)
    {
        cout<<a[i]<<' ';
    }

    return 0;
}
