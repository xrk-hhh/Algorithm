// 原始稿：04_训练与工具/牛客新手130题/08/61.cpp
// 原文行号：1-32；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    string s;
    cin>>s;

    while (m--)
    {
        int l, r;
        cin>>l>>r;

        char c1, c2;
        cin>>c1>>c2;

        for (int i = l - 1; i < r; i++)
        {
            if (s[i] == c1)
            {
                s[i] = c2;
            }
        }
    }

    cout<<s;

    return 0;
}
