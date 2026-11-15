// 原始稿：04_训练与工具/牛客新手130题/05/27.cpp
// 原文行号：1-31；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;

    int maxx = a;
    int minn = a;
    if (maxx < b)
    {
        maxx = b;
    }
    if (maxx < c)
    {
        maxx = c;
    }
    if (minn > b)
    {
        minn = b;
    }
    if (minn > c)
    {
        minn = c;
    }

    cout<<"The maximum number is : "<<maxx<<endl;
    cout<<"The minimum number is : "<<minn;
    return 0;
}
