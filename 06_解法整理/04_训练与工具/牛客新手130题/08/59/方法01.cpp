// 原始稿：04_训练与工具/牛客新手130题/08/59.cpp
// 原文行号：1-22；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1)
    {
        string s;
        if (!(cin>>s))
        {
            break;
        }
        char c = s[0];
        if (c >= 'a' && c <= 'z')
        {
            c = c - 'a' + 'A';
        }
        cout<<c;
    }

    return 0;
}
