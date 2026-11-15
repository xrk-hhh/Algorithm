// 原始稿：04_训练与工具/牛客新手130题/07/39.cpp
// 原文行号：1-21；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int A[30];

int main()
{
    int n;
    cin>>n;

    A[1] = 0, A[2] = A[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        A[i] = A[i - 3] + 2 * A[i - 2] + A[i - 1];
    }

    cout<<A[n];

    return 0;
}
