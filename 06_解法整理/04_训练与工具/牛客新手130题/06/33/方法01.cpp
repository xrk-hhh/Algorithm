// 原始稿：04_训练与工具/牛客新手130题/06/33.cpp
// 原文行号：1-17；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    double sum = 0.0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1.0 / i; 
    }
    cout<<fixed<<setprecision(6)<<sum;

    return 0;
}
