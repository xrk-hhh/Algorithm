// 原始稿：04_训练与工具/牛客新手130题/05/22.cpp
// 原文行号：1-19；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }

    return 0;
}
