// 原始稿：04_训练与工具/牛客新手130题/06/37.cpp
// 原文行号：1-24；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    if (n < 0)
    {
        n = -n;
    }
    
    int sum = 0;
    while (n != 0)
    {
        int tmp = n % 10;
        sum += tmp;
        n /= 10;
    }
    cout<<sum;

    return 0;
}
