// 原始稿：04_训练与工具/牛客新手130题/06/35.cpp
// 原文行号：1-25；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int sum[110];

int main()
{
    int n;
    cin>>n;

    sum[1] = 1;
    for (int i =2; i <= n; i++)
    {
        sum[i] = sum[i - 1] + i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += sum[i];
    }
    cout<<ans;

    return 0;
}
