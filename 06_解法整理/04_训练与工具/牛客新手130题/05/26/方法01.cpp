// 原始稿：04_训练与工具/牛客新手130题/05/26.cpp
// 原文行号：1-20；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    cin>>A>>B>>C;

    double avg = (A + B + C) / 3.0;
    if (avg >= 60)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }

    return 0;
}
