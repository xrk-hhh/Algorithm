// 原始稿：04_训练与工具/牛客新手130题/08/55.cpp
// 原文行号：1-21；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int len = s.size();

    for (int i = 0; i < len; i++)
    {
        cout<<s[i];
        if ((len - i - 1) % 3 == 0 && i != len - 1)
        {
           cout<<',';
        }
    }

    return 0;
}
