// 原始稿：04_训练与工具/牛客新手130题/06/36.cpp
// 原文行号：1-22；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int fib[50];

int main()
{
    int n;
    cin>>n;

    fib[1] = 1;
    fib[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout<<fib[n];

    return 0;
}
