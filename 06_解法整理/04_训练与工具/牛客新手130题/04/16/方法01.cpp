// 原始稿：04_训练与工具/牛客新手130题/04/16.cpp
// 原文行号：1-17；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int seconds;
    cin>>seconds;

    int h, m, s;
    h = seconds / 3600;
    m = seconds % 3600 / 60;
    s = seconds % 3600 % 60;

    cout<<h<<' '<<m<<' '<<s;

    return  0;
}
