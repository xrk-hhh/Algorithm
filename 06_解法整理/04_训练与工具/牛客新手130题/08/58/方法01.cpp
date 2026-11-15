// 原始稿：04_训练与工具/牛客新手130题/08/58.cpp
// 原文行号：1-21；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    string s;
    s[0] = 0;
    int k = 1;
    for (int i = 1; s.size() <= n; i++)
    {
        s += to_string(i);
    }

    cout<<s[n - 1];

    return 0;
}
