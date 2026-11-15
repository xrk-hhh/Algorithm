// 原始稿：04_训练与工具/牛客新手130题/04/13.cpp
// 原文行号：1-15；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double K;
    cin>>K;

    double C = K - 273.15;
    double F = C * 1.8 + 32;

    cout<<fixed<<setprecision(3)<<F;

    return 0;
}
