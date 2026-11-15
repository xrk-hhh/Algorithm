// 原始稿：04_训练与工具/牛客新手130题/06/32.cpp
// 原文行号：1-24；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((i & 1) == 0)
        {
            sum -= i;
        }
        else
        {
            sum += i;
        }
    }
    cout<<sum;

    return 0;
}
