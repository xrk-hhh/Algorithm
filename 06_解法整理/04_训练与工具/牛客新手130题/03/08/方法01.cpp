// 原始稿：04_训练与工具/牛客新手130题/03/08.cpp
// 原文行号：1-14；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;

    int ans1 = a / b;
    int ans2 = a % b;

    cout<<ans1<<" "<<ans2;
    return 0;
}
