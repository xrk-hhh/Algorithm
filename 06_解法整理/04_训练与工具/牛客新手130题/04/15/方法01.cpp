// 原始稿：04_训练与工具/牛客新手130题/04/15.cpp
// 原文行号：1-22；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;

    int ge, shi, bai, qian;
    ge = num % 10;
    num /= 10;
    shi = num % 10;
    num /= 10;
    bai = num % 10;
    num /= 10;
    qian = num % 10;

    int sum = ge + shi + bai + qian;
    cout<<sum;

    return 0;
}
