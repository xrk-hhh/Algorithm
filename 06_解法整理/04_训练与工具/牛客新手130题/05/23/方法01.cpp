// 原始稿：04_训练与工具/牛客新手130题/05/23.cpp
// 原文行号：1-23；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;

    if (a == b)
    {
        cout<<'=';
    }
    else if (a > b)
    {
        cout<<'>';
    }
    else
    {
        cout<<'<';
    }

    return 0;
}
