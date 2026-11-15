// 原始稿：04_训练与工具/牛客新手130题/08/56.cpp
// 原文行号：1-30；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }

    for (int i = 0; i < len - 2; i++)
    {
        if (s[i] == 'b' && s[i + 1] == 'o' && s[i + 2] == 'b')
        {
            cout<<i;
            return 0;
        }
    }

    cout<<-1;

    return 0;
}
