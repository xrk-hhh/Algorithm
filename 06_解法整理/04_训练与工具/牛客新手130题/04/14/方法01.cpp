// 原始稿：04_训练与工具/牛客新手130题/04/14.cpp
// 原文行号：1-17；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double xx1, yy1, xx2, yy2;
    cin>>xx1>>yy1>>xx2>>yy2;

    double dE = sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2));
    double dM = fabs(xx1 - xx2) + fabs(yy1 - yy2);

    double derta = fabs(dM - dE);

    cout<<fixed<<setprecision(10)<<derta;

    return 0;
}
