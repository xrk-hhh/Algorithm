// 原始稿：04_训练与工具/牛客新手130题/04/18.cpp
// 原文行号：1-15；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;

    int S = 2 * (a * b + a * c + b * c);
    int V = a * b * c;

    cout<<S<<endl<<V;

    return 0;
}
