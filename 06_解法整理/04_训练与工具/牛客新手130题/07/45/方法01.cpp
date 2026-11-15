// 原始稿：04_训练与工具/牛客新手130题/07/45.cpp
// 原文行号：1-25；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        while (num)
        {
            if (num % 10 == x)
            {
                cnt++;
            }
            num /= 10;
        }
    }
    cout<<cnt;

    return 0;
}
