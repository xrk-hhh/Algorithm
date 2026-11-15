// 原始稿：04_训练与工具/牛客新手130题/06/34.cpp
// 原文行号：1-28；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int maxx = -100001, minn = 100001;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        if (a > maxx)
        {
            maxx = a;
        }
        if (a < minn)
        {
            minn = a;
        }
    }

    int ans = maxx - minn;
    cout<<ans;

    return 0;
}
