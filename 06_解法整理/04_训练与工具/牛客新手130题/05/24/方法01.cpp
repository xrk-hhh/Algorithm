// 原始稿：04_训练与工具/牛客新手130题/05/24.cpp
// 原文行号：1-21；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int ans;
    if ((n & 1) == 1)
    {
        ans = 3 * n + 1;
    }
    else
    {
        ans = n / 2;
    }
    cout<<ans;

    return 0;
}
