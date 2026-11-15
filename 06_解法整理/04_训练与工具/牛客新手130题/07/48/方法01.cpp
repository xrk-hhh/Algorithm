// 原始稿：04_训练与工具/牛客新手130题/07/48.cpp
// 原文行号：1-23；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin>>a;
            sum += a;
        }
    }

    cout<<sum;

    return 0;
}
